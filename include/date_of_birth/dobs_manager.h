#pragma once

#include <map>
#include "/home/ido/workspace/zooz/users_search/include/common.h"
#include "/home/ido/workspace/zooz/users_search/include/date_of_birth/year.h"

class DOBsManager
{
public:
    DOBsManager() = default;
	~DOBsManager() = default;
	DOBsManager(const DOBsManager& other) = delete;
	DOBsManager& operator=(const DOBsManager& other) = delete;

    void AddUser(int day, int month, int year, user_uid_t user);
    users_unordered_cont_t GetUsersInGivenAge(int age);

private:
    std::map<int, Year> m_years;

    void get_date(int& day, int& month, int& year);
};

