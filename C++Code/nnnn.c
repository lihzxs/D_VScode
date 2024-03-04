#include <stdio.h>
#include <Windows.h>
#include <string.h>
#define MAIN 
void Func(int arr[],int len)
{
    //printf("Func sizeof(arr) = %d\n",sizeof(arr));
    arr[0] = 100000;
}
void Display();
int main()
{
    #if 0
    int *p = (int*)malloc(sizeof(int)*10);
    for(int i = 0;i<10;i++)
    {
        p[i] = i+1;
    }
    for(int i = 0;i<10;i++)
    {
        printf("%d\n",p[i]);
    }
    printf("sizeof(p) = %d\n",sizeof(p));
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    printf("main sizeof(arr) = %d\n",sizeof(arr));
    Func(arr,10);
    printf("arr[0] = %d\n",arr[0]);
    free(p);
    #endif
    //指针的const
#if 0
    地址是const  *号在const前面，，指向的值是const，在后面
    int a = 100;
    int b = 200;
    const int *const q =&a;  
    q = &b;      error
    *q = 20000;  error
    数组本质上就是int *const 的指针，，arr1 = arr2   //错误
#endif
#if 0
    //C语言的字符串操作
    const char *c = "Hello World";
    printf("sizeof(c) = %d\n",sizeof(c));
    printf("%s\n",c);
    char str1[10]="helloworl";  //末尾的\0也算一个字符
    printf("str1 = %s\n",str1);
    printf("sizeof(str1) = %d\n",sizeof(str1));
    char str2[2] = "d";
    printf("str2 = %s\n",str2);
    printf("sizeof(str2) = %d\n",sizeof(str2));
    int len1 = strlen(str1),len2 = strlen(str2);
    printf("len1 = %d,len2 = %d\n",len1,len2);
    char str3[20]="";
    int compare = strcmp(str1,str2);
    printf("compare = %d\n",compare);
    strcat(strcat(str3,str1),str2);
    printf("str3 = %s\n",str3);
#endif

#ifndef MAIN
    //函数指针
    typedef void (*pp)();
    pp ppp = Display;
    (*ppp)();
#endif
#ifdef MAIN
    //指针数组
    int *p[10];  //是一个数组，，每个元素是int *
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    //每个int*指向数组arr每个单元的地址
    for(int i = 0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        p[i] = &arr[i];
    }
    //用指针数组对arr的值进行修改
    for(int i = 0;i<10;i++)
    {
        *p[i] = 10;
    }
    //打印结果
    for(int i = 0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        printf("arr[%d] = %d\n",i,arr[i]);
    }
    printf("******************************\n");
    //数组指针  pp是一个指针，，指向一个长度为10 的数组
    int (*pp)[10] = &arr;
    //(*pp)是什么   ： 是arr
    for(int i = 0;i<10;i++)
    {
        (*pp)[i] *=10;
    }
    for(int i = 0;i<10;i++)
    {
        printf("(*pp)[%d] = %d\n",i,(*pp)[i]);
    }
#endif
    
    system("pause");
    //while(1);
    return 0;
}
void Display(){
    printf("**********************\n");
}