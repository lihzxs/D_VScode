#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 105;
bool vis[MAXN][MAXN];
char map[MAXN][MAXN];
int n, m;
bool flage = false;
int xx[] = {0, 0, 1, -1};
int yy[] = {1, -1, 0, 0};
struct Node
{
    int x;
    int y;
};
queue<Node> q;
void BFS()
{
    while (!q.empty())
    {
        //取出队首元素
        Node temp = q.front();
        q.pop();
        //判断是否是终点？
        if (temp.x == n && temp.y == m)
        {
            flage = true;
            return;
        }

        //遍历邻接点

        for (int i = 0; i < 4; i++)
        {
            int bx = xx[i] + temp.x;
            int by = yy[i] + temp.y;
            //判断情况
            if (bx < 1 || bx > n || by < 1 || by > m)
                continue; //越界情况
            if (map[bx][by] == '#')
                continue; //墙壁
            if (vis[bx][by])
                continue; //已经被标记过了

            q.push(Node{bx, by});
            vis[bx][by] = true;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
        }
    }
    q.push(Node{1, 1});
    vis[1][1] = 1;
    BFS();
    cout << (flage ? "Yes\n" : "No\n");
    system("pause");
    return 0;
}