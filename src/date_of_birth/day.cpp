#include "date_of_birth/day.h"


void Day::AddUser(user_uid_t user)
{
    m_users_cont.insert(user);
}

void Day::AddUsersToExternalCont(users_unordered_cont_t& ext_users_cont)
{
    ext_users_cont.insert(ext_users_cont.end(), m_users_cont.begin(), m_users_cont.end());
}