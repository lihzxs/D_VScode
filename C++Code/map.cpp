#include <iostream>
#include <map>
using namespace std;
class Compare
{
public:
    bool operator()(string str1, string str2) const
    {
        return str1.size() < str2.size();
    }
};
int main()
{
    map<string, unsigned int, Compare> mp;

    mp.insert(make_pair("llll", 10));
    mp.insert(make_pair("lll", 100));
    mp.insert(make_pair("ll", 1000));
    mp.insert(make_pair("l", 10000));

    for (auto a : mp)
    {
        cout << a.first << " " << a.second << endl;
    }
    auto b = mp.erase("llll");
    if (b == true)
    {
        cout << "shanchucg" << endl;
    }

    auto c = mp.find("l");
    if (c == mp.end())
    {
        cout << "zhaobudao" << endl;
    }
    else
    {
        cout << "zhaodaol" << endl;
    }
    system("pause");
    return 0;
}