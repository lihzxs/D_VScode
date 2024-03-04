#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int xx[] = {1,-1,0,0};
int yy[] = {0,0,1,-1};
int n,m,S_x,S_y,T_x,T_y;
int ss_x,ss_y;
char map[51][51];
bool vis[51][51];
struct Node
{
    int x;
    int y;
    int step;
};
queue<Node>q;
int BFS_One()
{
    while(!q.empty())
    {
        Node temp = q.front();
        q.pop();
        if(temp.x == T_x&& temp.y == T_y)
        {
            return temp.step;
        }
        for(int i = 0;i<4;i++)
        {
            int bx = xx[i] + temp.x;
            int by = yy[i] + temp.y;
            if(map[bx][by] =='1') continue;
            if(bx<0||bx>=n||by<0||by>=m) continue;
            if(vis[bx][by]) continue;
            q.push(Node{bx,by,temp.step+1});
            vis[bx][by] = true;
        }
    }
    return -1;
}
int BFS_Two()
{
    while(!q.empty())
    {
        Node temp = q.front();
        q.pop();
        if(temp.x == ss_x&& temp.y == ss_y)
        {
            return temp.step;
        }
        for(int i = 0;i<4;i++)
        {
            int bx = xx[i] + temp.x;
            int by = yy[i] + temp.y;
            if(map[bx][by] =='1') continue;
            if(bx<0||bx>=n||by<0||by>=m) continue;
            if(vis[bx][by]) continue;
            q.push(Node{bx,by,temp.step+1});
            vis[bx][by] = true;
        }
    }
    return -1;
}
int main()
{
    cin>>n>>m;
    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>map[i][j];
            if(map[i][j] == 'S')  //起点
            {
                S_x = i,S_y = j;
            }
            if(map[i][j] == 'T') //先找T位置
            {
                T_x = i,T_y = j;
            }
            if(map[i][j] == 'E') //从T位置找E位置
            {
                ss_x = i,ss_y = j;
            }
        }
    }
    vis[S_x][S_y] = true;
    q.push(Node{S_x,S_y,0});
    int result_one = BFS_One();
    //cout<<result_one<<endl;

    memset(vis,0,sizeof(vis));
    while(!q.empty()) q.pop();
    
    vis[T_x][T_y] = true;
    q.push(Node{T_x,T_y,0});
    int result_two = BFS_Two();
    //cout<<result_two<<endl;
    int result = result_one+result_two;
    cout<<result<<endl;
    system("pause");
    return 0;
}