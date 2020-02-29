#include <iostream>
#include "names/uuids_mapper.h"
#include "container/cont_funcs.h"
#include "users/parser.h"


void UUIDsMapper::AddUser(std::string key, user_uid_t user)
{    
    std::string lowered_key = Parser::ToLower(key);
    
    auto key_iter = m_keys_and_uids.find(key);
    if (key_iter == m_keys_and_uids.end())
    {
        m_keys_and_uids.insert({key, users_ordered_cont_t()});
    }

    m_keys_and_uids[lowered_key].insert(user);
}

void UUIDsMapper::add_users_with_exact_key_match_to_external_cont(const std::string& key,
                                                                   users_ordered_cont_t& ext_users_cont)
{
    auto key_iter = m_keys_and_uids.find(key);
    if (key_iter == m_keys_and_uids.end())
    {
        return;
    }

    for (const auto& user : key_iter->second)
    {
        ext_users_cont.insert(user);
    }
}

void UUIDsMapper::add_users_with_partial_key_match_to_external_cont(const std::string& key,
                                                                    users_ordered_cont_t& ext_users_cont)
{
    const user_uid_t DUMMY_USER = 0;
    size_t key_length = key.length();
    bool is_dummy_user_inserted = false;
    
    auto key_iter = m_keys_and_uids.find(key);
    if (key_iter == m_keys_and_uids.end())
    {
        AddUser(key, DUMMY_USER);
        is_dummy_user_inserted = true;
        key_iter = m_keys_and_uids.find(key);
    }
    else
    {
        ContFuncs::AddUsersInContToExternalCont(key_iter->second, ext_users_cont);
    }
    
    key_iter++;

    for (; (key_iter != m_keys_and_uids.end()) && (key_iter->first.compare(0, key_length, key) == 0); ++key_iter)
    {
        ContFuncs::AddUsersInContToExternalCont(key_iter->second, ext_users_cont);
    }

    key_iter = m_keys_and_uids.find(key);
    bool is_iter_in_beginning_in_prev_loop = (key_iter == m_keys_and_uids.begin());
    --key_iter;

    for (; (!is_iter_in_beginning_in_prev_loop) && (key_iter->first.compare(0, key_length, key) == 0); --key_iter)
    {
        ContFuncs::AddUsersInContToExternalCont(key_iter->second, ext_users_cont);

        is_iter_in_beginning_in_prev_loop = (key_iter == m_keys_and_uids.begin());
    }
    
    if (is_dummy_user_inserted)
    {
        m_keys_and_uids.erase(key);
    }
}

void UUIDsMapper::AddUsersWithGivenKeyToExternalCont(const std::string& key,
                                                     users_ordered_cont_t& ext_users_cont,
                                                     int partial_match_min_size)
{
    std::string lowered_key = Parser::ToLower(key);
    size_t key_length = lowered_key.length();

    if ((partial_match_min_size != 0) && (key_length >= partial_match_min_size))
    {
        add_users_with_partial_key_match_to_external_cont(lowered_key, ext_users_cont);
    }
    else
    {
        add_users_with_exact_key_match_to_external_cont(lowered_key, ext_users_cont);
    }
}

