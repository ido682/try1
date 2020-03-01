#pragma once

#include <array>

#include "common/common.h"
#include "attributes_managers/date_of_birth/day.h"


class Month
{
private:
	static const int MAX_DAYS_IN_MONTH = 31;

public:
    Month() = default;
    ~Month() = default;
    Month(const Month& other) = delete;
    Month& operator=(const Month& other) = delete;

    void AddUser(day_t day, user_uid_t user);
    void AddUsersBornAfterGivenDayToExternalCont(day_t day, users_ordered_cont_t& ext_users_cont);
	void AddUsersBornOnOrBeforeGivenDayToExternalCont(day_t day, users_ordered_cont_t& ext_users_cont);
	void AddUsersOfWholeMonthToExternalCont(users_ordered_cont_t& ext_users_cont);
    void DeleteUser(day_t day, user_uid_t user);

private:
    // day 0 will remain empty for code readablity
	std::array<Day, MAX_DAYS_IN_MONTH + 1> m_days;

    void add_users_in_range_to_external_cont(day_t begin_day, day_t end_day, users_ordered_cont_t& ext_users_cont);
};

