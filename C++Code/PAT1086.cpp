#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int sum = n*m;
    int s = 0;
    while(sum)
    {
        int num = sum % 10;
        s = s * 10 + num;
        sum = sum/10; 
    }
    cout<<s<<endl;
    system("pause");
    return 0;
}