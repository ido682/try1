#include <iostream> //RRR
#include "/home/ido/workspace/zooz/users_search/include/date_of_birth/year.h"


void Year::AddUser(int day, int month, user_uid_t user)
{
	// std::cout<<"RRR in Year::AddUser before"<<std::endl;
	m_months[month].AddUser(day, user);
	// std::cout<<"RRR in Year::AddUser after"<<std::endl;
}

void Year::AddUsersBornAfterGivenDayToExternalCont(int day, int month, users_unordered_cont_t& ext_users_cont)
{
	std::cout<<"RRR in Year::AddUsersSinceGivenDayToExternalCont, with day "<<day<<" and month "<<month<<std::endl;
	
	m_months[month].AddUsersBornAfterGivenDayToExternalCont(day, ext_users_cont);

	for (int curr_month = month + 1; curr_month <= MONTHS_IN_YEAR; ++curr_month)
	{
		m_months[curr_month].AddUsersOfWholeMonthToExternalCont(ext_users_cont);
	}
}

void Year::AddUsersBornOnOrBeforeGivenDayToExternalCont(int day, int month, users_unordered_cont_t& ext_users_cont)
{
	std::cout<<"RRR in Year::AddUsersSinceGivenDayToExternalCont, with day "<<day<<" and month "<<month<<std::endl;

	for (int curr_month = 1; curr_month < month; ++curr_month)
	{
		m_months[curr_month].AddUsersOfWholeMonthToExternalCont(ext_users_cont);
	}

	m_months[month].AddUsersBornOnOrBeforeGivenDayToExternalCont(day, ext_users_cont);
}

