#pragma once

#include <stdlib.h>
#include <set>
#include <vector>

typedef size_t user_uid_t;
typedef std::set<user_uid_t> users_ordered_cont_t;
typedef std::vector<user_uid_t> users_unordered_cont_t;

typedef int day_t;
typedef int month_t;
typedef int year_t;
typedef struct
{
    day_t day;
    month_t month;
    year_t year;
} date_t;

typedef struct
{
    std::string id;
    std::string email;
    std::string first_name;
    std::string last_name;
    date_t dob;
    std::string country;
} user_t;

