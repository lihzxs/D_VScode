#include <iostream>
#include <queue>
#include <cstring>
/*
    纯暴力法会TLE超时
    就是遍历所有的map[i][j]，，所有i，j作终点 
    每次重置vis数组，和清空队列
*/
using namespace std;
//马的行走方向
const int dx[8]={-1,-2,-2,-1,1,2,2,1};
const int dy[8]={2,1,-1,-2,2,1,-1,-2};
int map[405][405];//map[i][j]表示保存马走到这一点i，j的最短距离
bool vis[405][405];
struct Node{
    int x,y;
    int step;
};
int n,m,x,y;
queue<Node>q;
void BFS(){
    while(!q.empty())
    {
        Node temp = q.front();
        q.pop();
        for(int i = 0;i<8;i++)
        {
            int bx = temp.x + dx[i];
            int by = temp.y + dy[i];
            //遍历马走的点，，满足条件，，就map[bx][by] = 上一点加一
            if(bx>=1&&bx<=n&&by>=1&&by<=m&&map[bx][by]==-1) { map[bx][by] = temp.step+1;
            q.push(Node{bx,by,temp.step+1});}
        }
    }
}
int main()
{
    scanf("%d %d %d %d",&n,&m,&x,&y);
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            map[i][j] = 0;
        }
    }
    //先将map全都初始化为-1
    memset(map,-1,sizeof(map));
    map[x][y] = 0;//起点为0步
    q.push(Node{x,y,0});
    BFS();
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    system("pause");
    //while(1);
    return 0;
}