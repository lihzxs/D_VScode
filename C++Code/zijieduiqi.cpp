#include <iostream>
using namespace std;

// 结构体一般存在字节对齐，，怎么取消呢？？
//取消字节对齐
/*#pragma pack(1) 预处理指令，
该指令告诉编译器以字节对齐值1字节对结构体进行对齐。
这通常被称为"紧密排列"，
即结构体的每个成员都占用结构体的一个字节。*/
#pragma pack(1)
struct Node
{
    char ch; // 1
    char c;
    int a; // 4
    unsigned int aa;
    int cc;
    double b; // 8
};
int main()
{
    cout << "sizoof(Node) = " << sizeof(Node) << endl;
    system("pause");
    return 0;
}