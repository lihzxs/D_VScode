#include <iostream>

using namespace std;
constexpr int MAXN = 10001;

int arr[MAXN];
bool isprime[MAXN];
int cnt;
void Test(int n)
{
    // 线性时间复杂度筛素数
    for (int i = 2; i <= n; i++)
    {
        if (!isprime[i]) // 是素数
        {
            arr[cnt++] = i;
        }
        // 无论这个数是不是素数，，都要筛掉与已经是素数的乘积
        for (int j = 0; j < cnt && arr[j] * i <= n; j++)
        {
            isprime[arr[j] * i] = true;
            if (i % arr[j] == 0)
                break;
        }
    }
}

bool isprimenum(int num)
{
    if (num < 2)
        return false;
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
int main()
{
    Test(100);
    for (int i = 0; i < cnt; i++)
    {
        cout << arr[i] << endl;
    }

    cout << "-----------------------------------" << endl;

    for (int i = 0; i <= 100; i++)
    {
        if (isprimenum(i))
        {
            cout << i << endl;
        }
    }
    system("pause");
    return 0;
}