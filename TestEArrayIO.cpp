#include <iostream>
#include <Dense>
#include "EArrayIO.h"

using namespace std;
using Eigen::ArrayXXd;
int main()
{
    string path = "C:/Users/yjiang/Desktop/tmp.txt";
    EArrayIO *EAIO = new EArrayIO();
    //cout<<out.str()<<endl;
    //FIO->SFStr(out.str(), "C:/Users/yjiang/Desktop/saved.txt");
    //cout<<FIO->rowNum(out, true)<<endl;
    //cout<<FIO->colNum(out, ',')<<endl;
    //cout<<out.str()<<endl;
    //cout<<FIO->isEmpty("   ")<<endl;
    //cout<<out.str()<<endl;

    ArrayXXd out = EAIO->loadtxt(path, ',');
    EAIO->savetxt(out, "C:/Users/yjiang/Desktop/saved.txt", ' ');
    return 0;
}
