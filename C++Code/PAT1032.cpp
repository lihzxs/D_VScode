#include <iostream>
#include <map>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int n;
    map<int,int>mp;
    cin>>n;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        mp[x] = mp[x] + y;
    }
    int i = 0,j = 0;
    for(auto a : mp)
    {
        if(a.second>j)
        {
            j = a.second;
            i = a.first;
        }
    }
    cout<<i<<" "<<j<<endl;
    system("pause");
    return 0;
}