#ifndef FileIO_h
#define FileIO_h

#include <iostream>
#include <sstream>
#include <Dense>

class FileIO
{
    public:

        FileIO();
        ~FileIO();

        std::stringstream LF2Str(std::string path);
        
        void SFStr(std::string s, std::string path);
};
#endif
