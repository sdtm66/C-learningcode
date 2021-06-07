// 内存分区模型：
//程序运行前分为全局区和代码区
// （1）代码区：存放函数体的二进制代码，由操作系统进行管理；存放CPU执行的机器中指令。代码区是共享和只读的。
// （2）全局区：存放全局变量和静态变量，该区域的数据在程序结束后由操作系统释放；常量区存放const修饰的全局常量、字符串常量
//程序运行后
// （3）栈区：由编译器自动分配释放，存放函数的参数值和局部变量。注意事项：不要返回局部变量的地址，栈区开辟的数据由编译器自动释放
// （4）堆区：由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收。在c++中主要利用new在堆区开辟内存；堆区开辟的数据，释放利用操作符delect
#include <iostream>
#include <string>
#define MAX 10;
using namespace std;

int g_a = 10;       //全局变量，存放在全局区
int g_b = 10;       //全局变量，存放在全局区
const int c_a = 10; //const修饰的全局常量，存放在全局区

int *func(int b) //形参也会放在栈区
{
    int a = 10; //函数内部的局部变量，存放在栈区，栈区的数据在函数执行完成后自动释放
    return &a;  // 非法操作：返回局部变量的地址，该数据不会被接收到
}

int *func2()
{
    //利用new关键字，可以将数据开辟到堆区；new的基本语法：new 数据类型（数据），返回该数据类型的指针
    //指针本质也是局部变量，放在栈上，指针保存的数据是放在堆区
    int *a1 = new int(200);
    cout << "指针的地址：" << &a1 << endl; //指针本质也是局部变量，放在栈上
    cout << "堆区：" << endl;
    cout << "指针指向的数据的地址：" << &(*a1) << endl; //指针保存的数据是放在堆区
    return (a1);
}

int *func3()
{
    //堆区开辟数组
    int *arr = new int[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = 100 + i;
    }
    return (arr);
}

int main(void)
{
    const int c_b = 10;  //const修饰的局部常量，存放在代码区
    static int s_a = 10; //静态变量
    int a = 10;          //局部变量,存放在代码区
    int b = 10;          //局部变量,存放在代码区
    cout << "全局区：" << endl;
    cout << "g_a的地址是" << &g_a << endl;
    cout << "g_a的地址是" << &g_b << endl;
    cout << "s_a的地址是" << &s_a << endl;
    cout << "全局区之常量区：" << endl;
    cout << "c_a的地址是" << &c_a << endl;
    cout << "字符串常量的地址是" << &"hello world" << endl; //字符串常量，存放在全局区
    cout << "代码区：" << endl;
    cout << "c_b的地址是" << &c_b << endl;
    cout << "a的地址是" << &a << endl;
    cout << "b的地址是" << &b << endl;
    // 堆区示例
    int *bb = func2();
    cout << *bb << endl;
    cout << *bb << endl;
    delete bb;
    cout << *bb << endl;
    int *cc = func3();
    for (int i = 0; i < 10; i++)
    {
        cout << cc[i] << endl;
    }
    delete[] cc;
    for (int i = 0; i < 10; i++)
    {
        cc[i] = 100 + i;
    }
    //堆区数据由程序员开辟与释放
    //栈区示例
    int *aa = func(10);
    cout << *aa << endl;
    cout << *aa << endl;

    return 0;
}