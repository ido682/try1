#include <iostream> //RRR
#include "attributes_managers/date_of_birth/year.h"


void Year::AddUser(day_t day, month_t month, user_uid_t user)
{
	m_months[month].AddUser(day, user);
}

void Year::AddUsersBornAfterGivenDayToExternalCont(day_t day, month_t month, users_ordered_cont_t& ext_users_cont)
{	
	m_months[month].AddUsersBornAfterGivenDayToExternalCont(day, ext_users_cont);

	for (month_t curr_month = month + 1; curr_month <= MONTHS_IN_YEAR; ++curr_month)
	{
		m_months[curr_month].AddUsersOfWholeMonthToExternalCont(ext_users_cont);
	}
}

void Year::AddUsersBornOnOrBeforeGivenDayToExternalCont(day_t day, month_t month, users_ordered_cont_t& ext_users_cont)
{
	for (month_t curr_month = 1; curr_month < month; ++curr_month)
	{
		m_months[curr_month].AddUsersOfWholeMonthToExternalCont(ext_users_cont);
	}

	m_months[month].AddUsersBornOnOrBeforeGivenDayToExternalCont(day, ext_users_cont);
}

void Year::DeleteUser(day_t day, month_t month, user_uid_t user)
{
	m_months[month].DeleteUser(day, user);
}

