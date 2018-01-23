#include <iostream>
#include "FileIO.h"
using namespace std;

int main()
{
    FileIO *FIO = new FileIO(); 
    string path = "Set_Sa.out";
    stringstream out = FIO->LF2Str(path);
    //cout<<out.str()<<endl;
    FIO->SFStr(out.str(), "saved.txt");
    return 0;
}
