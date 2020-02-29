#include <iostream> //RRR
#include "date_of_birth/day.h"
#include "container/cont_funcs.h"


void Day::AddUser(user_uid_t user)
{
    m_users_cont.insert(user);
}

void Day::AddUsersToExternalCont(users_ordered_cont_t& ext_users_cont)
{
    ContFuncs::AddUsersInContToExternalCont(m_users_cont, ext_users_cont);
}