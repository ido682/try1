#pragma once

#include <map>
#include "common/common.h"
#include "attributes_managers/date_of_birth/year.h"

class DOBsManager
{
public:
    DOBsManager() = default;
	~DOBsManager() = default;
	DOBsManager(const DOBsManager& other) = delete;
	DOBsManager& operator=(const DOBsManager& other) = delete;

    void AddUser(date_t dob, user_uid_t user);
    users_ordered_cont_t GetUsersInGivenAge(int age, date_t curr_date = get_curr_date());
    void DeleteUser(date_t dob, user_uid_t user);

private:
    std::map<year_t, Year> m_years;

    static date_t get_curr_date();
};
