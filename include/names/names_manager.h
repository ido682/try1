#pragma once

#include <map>

#include "common.h"
#include "names/uuids_mapper.h"


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
    users_ordered_cont_t GetUsersByName(const std::string& name);

private:
    UUIDsMapper m_first_names;
    UUIDsMapper m_last_names;
}; //NamesManager