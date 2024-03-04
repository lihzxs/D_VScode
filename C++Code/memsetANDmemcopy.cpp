#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
    int arr[10];
    memset(arr, -1, sizeof(arr));
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int *temp = new int[10];

    memcpy(temp, arr, sizeof(arr));

    for (int i = 0; i < 10; i++)
    {
        cout << temp[i] << "  ";
    }
    cout << endl;
    delete[] temp;

    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    vector<int> tt;
    tt.resize(vec.size());

    cout << "vec rongliang:" << vec.capacity() << " tt rongliang:" << tt.capacity() << endl;

    // 复制多少个元素到目标容器
    copy_n(vec.begin(), 10, tt.begin());

    for (auto a : tt)
    {
        cout << a << endl;
    }
    system("pause");
    return 0;
}