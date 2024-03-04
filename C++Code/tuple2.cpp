#include <iostream>
#include <tuple>
using namespace std;
int main()
{
    //创建tuple对象
    tuple<string,int,string>t1("Hello",100,"World");
    tuple<string,int,string>t2(make_tuple("liu",200,"meng"));
    tuple<string,int,string>t3(t1);

    //输出元素 get<下标>(哪个tuple对象)
    cout<<get<0>(t1)<<" "<<get<1>(t1)<<" "<<get<2>(t1)<<endl;

    //获取tuple对象的大小 tuple_size<tuple对象的类型>::value
    int size = tuple_size<decltype(t1)>::value;
    cout<<"t1 size = "<<size<<endl;

    //把tuple对象里面的元素输出到变量里面  tie(变量名1，2,3) = tuple对象
    string str1,str2;
    int num;
    tie(str1,num,str2) = t1;
    cout<<"str1 = "<<str1<<" num = "<<num<<" str2 = "<<str2<<endl;

    //元组的比较
    if(t1 == t3)
    {
        cout<<"t1 == t3"<<endl;
    }
    else {
        cout<<"t1 != t3"<<endl;
    }

    //元组的拼接
    auto sumtuple = tuple_cat(t1,t2);
    cout<<"sum_size = "<<tuple_size<decltype(sumtuple)>::value<<endl;
    system("pause");
    return 0;
}