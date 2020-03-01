#include <iostream> //RRR
#include "attributes_managers/date_of_birth/day.h"
#include "common/cont_funcs.h"


void Day::AddUser(user_uid_t user)
{
    m_users_cont.insert(user);
}

void Day::AddUsersToExternalCont(users_ordered_cont_t& ext_users_cont)
{
    ContFuncs::AddUsersInContToExternalCont(m_users_cont, ext_users_cont);
}

void Day::DeleteUser(user_uid_t user)
{
    m_users_cont.erase(user);
}
