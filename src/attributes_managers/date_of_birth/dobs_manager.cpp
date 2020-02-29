#include <iostream> //RRR
#include "attributes_managers/date_of_birth/dobs_manager.h"


void DOBsManager::AddUser(date_t dob, user_uid_t user)
{
    auto year_iter = m_years.find(dob.year);
    if (year_iter == m_years.end())
    {
        m_years.emplace(std::piecewise_construct,
                        std::make_tuple(dob.year),
                        std::make_tuple());
    }

    m_years[dob.year].AddUser(dob.day, dob.month, user);
}

date_t DOBsManager::get_curr_date()
{
    time_t curr_time = time(nullptr);
    struct tm *time_info = localtime(&curr_time);

    date_t curr_date;

    curr_date.day = time_info->tm_mday;
    curr_date.month = time_info->tm_mon + 1;
    curr_date.year = time_info->tm_year + 1900;

    return curr_date;
}

users_ordered_cont_t DOBsManager::GetUsersInGivenAge(int age, date_t curr_date)
{    
    users_ordered_cont_t users_in_given_age_result;

    year_t year_to_check_on_or_before_given_day = curr_date.year - age;
    year_t year_to_check_after_given_day = year_to_check_on_or_before_given_day - 1;

    m_years[year_to_check_after_given_day].AddUsersBornAfterGivenDayToExternalCont(curr_date.day, curr_date.month, users_in_given_age_result);
    m_years[year_to_check_on_or_before_given_day].AddUsersBornOnOrBeforeGivenDayToExternalCont(curr_date.day, curr_date.month, users_in_given_age_result);

    return users_in_given_age_result;
}

