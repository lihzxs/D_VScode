#include <iostream>
#include <cstring>
using namespace std;
bool issushu[101];
int arr[101];
int main()
{
    int j = 0;
    memset(issushu, true, sizeof(issushu));
    //埃氏筛素数法
    for (int i = 2; i <= 100; i++)
    {
        if (issushu[i])
        {
            arr[j++] = i;
        }
        //筛掉是素数那个数的倍数
        for (int j = i; j <= 100; j += i)
        {
            issushu[j] = false;
        }
    }

    for (int k = 0; k < j; k++)
    {
        cout << arr[k] << endl;
    }
    system("pause");
    return 0;
}