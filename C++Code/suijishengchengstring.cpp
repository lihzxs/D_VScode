#include <iostream>
#include <string>
#include <time.h>
#include <set>
#include <vector>
using namespace std;

//生成随机长度固定的字符串
string getRandAndString(int num)
{
    string randStr = "";
    string mainStr = "abcdefghijklmnopqrstuvwxyz";

    int numsize = mainStr.size();
    cout << "mainStr.size = " << numsize << endl;

    srand((unsigned int)time(NULL));

    for (int i = 0; i < num; i++)
    {
        char ch = mainStr[rand() % numsize];
        randStr += ch;
    }
    return randStr;
}

// set容器配合vector
void test()
{
    vector<int> vec;
    set<int> s;
    srand((unsigned int)time(0));
    for (int i = 0; i < 10; i++)
    {
        int num = rand() % 20;
        if (s.insert(num).second)
        {
            vec.emplace_back(num);
        }
    }
    cout << "s.size = " << s.size() << endl;
    cout << "vec.size = " << vec.size() << endl;

    for (int &i : vec)
    {
        cout << i << endl;
    }
}
int main()
{
    // cout << getRandAndString(6) << endl;

    test();
    system("pause");
    return 0;
}