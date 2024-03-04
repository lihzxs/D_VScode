#include <iostream>
#include <vector>
using namespace std;
int arr[10] = {10,2,9,34,22,12,33,90,66,55};
//每个桶内进行快速排序
void Quickly_Sort(vector<int>&arr,int begin,int end)
{
    if(begin>=end) return;
    int l = begin,r = end -1;
    int temp = arr[l];  //基准数
    while(l<r)
    {
        while(l<r&&arr[r]>=temp) r--;
        if(l<r) arr[l] = arr[r];
        while(l<r&&arr[l]<=temp) l++;
        if(l<r) arr[r] = arr[l];
    }
    if(l == r) arr[l] = arr[r] = temp;
    Quickly_Sort(arr,0,r);
    Quickly_Sort(arr,l+1,end);
}
int main()
{
    vector<int>vec[3];  //分配三个桶
    //每个元素分配到对应的桶，保证后一个桶的所有元素比前一个桶的所有元素大
    for(int i = 0;i<10;i++)
    {
        if(arr[i]>=0&&arr[i]<=9) vec[0].push_back(arr[i]);
        else if(arr[i]>=10&&arr[i]<=50) vec[1].push_back(arr[i]);
        else {
            vec[2].push_back(arr[i]);
        }
    }
    Quickly_Sort(vec[0],0,vec[0].size());
    for(int i = 0;i<vec[0].size();i++)
    {
        cout<<vec[0][i]<<" ";
    }
    Quickly_Sort(vec[1],0,vec[1].size());
    for(int i = 0;i<vec[1].size();i++)
    {
        cout<<vec[1][i]<<" ";
    }
    Quickly_Sort(vec[2],0,vec[2].size());
    for(int i = 0;i<vec[2].size();i++)
    {
        cout<<vec[2][i]<<" ";
    }
    system("pause");
    return 0;
}