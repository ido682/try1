#pragma once

#include "file_handler/file_wrapper.h"


class FileReader
{
private:
    static int m_last_point;

public:
    FileReader(const std::string& file_name);
    ~FileReader() = default;
    FileReader(const FileReader& other) = delete;
    FileReader& operator=(const FileReader& other) = delete;

    void ProcessNewLines();

private:
    ReadOnlyFileWrapper m_file;
};

