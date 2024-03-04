#include <iostream>
#include <vector>
#include <algorithm>
/*
    unique去重算法：
    /*
首先，std::unique函数在vec容器的[vec.begin(), 
vec.end())范围内查找相邻的重复元素，
并删除这些元素，只保留第一个元素。
返回值是删除元素的最后一个位置的下一个位置的迭代器。
然后，vec.erase函数从返回的迭代器开始到vec.end()的位置，
删除剩下的元素，直到容器的末尾。
综上，vec.erase(std::unique(vec.begin(), vec.end()),
 vec.end())这一行代码是删除vec容器中重复的元素，
实现去重的操作。

std::unique(first, last)
其中，first表示要消除重复元素的数组或容器的第一个元素，
last表示最后一个元素的下一位。
该函数将重复元素移动到数组或容器的末尾，
并返回指向不重复元素的最后一个元素的迭代器。
*/
using namespace std;
int main()
{
    vector<int>vec{1,2,2,3,4,4,4,6,9,10,10};
    cout<<"vec.size = "<<vec.size()<<endl;
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for(auto a : vec)
    {
        cout<<a<<endl;
    }
    cout<<"vec.size = "<<vec.size()<<endl;
    cout<<"vec.capacity = "<<vec.capacity()<<endl;

    //内存收缩，，使得size和capacity相等
    //避免内存空间的浪费
    vector<int>(vec).swap(vec);
    //或者
    vec.shrink_to_fit();
    cout<<"vec.capacity = "<<vec.capacity()<<endl;
    system("pause");
    return 0;
}