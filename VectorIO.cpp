#include <iostream>
#include <vector>
#include <algorithm>
#include "FileIO.h"
#include "VectorIO.h"

VectorIO::VectorIO():FileIO() {}
VectorIO::~VectorIO() {}

std::vector<std::string> VectorIO::loadline(std::string path)
{
    std::stringstream ss = this->LF2Str(path);
    std::vector<std::string> out;
    std::string temp_line;
    while (std::getline(ss, temp_line))
        out.push_back(temp_line);
    return out;
}

void VectorIO::saveline(std::vector<std::string> input, std::string path)
{
    std::stringstream out;
    for (int i=0; i<input.size(); i++)
    {
        out <<input[i];
        if (i!=input.size()-1)
            out<<'\n';
    }
    this->SFStr(out.str(), path);
}


template <class T>
std::vector<std::vector<T>> VectorIO::loadtxt(std::string path, char delim)
{
    //Load File as stringstream
    std::stringstream ss = this->LF2Str(path);
    //
    //create output Array
    std::vector<std::vector<T>> out;
    //map the string into the array
    std::string temp_line;

    while (std::getline(ss, temp_line))
    {

        //std::cout<<temp_str<<std::endl;
        //map data for the line number i
        if (this->isEmpty(temp_line)==false)
        {
            //replace the delimiter to space
            if (delim != ' ')
                std::replace(temp_line.begin(), temp_line.end(), delim, ' ');
            std::stringstream temp_ss(temp_line);
            //map the data

            std::string temp_str;
            std::vector<T> temp_out;
            while (temp_ss>>temp_str)
            {
                T temp_data;
                std::stringstream(temp_str)>>temp_data;
                temp_out.push_back(temp_data);
            }

            out.push_back(temp_out);
        }
    }
    return out;
}
template std::vector<std::vector<std::string>> VectorIO::loadtxt(std::string path, char delim);
template std::vector<std::vector<double>> VectorIO::loadtxt(std::string path, char delim);
template std::vector<std::vector<int>> VectorIO::loadtxt(std::string path, char delim);

template <class T>
void VectorIO::savetxt(std::vector<std::vector<T>> input, std::string path, char delim)
{
    std::string out = this->Vector2Str(input, delim);
    this->SFStr(out, path);
}
template void VectorIO::savetxt(std::vector<std::vector<std::string>> input, std::string path, char delim);
template void VectorIO::savetxt(std::vector<std::vector<int>> input, std::string path, char delim);
template void VectorIO::savetxt(std::vector<std::vector<double>> input, std::string path, char delim);

template <class T>
std::string VectorIO::Vector2Str(std::vector<std::vector<T>> input, char delim)
{
    //Size of the array
    int rowNum = input.size();
    int colNum = input[0].size();

    //build string
    std::stringstream out;
    for (int i=0; i<rowNum; i++)
    {
        for (int j=0; j<colNum; j++)
        {
            out<<input[i][j];
            if (j!=colNum-1)
                out<<delim;
        }
        if (i!=rowNum-1)
            out<<'\n';
    }
    return out.str();
}
template std::string VectorIO::Vector2Str(std::vector<std::vector<std::string>> input, char delim);
template std::string VectorIO::Vector2Str(std::vector<std::vector<int>> input, char delim);
template std::string VectorIO::Vector2Str(std::vector<std::vector<double>> input, char delim);
