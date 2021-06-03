#include <iostream>
#include <stdio.h>
#include <string> //提供string类型变量
using namespace std;

int main(void)
{
    /* 变量声明 */
    int a = 6;
    int b = 3;
    bool flag_true = true;
    bool flag_false = false;
    /* 打印输出 */
    //算术运算符
    cout << "a + b =" << a + b << endl;
    cout << "a - b =" << a - b << endl;
    cout << "a * b =" << a * b << endl;
    cout << "a / b =" << a / b << endl;
    cout << "a % b =" << a % b << endl;
    cout << "++a=" << ++a << endl;
    cout << "--b =" << --b << endl;
    //赋值运算符
    a += 3;
    cout << "a += 3-->a = " << a << endl;
    a -= 3;
    cout << "a -= 3-->a = " << a << endl;
    a *= 3;
    cout << "a *= 3-->a = " << a << endl;
    a /= 3;
    cout << "a /= 3-->a = " << a << endl;
    //比较运算符
    cout << "a==b = " << (a == b) << endl;
    cout << "a!=b = " << (a != b) << endl;
    cout << "a>b = " << (a > b) << endl;
    cout << "a>=b = " << (a >= b) << endl;
    cout << "a<b = " << (a < b) << endl;
    cout << "a<=b = " << (a <= b) << endl;
    //逻辑运算符
    cout << "!true = " << (!flag_true) << endl;
    cout << "true && false = " << (flag_true && flag_false) << endl;
    cout << "true || false = " << (flag_true || flag_false) << endl;

    system("pause");
    return 0;
}