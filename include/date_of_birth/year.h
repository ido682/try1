#pragma once

#include <array>

#include "/home/ido/workspace/zooz/users_search/include/common.h"
#include "/home/ido/workspace/zooz/users_search/include/date_of_birth/month.h"


class Year
{
private:
	static const int MONTHS_IN_YEAR = 12;

public:
	Year() = default;
	~Year() = default;
	Year(const Year& other) = delete;
	Year& operator=(const Year& other) = delete;

	void AddUser(int day, int month, user_uid_t user);
	void AddUsersBornAfterGivenDayToExternalCont(int day, int month, users_unordered_cont_t& ext_users_cont);
	void AddUsersBornOnOrBeforeGivenDayToExternalCont(int day, int month, users_unordered_cont_t& ext_users_cont);

private:
	// month 0 will remain empty for code readablity
	std::array<Month, MONTHS_IN_YEAR + 1> m_months;
};

