#ifndef VectorIO_h
#define VectorIO_h

#include <iostream>
#include <vector>
#include "FileIO.h"


class VectorIO : public FileIO
{
public:
    VectorIO();
    ~VectorIO();

    std::vector<std::string> loadline(std::string path);
    void saveline(std::vector<std::string> input, std::string path);

    template <class T>
    std::vector<std::vector<T>> loadtxt(std::string path, char delim=' ');

    template <class T>
    void savetxt(std::vector<std::vector<T>> input, std::string path, char delim=' ');

    template <class T>
    std::string Vector2Str(std::vector<std::vector<T>> input, char delim = ' ');
};

#endif
