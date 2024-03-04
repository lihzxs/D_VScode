#include <iostream>
#include <queue>
using namespace std;
pair<int,int>pr;  //保存路径
int maze[5][5];
bool vis[5][5];
int xx[] = {1,-1,0,0};
int yy[] = {0,0,1,-1};
struct Node
{
    int x,y;
    int step;
};
queue<Node>q;
int BFS()
{
    while(!q.empty())
    {
        Node temp = q.front();
        q.pop();
        if(temp.x == 4&&temp.y==4){
            return temp.step;
        }
        for(int i = 0;i<4;i++)
        {
            int nx = temp.x+xx[i];
            int ny = temp.y+yy[i];
            if(nx>4||nx<0||ny>4||ny<0) continue;
            if(vis[nx][ny]||maze[nx][ny]==1) continue;
            q.push(Node{nx,ny,temp.step+1});
            vis[nx][ny] = true;
        }
    }
    return -1;
}

int main()
{
    for(int i = 0;i<5;i++)
    {
        for(int j = 0;j<5;j++)
        {
            cin>>maze[i][j];  //输入地图数据
        }
    }
    q.push(Node{0,0,0});
    vis[0][0] = true;//标记起点
    int result = BFS();
    cout<<"result = "<<result<<endl;
    system("pause");
    return 0;
}