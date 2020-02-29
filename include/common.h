  
#pragma once

#include <stdlib.h>
#include <set>
#include <vector>
#include <string>

typedef size_t user_uid_t;
typedef std::set<user_uid_t> users_ordered_cont_t;
typedef std::vector<user_uid_t> users_unordered_cont_t;
typedef size_t pos_in_file_t;
typedef std::string first_name_t;
typedef std::string last_name_t;
typedef std::pair<first_name_t, last_name_t> full_name_t;
typedef std::string long_id_t;
typedef std::string country_t;
typedef std::string email_t;

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