#include <iostream>
using namespace std;
int n;
int arr[101];
int cnt = 0;
void DFS(int sum,int step)
{
    if(sum > n) return ; //1 1 1 1 1 1 2大于7，返回上一层
    if(sum == n)
    {
        cnt++;
        printf("%d=",n);
        for(int i = 1;i<=step-2;i++)  //7个1的时候，，step == 8
        {
            printf("%d+",arr[i]);
        }
        printf("%d\n",arr[step-1]);
        return ;
    }
    //1 0 0 0 0 0 0 0
    for(int i = arr[step-1];i<n;i++)
    {
        arr[step] = i;
        DFS(sum+i,step+1);
    }
}
int main()
{
    scanf("%d",&n);
    arr[0] = 1;
    DFS(0,1);
    printf("total=%d\n",cnt);
    system("pause");
    return 0;
}