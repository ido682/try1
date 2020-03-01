#pragma once

#include <array>

#include "common/common.h"
#include "attributes_managers/date_of_birth/month.h"



class Year
{
private:
	static const int MONTHS_IN_YEAR = 12;

public:
	Year() = default;
	~Year() = default;
	Year(const Year& other) = delete;
	Year& operator=(const Year& other) = delete;

	void AddUser(day_t day, month_t month, user_uid_t user);
	void AddUsersBornAfterGivenDayToExternalCont(day_t day, month_t month, users_ordered_cont_t& ext_users_cont);
	void AddUsersBornOnOrBeforeGivenDayToExternalCont(day_t day, month_t month, users_ordered_cont_t& ext_users_cont);
	void DeleteUser(day_t day, month_t month, user_uid_t user);

private:
	// month 0 will remain empty for code readablity
	std::array<Month, MONTHS_IN_YEAR + 1> m_months;
};

