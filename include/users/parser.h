#pragma once

#include <string>
#include "common.h"

namespace Parser
{
    typedef enum
    {
        ID,
        EMAIL,
        FULL_NAME,
        DOB,
        COUNTRY,
        NUM_OF_ATTRS
    } user_attr_t;

    const std::string COMMA = ",";
    const std::string SPACE = " ";
    const std::string SLASH = "/";
    
    //RRR
    // void ParseAttributes(const std::string& line,
    //                      long_id_t& long_id_out_param,
    //                      email_t& email_out_param,
    //                      full_name_t& full_name_out_param,
    //                      date_t& dob_out_param,
    //                      country_t& country_out_param);
    user_t ParseUser(const std::string& line);
    date_t ParseDate(const std::string& date_in_string, const std::string& delimiter);
    full_name_t ParseName(const std::string& name_in_one_string);
    std::vector<std::string> Split(const std::string& line, const std::string& delimiter);
    std::string ToLower(const std::string& original_string);
}; // Parser