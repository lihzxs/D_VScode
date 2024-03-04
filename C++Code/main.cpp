#include <iostream>
#include <functional>
#include <algorithm>
#include <numeric>
using namespace std;
/*
    快速排序算法
*/
void quickly_Sort(int arr[],int begin,int end)
{
    if(begin>=end) return ;
    int left = begin;
    int right = end-1;
    int temp = arr[left];  //临时变量先保存基准数
    while(left<right)
    {
        //什么时候右指针移动？当arr[right]>=temp时，right--
        while(left<right&&arr[right]>=temp)
        {
            right--;
        }
        if(left<right) arr[left] = arr[right];
        //什么时候左指针移动？当arr[left]<=temp时，left++
        while(left<right&&arr[left]<=temp)
        {
            left++;
        }
        if(left<right) arr[left] = arr[right];
    }
    if(left == right) arr[left] = arr[right] = temp;
    quickly_Sort(arr,0,right);
    quickly_Sort(arr,left+1,end);
}        
int main()
{
    int arr[10] = {10,9,8,7,6,5,4,3,2,1};
    quickly_Sort(arr,0,10);
    for_each(arr,arr+10,[](int &x){cout<<x<<" ";});
    cout<<endl;
    //remove 算法函数：
    /*remove(arr,arr+10,2);
    for_each(arr,arr+sizeof(arr)/sizeof(arr[0]),[](int x){cout<<x<<endl;});*/
    /*replace(arr,arr+10,10,1000);
    for(int i = 0;i<10;i++)
    {
        cout<<arr[i]<<endl;
    }
    replace_if(arr,arr+10,[](int &x){return x%2==0;},2000);
    for(int i = 0;i<10;i++)
    {
        cout<<arr[i]<<endl;
    }*/
    //累加算法
    int sum = accumulate(arr,arr+10,0);
    cout<<"sum = "<<sum<<endl;
    
    system("pause");
    return 0;
}