#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
using namespace std;
int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int sum = accumulate(arr,arr+10,100);
    cout<<"sum = "<<sum<<endl;
    vector<int>vec{2,4,6,8,10};
    vector<int>t;
    t.resize(10+vec.size());
    cout<<vec.size()<<endl;
    //容器合并算法，，两个容器有序
    merge(arr,arr+10,vec.begin(),vec.end(),t.begin());
    for(auto a : t)
    {
        cout<<a<<endl;
    }
    cout<<"**********************\n";
    vector<int>vv;
    vv.resize(10);
    //容器的元素搬运
    transform(arr,arr+10,vv.begin(),[](int &x){return x;});
    for(auto a : vv)
    {
        cout<<a<<endl;
    }
    cout<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
    list<int>l;
    srand((unsigned int)time(NULL));
    for(int i = 0;i<10;i++)
    {
        l.push_back(rand()%100);
    }
    for(auto a : l)
    {
        cout<<a<<endl;
    }
    //lower_bound
    int index = (lower_bound(arr,arr+10,11)-arr);
    cout<<"index = "<<index<<endl;
    //upper_bound
    int index2 = (upper_bound(arr,arr+10,10)-arr);
    cout<<"index2 = "<<index2<<endl;
    //binary_search:
    bool b = binary_search(arr,arr+10,10);
    cout<<"b = "<<b<<endl;
    
    system("pause");
    return 0;
}