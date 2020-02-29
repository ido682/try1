#pragma once

#include "file_handler/file_wrapper.h"


class FileReader
{
private:
    static int m_s_last_pos;

public:
    FileReader(const std::string& file_name);
    ~FileReader() = default;
    FileReader(const FileReader& other) = delete;
    FileReader& operator=(const FileReader& other) = delete;

    void ProcessNewLines();
    void ProcessLineRRR(const std::string& line);

private:
    ReadOnlyFileWrapper m_file;
};

