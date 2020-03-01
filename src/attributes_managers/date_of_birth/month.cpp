#include <iostream> //RRR
#include "attributes_managers/date_of_birth/month.h"


void Month::AddUser(day_t day, user_uid_t user)
{
    m_days[day].AddUser(user);
}

void Month::add_users_in_range_to_external_cont(day_t begin_day, day_t end_day, users_ordered_cont_t& ext_users_cont)
{
    for (day_t curr_day = begin_day; curr_day < end_day; ++curr_day)
	{
		m_days[curr_day].AddUsersToExternalCont(ext_users_cont);
	}
}

void Month::AddUsersBornAfterGivenDayToExternalCont(day_t day, users_ordered_cont_t& ext_users_cont)
{
    add_users_in_range_to_external_cont(day + 1, MAX_DAYS_IN_MONTH + 1, ext_users_cont);
}

void Month::AddUsersBornOnOrBeforeGivenDayToExternalCont(day_t day, users_ordered_cont_t& ext_users_cont)
{
    add_users_in_range_to_external_cont(1, day + 1, ext_users_cont);
}

void Month::AddUsersOfWholeMonthToExternalCont(users_ordered_cont_t& ext_users_cont)
{
    add_users_in_range_to_external_cont(1, MAX_DAYS_IN_MONTH + 1, ext_users_cont);
}

void Month::DeleteUser(day_t day, user_uid_t user)
{
    m_days[day].DeleteUser(user);
}

