#include <iostream>
#include <vector>
#include "VectorIO.h"

using namespace std;

int main()
{
    string path = "C:/Users/yjiang/Desktop/tmp.txt";
    VectorIO *VIO = new VectorIO();
    //cout<<out.str()<<endl;
    //FIO->SFStr(out.str(), "C:/Users/yjiang/Desktop/saved.txt");
    //cout<<FIO->rowNum(out, true)<<endl;
    //cout<<FIO->colNum(out, ',')<<endl;
    //cout<<out.str()<<endl;
    //cout<<FIO->isEmpty("   ")<<endl;
    //cout<<out.str()<<endl;

    vector<vector<string>> out = VIO->loadtxt<string>(path, ',');
    //cout<<out[0][0]<<endl;
    VIO->savetxt(out, "C:/Users/yjiang/Desktop/saved.txt");
    return 0;
}
