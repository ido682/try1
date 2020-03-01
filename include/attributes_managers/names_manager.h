#pragma once

#include <map>

#include "common/common.h"
#include "attributes_managers/uuids_mapper.h"


class NamesManager
{
private:
    const int PARTIAL_MATCH_MIN_SIZE = 3;
    
public:
    NamesManager() = default;
    ~NamesManager() = default;
    NamesManager(const NamesManager& other) = delete;
    NamesManager& operator=(const NamesManager& other) = delete;

    void AddUser(full_name_t full_name, user_uid_t user);
    users_ordered_cont_t GetUsersByName(const name_t& name);
    void DeleteUser(full_name_t full_name, user_uid_t uuid);

private:
    UUIDsMapper m_first_names;
    UUIDsMapper m_last_names;

    users_ordered_cont_t get_users_by_name_with_one_word(const name_t& name);
    users_ordered_cont_t get_users_by_name_with_two_words(const name_t& name);

}; //NamesManager