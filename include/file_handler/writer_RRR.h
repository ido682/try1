//RRR WHOLE FILE!!

#pragma once

#include <fstream>
#include <string>


class Writer
{
public:
    Writer(const std::string& file_name);
    ~Writer();
    Writer(const Writer& other) = delete;
    Writer& operator=(const Writer& other) = delete;

    void AddLine(const std::string& line_to_add);

private:
    std::fstream m_file;
};