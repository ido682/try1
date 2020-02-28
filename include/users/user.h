#pragma once

#include <string>
#include "common.h"


class User
{
public:
    User(const std::string& user_line_from_data_file);
    ~User() = default;
    User(const User& other) = delete;
	User& operator=(const User& other) = delete;

private:
    user_uid_t uid;
    size_t line_in_data_file;
    std::string long_id;
    std::string email;
    std::string first_name;
    std::string last_name;
    date_t dob;
    std::string country;
} user_t;


