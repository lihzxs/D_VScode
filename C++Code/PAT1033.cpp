#include <iostream>
using namespace std;
constexpr int MAX = 1e5+10;
int arr[MAX];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    int max = 0;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        arr[x]+=y;
        if(max<x){
            max = x;
        }
    }
    int MM = 0,j = 0;
    for(int i = 0;i<=max;i++)
    {
        if(arr[i]!=0&&arr[i]>MM){
            MM = arr[i];
            j = i;
        }
    }
    cout<<j<<" "<<MM<<endl;
    system("pause");
    return 0;
}