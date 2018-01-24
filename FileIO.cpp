#include <iostream>
#include <sstream>
#include <fstream>
#include "FileIO.h"

FileIO::FileIO() {}

FileIO::~FileIO() {}

std::stringstream FileIO::LF2Str(std::string path)
{
    std::stringstream out;
    std::ifstream file(path, std::ifstream::in);
    out <<file.rdbuf();
    return out;
}

void FileIO::SFStr(std::string s, std::string path)
{
    std::ofstream file(path, std::ifstream::out);
    file<<s;
    file.close();
}

int FileIO::rowNum(std::stringstream &ss, bool skipEmptyLine)
{
    int rowNum = 0;
    std::string temp_line;
    if (skipEmptyLine)
    {
        while (std::getline(ss, temp_line))
            if (this->isEmpty(temp_line)==false)
                rowNum++;
    } else {
        while (std::getline(ss, temp_line))
            rowNum++;
    }

    ss.clear();
    ss.seekg(0, std::ios::beg);
    return rowNum;
}

int FileIO::colNum(std::stringstream &ss, char delim)
{
    int colNum = 0;
    std::string temp_line;
    std::getline(ss, temp_line);
    if (delim != ' ')
    {
        std::replace(temp_line.begin(), temp_line.end(), delim, ' ');
    }
    std::stringstream temp_ss(temp_line);
    while (temp_ss >> temp_line)
    {
        colNum++;
    }
    ss.clear();
    ss.seekg(0, std::ios::beg);
    return colNum;
}

bool FileIO::isEmpty(std::string str)
{
    return (str.find_first_not_of(' ') == std::string::npos);
}
