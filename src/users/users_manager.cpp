#include "iostream" //RRR
#include "users/users_manager.h"
#include "users/parser.h"
#include "file_handler/file_reader.h"


// might want to use 0 to imply an invalid user in the future
size_t UsersManager::m_s_counter = 1;

user_uid_t UsersManager::AddUser(const user_t& user)
{
    std::cout<<"RRR in UsersManager::AddUser 1"<<std::endl;
    
    user_uid_t user_uid = m_s_counter++;

    std::cout<<"RRR in UsersManager::AddUser 2"<<std::endl;

    full_name_t full_name = Parser::ParseName(user.full_name);
    std::cout<<"RRR in UsersManager::AddUser, first is "<<full_name.first<<", second is "<<full_name.second<<std::endl;

    m_names_manager.AddUser(full_name, user_uid);

    std::cout<<"RRR in UsersManager::AddUser 3"<<std::endl;

    return user_uid;
}

users_ordered_cont_t UsersManager::GetUsersByAttribute(search_attr_t attribute, const std::string& value)
{    
    users_ordered_cont_t user_uids;
    
    switch (attribute)
    {
    case ID:
        /* code */
        break;

    case NAME:
        user_uids = m_names_manager.GetUsersByName(value);
        break;

    case AGE:
        /* code */
        break;
    
    default:
        break;
    }

    return user_uids;
}