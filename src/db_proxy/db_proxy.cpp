#include <iostream> //RRR
#include "db_proxy/db_proxy.h"
#include "file_handler/file_reader.h"
#include "users/parser.h"


DBProxy::DBProxy(const std::string& db_file_name) :
    m_db_file_name(db_file_name)
{
    // Intentionally left blank
}

void DBProxy::add_user(pos_in_file_t pos, const std::string& line)
{
    std::cout<<"RRR in DBProxy::add_user 1"<<std::endl;
    user_uid_t uid = m_users_manager.AddUser(Parser::ParseUser(line));
    std::cout<<"RRR in DBProxy::add_user 2"<<std::endl;
    m_users_and_positions[uid] = pos;
    std::cout<<"RRR in DBProxy::add_user 3"<<std::endl;
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
    std::cout<<"RRR in DBProxy::update_recently_added_users 1"<<std::endl;
    
    std::map<pos_in_file_t, std::string> positions_and_lines;

    std::cout<<"RRR in DBProxy::update_recently_added_users 2"<<std::endl;
    
    {
        std::cout<<"RRR in DBProxy::update_recently_added_users 3"<<std::endl;
        FileReader db_file(m_db_file_name);
        std::cout<<"RRR in DBProxy::update_recently_added_users 4"<<std::endl;
        positions_and_lines  = db_file.GetNewLines();
        std::cout<<"RRR in DBProxy::update_recently_added_users 5"<<std::endl;
    }

    for (const auto& pos_and_line : positions_and_lines)
    {
        if (pos_and_line.first == 0)
        {
            continue;
        }
        
        add_user(pos_and_line.first, pos_and_line.second);
    }

    std::cout<<"RRR in DBProxy::update_recently_added_users 6"<<std::endl;
}

std::vector<user_t> DBProxy::GetUsersByAttribute(search_attr_t attribute, const std::string& value)
{
    std::cout<<"RRR in DBProxy::GetUsersByAttribute 1"<<std::endl;
    
    update_recently_added_users();

    std::cout<<"RRR in DBProxy::GetUsersByAttribute 2"<<std::endl;
    
    auto uids = m_users_manager.GetUsersByAttribute(attribute, value);

    std::cout<<"RRR in DBProxy::GetUsersByAttribute 3"<<std::endl;

    return get_users_from_uids(uids);
}

