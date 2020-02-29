#pragma once

#include <string>
#include <map>
#include <vector>

#include "common.h"
#include "users/user.h"
#include "names/names_manager.h"
#include "date_of_birth/dobs_manager.h"


class UsersManager
{
private:
    static size_t m_s_counter;

public:
    UsersManager() = default;
    ~UsersManager() = default;
    UsersManager(const UsersManager& other) = delete;
	UsersManager& operator=(const UsersManager& other) = delete;

    user_uid_t AddUser(const user_t& user);
    users_ordered_cont_t GetUsersByAttribute(search_attr_t attribute, const std::string& value);

private:
    // LongIDsManager m_long_ids_manager;
    NamesManager m_names_manager;
    DOBsManager m_dobs_manager;

}; //UsersManager


