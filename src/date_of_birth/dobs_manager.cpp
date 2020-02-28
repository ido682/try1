#include <iostream> //RRR
#include "/home/ido/workspace/zooz/users_search/include/date_of_birth/dobs_manager.h"


void DOBsManager::AddUser(int day, int month, int year, user_uid_t user)
{
    auto year_iter = m_years.find(year);
    if (year_iter == m_years.end())
    {
        std::cout<<"RRR creating year: "<<year<<std::endl;
        m_years.emplace(std::piecewise_construct,
                        std::make_tuple(year),
                        std::make_tuple());
    }

    m_years[year].AddUser(day, month, user);
}

void DOBsManager::get_date(int& day, int& month, int& year)
{
    time_t curr_time = time(nullptr);
    struct tm *time_info = localtime(&curr_time);

    day = time_info->tm_mday;
    month = time_info->tm_mon + 1;
    year = time_info->tm_year + 1900;
}

users_unordered_cont_t DOBsManager::GetUsersInGivenAge(int age)
{
    std::cout<<"RRR in DOBsManager::GetUsersInGivenAge, with age "<<age<<std::endl;
    
    int day;
    int month;
    int year;
    get_date(day, month, year);
    // std::cout<<"day: "<<day<<", month: "<<month<<", year: "<<year<<std::endl;
    
    users_unordered_cont_t users_in_given_age_result;

    int year_to_check_until_given_day = year - age;
    int year_to_check_since_given_day = year_to_check_until_given_day - 1;

    std::cout<<"RRR year_to_check_since_given_day: "<<year_to_check_since_given_day<<std::endl;
    std::cout<<"RRR year_to_check_until_given_day: "<<year_to_check_until_given_day<<std::endl;


    m_years[year_to_check_since_given_day].AddUsersBornAfterGivenDayToExternalCont(day, month, users_in_given_age_result);
    m_years[year_to_check_until_given_day].AddUsersBornOnOrBeforeGivenDayToExternalCont(day, month, users_in_given_age_result);

    return users_in_given_age_result;
}


