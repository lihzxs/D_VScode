#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 1e8 + 10;
bool is_sushu[MAX];
int arr[MAX];
/*
    欧拉筛法：
    O(n)时间复杂度筛素数
*/
int Init(int n)
{
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (is_sushu[i])
            arr[cnt++] = i;
        //无论i是不是素数，，都要筛掉i与已经是素数的乘积
        for (int j = 0; j < cnt && i * arr[j] <= n; j++)
        {
            is_sushu[i * arr[j]] = false;
            if (i % arr[j] == 0)
                break; //确保是最小的倍数筛掉
        }
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    int m;
    memset(is_sushu, true, sizeof(is_sushu));
    cin >> n;
    int cnt = Init(n);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        cout << arr[num - 1] << endl;
    }
    system("pause");
    return 0;
}