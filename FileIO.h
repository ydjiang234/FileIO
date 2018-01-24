#ifndef FileIO_h
#define FileIO_h

#include <iostream>
#include <sstream>

class FileIO
{
    public:

        FileIO();
        ~FileIO();

        std::stringstream LF2Str(std::string path);
        
        void SFStr(std::string s, std::string path);

        int rowNum(std::stringstream &ss, bool skipEmptyLine = true);
        int colNum(std::stringstream &ss, char delim=' ');
        bool isEmpty(std::string s);
};
#endif
