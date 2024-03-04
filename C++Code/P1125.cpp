#include <iostream>
#include <cmath>
#include <unordered_map>
#include <string>
using namespace std;
bool is_prime(int num)
{
    if (num < 2)
        return false;
    int k = sqrt(num);
    for (int i = 2; i <= k; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int num, mmax, mmin;
    string str;
    unordered_map<char, int> ump;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        ump[str[i]]++;
    }
    mmax = -99999999, mmin = 99999999;
    for (auto a : ump)
    {
        if (a.second > mmax)
        {
            mmax = a.second;
        }
        if (a.second < mmin)
        {
            mmin = a.second;
        }
    }
    num = mmax - mmin;
    if (is_prime(num))
    {
        cout << "Lucky Word" << endl;
        cout << num << endl;
    }
    else
    {
        cout << "No Answer" << endl;
        cout << num << endl;
    }
    system("pause");
    return 0;
}