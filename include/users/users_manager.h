#pragma once

#include <string>
#include <map>
#include <vector>
#include "common.h"
#include "users/user.h"


class UsersManager
{
private:
    static size_t m_s_counter;

public:
    typedef enum
    {
        ID,
        NAME,
        AGE
    } search_attr_t;

    UsersManager() = default;
    ~UsersManager() = default;
    UsersManager(const UsersManager& other) = delete;
	UsersManager& operator=(const UsersManager& other) = delete;

    //template<typename>
    std::vector<User> GetUsersByAttribute(search_attr_t attribute, const std::string& value);

private:
    // LongIDsManager m_long_ids_manager;
    // NamesManager m_names_manager;
    // DOBsManager m_dobs_manager;

    std::map<user_uid_t, pos_in_file_t> m_users_and_positions;
}; //UsersManager


