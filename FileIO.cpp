#include <iostream>
#include <sstream>
#include <fstream>
#include <Dense>
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
