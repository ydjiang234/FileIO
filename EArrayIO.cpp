#include <iostream>
#include <Dense>
#include "FileIO.h"
#include "EArrayIO.h"

EArrayIO::EArrayIO():FileIO() {}
EArrayIO::~EArrayIO() {}

Eigen::ArrayXXd EArrayIO::loadtxt(std::string path, char delim)
{
    //Load File as stringstream
    std::stringstream ss = this->LF2Str(path);
    //Get the row and col number
    int rowNum = this->rowNum(ss, true);
    int colNum = this->colNum(ss, delim);
    //
    //create output Array
    Eigen::ArrayXXd out(rowNum, colNum);
    //map the string into the array
    std::string temp_line;
    int i = 0;
    while (std::getline(ss, temp_line))
    {
        //std::cout<<i<<std::endl;
        //map data for the line number i
        if (this->isEmpty(temp_line)==false)
        {
            //replace the delimiter to space
            if (delim != ' ')
                std::replace(temp_line.begin(), temp_line.end(), delim, ' ');
            std::stringstream temp_ss(temp_line);
            //map the data
            double temp_data;
            int j = 0;
            while (temp_ss>>temp_data)
            {
                out(i,j) = temp_data;
                j++;
            }
            i++;
        }

    }
    return out;
}

void EArrayIO::savetxt(Eigen::ArrayXXd input, std::string path, char delim)
{
    std::string out = this->EArray2Str(input, delim);
    this->SFStr(out, path);
}

std::string EArrayIO::EArray2Str(Eigen::ArrayXXd input, char delim)
{
    //Size of the array
    int rowNum = input.rows();
    int colNum = input.cols();

    //build string
    std::stringstream out;
    for (int i=0; i<rowNum; i++)
    {
        for (int j=0; j<colNum; j++)
        {
            out<<input(i,j);
            if (j!=colNum-1)
                out<<delim;
        }
        if (i!=rowNum-1)
            out<<'\n';
    }
    return out.str();
}
