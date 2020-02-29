#include <iostream> //RRR
#include <sstream>
#include "common.h"
#include "users/parser.h" //RRR
#include "file_handler/file_reader.h"


int FileReader::m_s_last_pos = 0;

FileReader::FileReader(const std::string& file_name) :
    m_file(file_name)
{
    // Intentionally left blank
}

void FileReader::ProcessNewLines()
{
    m_file.GetFileRef().seekg(m_s_last_pos, m_file.GetFileRef().beg);
    std::string curr_line;

    while (std::getline(m_file.GetFileRef(), curr_line))
    {
        /* PROCESS LINE INFO WITH curr_line*/
        /* PROCESS LINE INFO WITH curr_line*/
        /* PROCESS LINE INFO WITH curr_line*/
        if (m_s_last_pos != 0)
        {
            ProcessLineRRR(curr_line);
        }
        
        m_s_last_pos = m_file.GetFileRef().tellg();
    }
}

void FileReader::ProcessLineRRR(const std::string& line)
{
    long_id_t long_id;
    email_t email;
    full_name_t full_name;
    date_t dob;
    country_t country;

    Parser::ParseAttributes(line, long_id, email, full_name, dob, country);

    std::cout<<"long_id: "<<long_id<<std::endl;
    std::cout<<"email: "<<email<<std::endl;
    std::cout<<"first name: "<<full_name.first<<std::endl;
    std::cout<<"last name: "<<full_name.second<<std::endl;
    std::cout<<"day: "<<dob.day<<std::endl;
    std::cout<<"month: "<<dob.month<<std::endl;
    std::cout<<"year: "<<dob.year<<std::endl;
    std::cout<<"country: "<<country<<std::endl;
}

