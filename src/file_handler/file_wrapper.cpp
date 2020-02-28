#include <iostream> // RRR
#include "file_handler/file_wrapper.h"



ReadOnlyFileWrapper::ReadOnlyFileWrapper(const std::string& file_name) :
    m_file(file_name)
{
    // Intentionally left blank
    std::cout<<"RRR ReadOnlyFileWrapper Ctor"<<std::endl;
}

ReadOnlyFileWrapper::~ReadOnlyFileWrapper()
{
    std::cout<<"RRR ReadOnlyFileWrapper Dtor"<<std::endl;
    m_file.close();
}

std::ifstream& ReadOnlyFileWrapper::GetFileRef()
{
    return m_file;
}