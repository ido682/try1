//RRR WHOLE FILE!!

#include "file_handler/writer_RRR.h"

Writer::Writer(const std::string& file_name) :
    m_file(file_name, std::fstream::app|std::fstream::out)
{
    // Intentionally left blank
}

Writer::~Writer() 
{
    m_file.close();
}

void Writer::AddLine(const std::string& line_to_add)
{
    m_file << line_to_add << std::endl;
}