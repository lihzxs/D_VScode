#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    cout << "Hello World" << endl;

    int arr[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // partial_sort   部分排序算法

    partial_sort(arr, arr + 5, arr + 10, [](int x, int y)
                 { return x > y; });

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }

    stable_sort(arr, arr + 10);
    // issorted和issorted_until   判断序列是否有序算法
    if (is_sorted(arr, arr + 10))
    {
        cout << "youxu" << endl;
    }
    else
    {
        cout << "wuxu" << endl;
    }

    int *p = is_sorted_until(arr, arr + 10);
    if (p == arr + 10)
    {
        cout << "youxu" << endl;
    }
    else
    {
        cout << "wuxu" << endl;
    }
    system("pause");
    return 0;
}