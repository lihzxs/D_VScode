#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    string str("Hello World Hello Hello");
    stringstream ss;
    ss<<str;
    string temp;
   // ss.str("");   //string类型时对 ss置空
    ss.clear();   //对string不管用
    while(ss>>temp)
    {
        cout<<temp<<endl;
    }
    system("pause");
    return 0;
}