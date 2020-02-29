#include <iostream>
#include "names/names_holder.h"
#include "container/cont_funcs.h"
#include "users/parser.h"


void NamesHolder::AddUser(const name_t& name, user_uid_t user)
{    
    name_t lowered_name = Parser::ToLower(name);
    
    auto name_iter = m_names_and_uids.find(lowered_name);
    if (name_iter == m_names_and_uids.end())
    {
        m_names_and_uids.insert({lowered_name, users_ordered_cont_t()});
    }

    m_names_and_uids[lowered_name].insert(user);
}

void NamesHolder::add_users_with_exact_name_match_to_external_cont(const name_t& name,
                                                                   users_ordered_cont_t& ext_users_cont)
{
    auto name_iter = m_names_and_uids.find(name);
    if (name_iter == m_names_and_uids.end())
    {
        return;
    }

    for (const auto& user : name_iter->second)
    {
        ext_users_cont.insert(user);
    }
}

void NamesHolder::add_users_with_partial_name_match_to_external_cont(const name_t& name,
                                                                     users_ordered_cont_t& ext_users_cont)
{
    const user_uid_t DUMMY_USER = 0;
    size_t name_length = name.length();
    bool is_dummy_user_inserted = false;
    
    auto name_iter = m_names_and_uids.find(name);
    if (name_iter == m_names_and_uids.end())
    {
        AddUser(name, DUMMY_USER);
        is_dummy_user_inserted = true;
        name_iter = m_names_and_uids.find(name);
    }
    else
    {
        ContFuncs::AddUsersInContToExternalCont(name_iter->second, ext_users_cont);
    }
    
    name_iter++;

    std::cout<<"^^^^^^^ here 1"<<std::endl;
    for (; (name_iter != m_names_and_uids.end()) && (name_iter->first.compare(0, name_length, name) == 0); ++name_iter)
    {
        std::cout<<"^^^^^^^ here 2 for loop"<<std::endl;
        ContFuncs::AddUsersInContToExternalCont(name_iter->second, ext_users_cont);
    }

    name_iter = m_names_and_uids.find(name);
    bool is_iter_in_beginning_in_prev_loop = (name_iter == m_names_and_uids.begin());
    --name_iter;

    for (; (!is_iter_in_beginning_in_prev_loop) && (name_iter->first.compare(0, name_length, name) == 0); --name_iter)
    {
        ContFuncs::AddUsersInContToExternalCont(name_iter->second, ext_users_cont);

        is_iter_in_beginning_in_prev_loop = (name_iter == m_names_and_uids.begin());
    }
    
    if (is_dummy_user_inserted)
    {
        m_names_and_uids.erase(name);
    }
}

void NamesHolder::AddUsersWithGivenNameToExternalCont(const name_t& name,
                                                      users_ordered_cont_t& ext_users_cont)
{
    name_t lowered_name = Parser::ToLower(name);
    size_t name_length = lowered_name.length();

    if (name_length < EXACT_SEARCH_LIMIT)
    {
        add_users_with_exact_name_match_to_external_cont(lowered_name, ext_users_cont);
    }
    else
    {
        add_users_with_partial_name_match_to_external_cont(lowered_name, ext_users_cont);
    }
}

