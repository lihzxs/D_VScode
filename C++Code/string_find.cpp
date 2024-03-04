#include <iostream>
#include <string>

using namespace std;
int main()
{
    // find_first_of算法：
    // 查找住字符串中第一个字符在里面的

    string str1 = "Aabcabcaaaacccc";
    // 下标为1的字符在aa字符串里面，，所以输出1
    cout << str1.find_first_of("aa") << endl;

    // 中文字符的size

    string str2 = "刘萌萌";
    // size和length返回的都是字符的字节数
    cout << "str2.size = " << str2.size() << endl;
    cout << "str2.length = " << str2.length() << endl;

        system("pause");
    return 0;
}