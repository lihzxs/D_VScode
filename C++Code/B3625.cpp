#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1000001;
bool vis[MAX];
int arr[MAX];
int xx[]={-1,1,};
int n;
struct Node{
    int x,step;
};
queue<Node>q;
int BFS()
{
    while(!q.empty())
    {
        Node temp = q.front();
        q.pop();
        if(temp.x == n)
        {
            return temp.step;
        }
    }
}
int main()
{
    cin>>n;
    q.push(Node{1,0});
    vis[1] = true;
    int result = BFS();
    cout<<result<<endl;
    system("pause");
    return 0;
}