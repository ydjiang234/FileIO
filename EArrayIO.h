#ifndef EArrayIO_h
#define EArrayIO_h

#include <iostream>
#include <Dense>
#include "FileIO.h"

class EArrayIO : public FileIO
{
public:
    EArrayIO();
    ~EArrayIO();

    Eigen::ArrayXXd loadtxt(std::string path, char delim=' ');

    void savetxt(Eigen::ArrayXXd input, std::string path, char delim=' ');

    std::string EArray2Str(Eigen::ArrayXXd input, char delim = ' ');
};

#endif
