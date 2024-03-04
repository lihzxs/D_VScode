#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 1e5+10;
bool is_sushu[MAX];
int result[MAX];
int arr[MAX];
int Init(int *arr,int len)
{
    int cnt = 0;
   for(int i = 1;i<=len;i++)
   {
        if(is_sushu[arr[i]]==true)
        {
            result[cnt++] = arr[i];
        }
        for(int j = 0;j<cnt;j++)
        {
            is_sushu[i*result[j]] = false;
            if(i%result[j]==0) break;
        }
   }
   return cnt;
}
int main()
{
    int n;
    scanf("%d",&n);
    memset(is_sushu,true,sizeof(is_sushu));
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int cnt = Init(arr,n);
    for(int i = 0;i<cnt;i++)
    {
        printf("%d ",result[i]);
    }
    system("pause");
    return 0;
}