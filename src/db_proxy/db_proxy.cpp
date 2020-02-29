#include <iostream> //RRR
#include "db_proxy/db_proxy.h"
#include "file_handler/file_reader.h"
#include "common/parser.h"


DBProxy::DBProxy(const std::string& db_file_name) :
    m_db_file_name(db_file_name)
{
    // Intentionally left blank
}

void DBProxy::add_user_to_user_manager(pos_in_file_t pos, const std::string& line)
{
    user_uid_t uid = m_users_manager.AddUser(Parser::ParseUser(line));
    m_users_and_positions[uid] = pos;
}

user_t DBProxy::get_user_from_uid(user_uid_t uid)
{
    user_t user;
    pos_in_file_t pos = m_users_and_positions[uid];

    {
        FileReader db_file(m_db_file_name);
        std::string user_line = db_file.GetLine(pos);
        user = Parser::ParseUser(user_line);
    }

    return user;    
}

// Doesn't use get_user_from_uid() to avoid multiple openning and closing of the file
std::vector<user_t> DBProxy::get_users_from_uids(users_ordered_cont_t& uids)
{
    std::vector<user_t> users;
    
    {
        FileReader db_file(m_db_file_name);

        for (const auto& uid : uids)
        {
            pos_in_file_t pos = m_users_and_positions[uid];
            std::string user_line = db_file.GetLine(pos);
            users.push_back(Parser::ParseUser(user_line));
        }
    }

    return users;    
}

void DBProxy::update_recently_added_users()
{    
    std::map<pos_in_file_t, std::string> positions_and_lines;

    {
        FileReader db_file(m_db_file_name);
        positions_and_lines  = db_file.GetNewLines();
    }

    for (const auto& pos_and_line : positions_and_lines)
    {
        if (pos_and_line.first == 0)
        {
            continue;
        }
        
        add_user_to_user_manager(pos_and_line.first, pos_and_line.second);
    }
}

// Having a general function to all attributes avoids future possible mistakes
// which could be caused by not calling update_recently_added_users()
std::vector<user_t> DBProxy::GetUsersByAttribute(search_attr_t attribute, const std::string& value)
{    
    update_recently_added_users();
    
    auto uids = m_users_manager.GetUsersByAttribute(attribute, value);

    return get_users_from_uids(uids);
}

user_t DBProxy::GetUserByLongID(long_id_t long_id)
{
    update_recently_added_users();

    user_uid_t uuid = m_users_manager.GetUserByLongID(long_id);

    return get_user_from_uid(uuid);
}


