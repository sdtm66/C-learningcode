// 引用的基本使用：给变量起别名：语法： 数据类型 &别名 = 原名;
//注意事项：引用必须初始化；引用在初始化后，不可以改变；
//引用的本质：在c++内部是一个指针常量
//
//

#include <iostream>
#include <string>
using namespace std;
//引用做函数参数:函数传参时，可以利用引用的技术让形参修饰实参，可以简化指针修改实参
//值传递
void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
//地址传递
void swap2(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
//引用传递
void swap3(int &a, int &b) //工作机理:发现是引用，转换为 int * const a = 实参的地址，int * const b = 实参的地址；
{
    int temp = a;
    a = b;
    b = temp;
}

//引用作为函数的返回值，注意事项：不要返回局部变量引用（类似于不要返回局部变量的指针，因为局部变量在函数结束时，其地址会被释放）
//函数的调用可以作为左值；
//返回局部变量引用
int &test()
{
    int a = 10; //局部变量存放在栈区
    return a;
}
//返回静态变量引用
int &test2()
{
    static int a = 100; //静态变量存放在全局区，函数调用结束后，地址不会被释放，会一直保留至程序结束由系统将其释放
    return a;
}
//常量引用：修饰形参，防止误操作；在函数形参列表中，可以加const修饰形参，防止形参改变实参
//未使用常量引用
void showval(int &a)
{
    a = 900;
    cout << "值等于" << a << endl;
}
//使用常量引用
void showval2(const int &a)
{
    //a = 900;会报错，不可以修改a的值，因为a是常量引用
    cout << "值等于" << a << endl;
}

int main(void)
{
    int a = 10;
    int d = 30;
    //内部工作机理：自动转换成 int * const b = &a
    int &b = a; //b引用a，两者标识同一对象（同一内存）
    //int &c;//错误，引用必须初始化
    int &c = a; //一旦初始化后，就不可以更改；
    //int &c = d; //错误操作，初始化后的引用不可以更改被引对象；
    cout << "c=" << c << endl;
    c = d; //这是赋值操作，不是更改引用
    cout << "c=" << c << endl;
    b = 20; //内部自动转换为*b=20；
    cout << "a=" << a << endl;
    //引用做函数参数
    int a1 = 10;
    int b1 = 20;
    swap(a1, b1); //值传递，形参不会修饰实参，传递的是值，函数内部创建局部变量，局部变量交换了值，函数外部的值并没有交换
    cout << "a1=" << a1 << ";b1=" << b1 << endl;
    swap2(&a1, &b1); //地址传递，形参修饰实参，传递的是地址，地址上的值交换
    cout << "a1=" << a1 << ";b1=" << b1 << endl;
    a1 = 10;
    b1 = 20;
    //内部工作机理：自动转换成 int * const a = &a1, int * const b = &b1;指针常量是指针指向不可改（也说明了为什么引用不可以改），但指向的内存里的值可以改
    swap3(a1, b1); //引用传递：形参会修饰实参，函数形参是实参的别名，和实参指向同一内存，所以此时的形参值发生改变，相当于同一地址上的实参值发生改变
    cout << "a1=" << a1 << ";b1=" << b1 << endl;
    //引用作为函数的返回值
    int &ref1 = test2();
    cout << "ref1=" << ref1 << endl;
    test2() = 200; //函数的调用可以作为左值,因为test2()调用后返回静态变量a的引用：即ref1，所以test2() = 200;相当于ref1=200;
    cout << "ref1=" << ref1 << endl;
    //int &ref = test();
    //cout << "ref=" << ref << endl;
    //常量引用
    const int &e = 10; //编译器将代码修改为 int temp =10；const int &e = temp；加入const后变为只读引用，不可修改所引用的内存里的值
    int f = 300;
    showval2(f);
    showval(f);

    return 0;
}