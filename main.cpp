#include <iostream>
#include "FileIO.h"
using namespace std;

int main()
{
    FileIO *FIO = new FileIO(); 
    string path = "C:/Users/yjiang/Desktop/tmp.txt";
    stringstream out = FIO->LF2Str(path);
    //cout<<out.str()<<endl;
    //FIO->SFStr(out.str(), "C:/Users/yjiang/Desktop/saved.txt");
    cout<<FIO->rowNum(out, true)<<endl;
    cout<<FIO->colNum(out, ',')<<endl;
    //cout<<out.str()<<endl;
    cout<<FIO->isEmpty("   ")<<endl;
    cout<<out.str()<<endl;
    return 0;
}
