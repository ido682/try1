#pragma once

#include <map>
#include "common.h"
#include "date_of_birth/year.h"

class DOBsManager
{
public:
    DOBsManager() = default;
	~DOBsManager() = default;
	DOBsManager(const DOBsManager& other) = delete;
	DOBsManager& operator=(const DOBsManager& other) = delete;

    void AddUser(date_t dob, user_uid_t user);
    users_unordered_cont_t GetUsersInGivenAge(int age);

private:
    std::map<year_t, Year> m_years;

    date_t get_curr_date();
};

