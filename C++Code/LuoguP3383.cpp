#include <iostream>
#include <cstring>
using namespace std;
constexpr int MAX = 1e6+10;
bool is_sushu[MAX];
int arr[MAX];
int Oula_Shai(int n)
{
    int res = 0;
    for(int i = 2;i<=n;i++)
    {
        if(is_sushu[i])
           { arr[res++] = i;}
            for(int j = 0;j<res&&i*arr[j]<=n;j++)
            {
                is_sushu[i*arr[j]] = false;
                if(i%arr[j]==0){break;}
            }
    }
    return res;
}
int main()
{
    memset(is_sushu,true,sizeof(is_sushu));
    int n;
    scanf("%d",&n);
    int cnt = Oula_Shai(n);
    for(int i = 0;i<cnt;i++)
    {
        printf("%d\n",arr[i]);
    }
    system("pause");
    return 0;
}