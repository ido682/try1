#include <vector>

#include "users/parser.h"


namespace Parser
{
    void ParseAttributes(const std::string& line,
                         long_id_t& long_id_out_param,
                         email_t& email_out_param,
                         full_name_t& full_name_out_param,
                         date_t& dob_out_param,
                         country_t& country_out_param)
    {
        std::vector<std::string> attributes = Split(line, COMMA);

        long_id_out_param = attributes[ID];
        email_out_param = attributes[EMAIL];
        full_name_out_param = ParseName(attributes[FULL_NAME]);
        dob_out_param = ParseDate(attributes[DOB], SLASH);
        country_out_param = attributes[COUNTRY];
    }

    date_t ParseDate(const std::string& date_in_string, const std::string& delimiter)
    {
        std::vector<std::string> dob_split = Split(date_in_string, delimiter);

        date_t date = {std::stoi(dob_split[0]),
                       std::stoi(dob_split[1]),
                       std::stoi(dob_split[2])};

        return date;
    }

    full_name_t ParseName(const std::string& name_in_one_string)
    {
        std::vector<std::string> name_split = Split(name_in_one_string, SPACE);

        full_name_t full_name = std::make_pair(name_split[0], name_split[1]);

        return full_name;
    }

    std::vector<std::string> Split(const std::string& line, const std::string& delimiter)
    {
        std::string line_copy(line);
        size_t delimiter_length = delimiter.length();
        size_t pos;
        std::string token;
        std::vector<std::string> words;

        while ((pos = line_copy.find(delimiter)) != std::string::npos)
        {
            token = line_copy.substr(0, pos);
            words.push_back(token);
            line_copy.erase(0, pos + delimiter_length);
        }
        words.push_back(line_copy);

        return words;
    }
}