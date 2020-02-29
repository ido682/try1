#include <iostream> //RRR
#include "names/names_manager.h"


void NamesManager::AddUser(full_name_t full_name, user_uid_t user)
{
    m_first_names.AddUser(full_name.first, user);
    m_last_names.AddUser(full_name.second, user);
}

users_ordered_cont_t NamesManager::GetUsersByName(const std::string& name)
{
    users_ordered_cont_t users;

    m_first_names.AddUsersWithGivenNameToExternalCont(name, users);
    m_last_names.AddUsersWithGivenNameToExternalCont(name, users);

    return users;
}