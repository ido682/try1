#pragma once

#include <map>

#include "common.h"
#include "names/names_holder.h"


class NamesManager
{
public:
    NamesManager() = default;
    ~NamesManager() = default;
    NamesManager(const NamesManager& other) = delete;
    NamesManager& operator=(const NamesManager& other) = delete;

    void AddUser(full_name_t full_name, user_uid_t user);
    users_ordered_cont_t GetUsersByName(const std::string& name);

private:
    NamesHolder m_first_names;
    NamesHolder m_last_names;
}; //NamesManager