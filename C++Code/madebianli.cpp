#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int map[405][405];
bool vis[405][405];
struct Node{
    int x,y;
    int step;
};
int n,m;
int x,y;
const int dx[8]={-1,-2,-2,-1,1,2,2,1};
const int dy[8]={2,1,-1,-2,2,1,-1,-2};//8个方向
queue<Node>q;
void BFS()
{
    while(!q.empty())
    {
        Node temp = q.front();
        q.pop();
        for(int i = 0;i<8;i++)
        {
            int bx = temp.x + dx[i];
            int by = temp.y + dy[i];
            if(bx>=1&&bx<=n&&by>=1&&by<=m&&map[bx][by]==-1)
            {
                map[bx][by] = temp.step+1;
               // vis[bx][by] = true;
               q.push(Node{bx,by,temp.step+1});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    memset(map,-1,sizeof(map));
    cin>>n>>m>>x>>y;
    map[x][y] = 0;  //起点0步就能到达
    q.push(Node{x,y,0});
    //vis[x][y] = true;
    BFS();
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}