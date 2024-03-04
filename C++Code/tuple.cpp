#include <iostream>
#include <tuple>
using namespace std;
/*
    C++11元组的使用：
    元组可以理解为结构体，，，里面存放不同的类型，，且有多个
    和Python中的元组不一样的是，C++元组里面的每一个元素不是const
    可以修改，，，Python的是只读
    当函数返回多个值时，，可以使用元组tuple
*/
//函数返回一个tuple对象
tuple<string,int,double> Func()
{
    return make_tuple("Hello",100,90.999);
}
int main()
{
    //创建tuple对象  make_tuple(参数)
    tuple<int,char,string,double>first = make_tuple(10,'a',"hello World",3.14);

    //输出tuple对象的元素  get<下标>(哪个tuple对象)
    cout<<get<0>(first)<<endl;
    get<0>(first) = 1000;
    //可以修改
    cout<<get<0>(first)<<endl;

    //获取tuple对象的大小  <>里面是类型，，
    //所以需要decltype推导First的类型
    //如果直接写tuple，，哪个对象？不知道
    int size = tuple_size<decltype(first)>::value;
    cout<<"first size = "<<size<<endl;

    //接受函数返回的tuple对象
    tuple<string,int,double> second = Func();
    cout<<get<0>(second)<<endl;
    cout<<get<1>(second)<<endl;
    cout<<get<2>(second)<<endl;
    
    //拷贝构造
    tuple<string,int,double>flage(second);

    int ff_size = tuple_size<decltype(flage)>::value;
    cout<<"ff_size = "<<ff_size<<endl;

    //解包元组，把元组里的每个元素输出到变量里  tie
    string str = "";
    int a;
    double d;
    tie(str,a,d) = flage;
    cout<<"str = "<<str<<" a = "<<a<<" d = "<<d<<endl;
    system("pause");
    return 0;
}