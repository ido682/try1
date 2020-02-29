#include "iostream" //RRR
#include "users/users_manager.h"
#include "users/parser.h"
#include "file_handler/file_reader.h"


// might want to use 0 to imply an invalid user in the future
size_t UsersManager::m_s_counter = 1;

user_uid_t UsersManager::AddUser(const user_t& user)
{    
    user_uid_t user_uid = m_s_counter++;
    full_name_t full_name = Parser::ParseName(user.full_name);
    date_t dob = Parser::ParseDate(user.dob);

    m_names_manager.AddUser(full_name, user_uid);
    m_dobs_manager.AddUser(dob, user_uid);

    return user_uid;
}

users_ordered_cont_t UsersManager::GetUsersByAttribute(search_attr_t attribute, const std::string& value)
{    
    switch (attribute)
    {
    case ID:
        return users_ordered_cont_t();

    case NAME:
        return m_names_manager.GetUsersByName(value);

    case AGE:
        return m_dobs_manager.GetUsersInGivenAge(std::stoi(value));
    
    default:
        return users_ordered_cont_t();
    }
}