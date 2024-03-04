#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    //比较里面的内容是否相同？？equal算法
    string str1 = "Hello";
    string str2 = "hello";
    cout << boolalpha << equal(str1.begin(), str1.end(), str2.begin()) << endl;

    // max和min算法求数组的最大最小值
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int maxn = max({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    int minn = min({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

    cout << maxn << " " << minn << endl;

    //*minmaxelement算法求最大最小值

    //返回的是pair对组，，，两个都是迭代器
    auto a = minmax_element(arr, arr + 10);
    cout << "min = " << *(a.first) << " max = " << *(a.second) << endl;
    system("pause");
    return 0;
}