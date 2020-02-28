#pragma once

#include "common.h"


class Day
{
public:
	Day() = default;
	~Day() = default;
	Day(const Day& other) = delete;
	Day& operator=(const Day& other) = delete;

	void AddUser(user_uid_t user);
    void AddUsersToExternalCont(users_unordered_cont_t& ext_users_cont);

private:
	users_ordered_cont_t m_users_cont;
};


