#pragma once

#include "common/common.h"


class Day
{
public:
	Day() = default;
	~Day() = default;
	Day(const Day& other) = delete;
	Day& operator=(const Day& other) = delete;

	void AddUser(user_uid_t user);
    void AddUsersToExternalCont(users_ordered_cont_t& ext_users_cont);
	void DeleteUser(user_uid_t user);

private:
	users_ordered_cont_t m_users_cont;
};

