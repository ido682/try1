#pragma once

#include <map>

#include "common.h"


class NamesHolder
{
private:
    typedef std::map<name_t, users_ordered_cont_t> names_and_uids_map_t;
    const int EXACT_SEARCH_LIMIT = 3;

public:
    NamesHolder() = default;
    ~NamesHolder() = default;
    NamesHolder(const NamesHolder& other) = delete;
    NamesHolder& operator=(const NamesHolder& other) = delete;

    void AddUser(const name_t& name, user_uid_t user);
    void AddUsersWithGivenNameToExternalCont(const name_t& name,
                                             users_ordered_cont_t& ext_users_cont);

private:
    names_and_uids_map_t m_names_and_uids;

    void add_users_with_exact_name_match_to_external_cont(const name_t& name,
                                                          users_ordered_cont_t& ext_users_cont);
    void add_users_with_partial_name_match_to_external_cont(const name_t& name,
                                                            users_ordered_cont_t& ext_users_cont);
}; //NamesHolder