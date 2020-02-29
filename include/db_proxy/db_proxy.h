#pragma once

#include <vector>
#include <map>

#include "common.h"
#include "users/users_manager.h"

class DBProxy
{
public:
    DBProxy(const std::string& db_file_name);
    ~DBProxy() = default;
    DBProxy(const DBProxy& other) = delete;
    DBProxy& operator=(const DBProxy& other) = delete;

    std::vector<user_t> GetUsersByAttribute(search_attr_t attribute, const std::string& value);

private:
    std::string m_db_file_name;
    std::map<user_uid_t, pos_in_file_t> m_users_and_positions;
    UsersManager m_users_manager;

    void add_user_to_user_manager(pos_in_file_t pos, const std::string& line);
    void update_recently_added_users();

    user_t get_user_from_uid(user_uid_t uid);
    std::vector<user_t> get_users_from_uids(users_ordered_cont_t& uids);
}; //DBProxy