#include <iostream> //RRR
#include "/home/ido/workspace/zooz/users_search/include/date_of_birth/month.h"


void Month::AddUser(int day, user_uid_t user)
{
    // std::cout<<"RRR in Month::AddUser before, day is "<<day<<std::endl;
    m_days[day].AddUser(user);
    // std::cout<<"RRR in Month::AddUser after"<<std::endl;
}

void Month::add_users_in_range_to_external_cont(int begin_day, int end_day, users_unordered_cont_t& ext_users_cont)
{
    for (int curr_day = begin_day; curr_day < end_day; ++curr_day)
	{
		m_days[curr_day].AddUsersToExternalCont(ext_users_cont);
	}
}

void Month::AddUsersBornAfterGivenDayToExternalCont(int day, users_unordered_cont_t& ext_users_cont)
{
    add_users_in_range_to_external_cont(day + 1, MAX_DAYS_IN_MONTH + 1, ext_users_cont);
}

void Month::AddUsersBornOnOrBeforeGivenDayToExternalCont(int day, users_unordered_cont_t& ext_users_cont)
{
    add_users_in_range_to_external_cont(1, day + 1, ext_users_cont);
}

void Month::AddUsersOfWholeMonthToExternalCont(users_unordered_cont_t& ext_users_cont)
{
    add_users_in_range_to_external_cont(1, MAX_DAYS_IN_MONTH + 1, ext_users_cont);
}

