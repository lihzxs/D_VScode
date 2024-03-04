#include <iostream>
using namespace std;
bool vis[30];
int arr[30];
int n,m;
void DFS(int step)
{
    if(step == m+1)
    {
        for(int i = 1;i<step;i++)
        {
            printf("%3d",arr[i]);
        }
        printf("\n");
        return ;
    }
    for(int i = arr[step-1]+1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i] = true;
            arr[step] = i;
            DFS(step+1);
            vis[i] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    DFS(1);
    system("pause");
    return 0;
}