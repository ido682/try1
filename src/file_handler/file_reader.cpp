#include <iostream> //RRR
#include <sstream>
#include "file_handler/file_reader.h"


int FileReader::m_last_point = 0;

FileReader::FileReader(const std::string& file_name) :
    m_file(file_name)
{
    // Intentionally left blank
}

void FileReader::ProcessNewLines()
{
    m_file.GetFileRef().seekg(m_last_point, m_file.GetFileRef().beg);
    std::string curr_line;

    while (std::getline(m_file.GetFileRef(), curr_line))
    {
        /* PROCESS LINE INFO WITH curr_line*/
        /* PROCESS LINE INFO WITH curr_line*/
        /* PROCESS LINE INFO WITH curr_line*/
        std::cout<<"RRR curr_line is "<<curr_line<<std::endl;
        m_last_point = m_file.GetFileRef().tellg();
    }
}