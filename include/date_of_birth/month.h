#pragma once

#include <array>

#include "/home/ido/workspace/zooz/users_search/include/common.h"
#include "/home/ido/workspace/zooz/users_search/include/date_of_birth/day.h"


class Month
{
private:
	static const int MAX_DAYS_IN_MONTH = 31;

public:
    Month() = default;
    ~Month() = default;
    Month(const Month& other) = delete;
    Month& operator=(const Month& other) = delete;

    void AddUser(int day, user_uid_t user);
    void AddUsersBornAfterGivenDayToExternalCont(int day, users_unordered_cont_t& ext_users_cont);
	void AddUsersBornOnOrBeforeGivenDayToExternalCont(int day, users_unordered_cont_t& ext_users_cont);
	void AddUsersOfWholeMonthToExternalCont(users_unordered_cont_t& ext_users_cont);

private:
    // day 0 will remain empty for code readablity
	std::array<Day, MAX_DAYS_IN_MONTH + 1> m_days;

    void add_users_in_range_to_external_cont(int begin_day, int end_day, users_unordered_cont_t& ext_users_cont);
};

