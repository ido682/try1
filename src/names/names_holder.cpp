#include <iostream>
#include "names/names_holder.h"
#include "container/cont_funcs.h"
#include "users/parser.h"


void NamesHolder::AddUser(const name_t& name, user_uid_t user)
{
    std::cout<<"RRR in NamesHolder::AddUser 1"<<std::endl;
    
    name_t lowered_name = Parser::ToLower(name);

    std::cout<<"RRR in NamesHolder::AddUser 2"<<std::endl;
    
    auto name_iter = m_names_and_uids.find(lowered_name);
    std::cout<<"RRR in NamesHolder::AddUser 3"<<std::endl;
    if (name_iter == m_names_and_uids.end())
    {
        m_names_and_uids[lowered_name] = users_ordered_cont_t();
    }
    std::cout<<"RRR in NamesHolder::AddUser 4"<<std::endl;

    m_names_and_uids[lowered_name].insert(user);
    std::cout<<"RRR in NamesHolder::AddUser 5"<<std::endl;
}

void NamesHolder::add_users_with_exact_name_match_to_external_cont(const name_t& name,
                                                                   users_ordered_cont_t ext_users_cont)
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
                                                                     users_ordered_cont_t ext_users_cont)
{
    const user_uid_t DUMMY_USER = 0;
    size_t name_length = name.length();
    bool is_dummy_user_inserted = false;
    
    auto found_iter = m_names_and_uids.find(name);
    if (found_iter == m_names_and_uids.end())
    {
        AddUser(name, DUMMY_USER);
        is_dummy_user_inserted = true;
        found_iter = m_names_and_uids.find(name);
    }

    names_and_uids_map_t::iterator name_iter = found_iter;
    if (is_dummy_user_inserted)
    {
        ++name_iter;
    }

    for (; name_iter->first.compare(0, name_length, name) == 0; ++name_iter)
    {
        ContFuncs::AddUsersInContToExternalCont(name_iter->second, ext_users_cont);
    }

    name_iter = found_iter;
    --name_iter;
    for (; name_iter->first.compare(0, name_length, name) == 0; --name_iter)
    {
        ContFuncs::AddUsersInContToExternalCont(name_iter->second, ext_users_cont);
    }

    if (is_dummy_user_inserted)
    {
        m_names_and_uids.erase(name);
    }
}

void NamesHolder::AddUsersWithGivenNameToExternalCont(const name_t& name,
                                                      users_ordered_cont_t ext_users_cont)
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

