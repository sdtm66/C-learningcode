#include <iostream>
#include <stdio.h>
#include <string> //提供string类型变量
using namespace std;
// 宏常量
#define Day 7

int main(void)
{
    /* 变量声明 */
    const int month = 12; //const修饰变量=常量
    short num1 = 10;
    int num2;
    long num3 = 10;
    long long num4 = 10;
    float num5;
    double num6 = 10.3;
    char num7 = 'a';
    char num8[] = "abcd";
    string num9 = "abcd";
    bool num10 = true;
    /* 获取输入 */
    cout << "请给整形变量num2赋值：" << endl;
    cin >> num2;
    printf("请给浮点类型变量num5赋值:\n");
    scanf("%f", &num5);
    /* 打印输出 */
    cout << "num1=" << num1 << ". the storage of short is " << sizeof(num1) << " bytes" << endl;
    cout << "num2=" << num2 << ". the storage of int is " << sizeof(num2) << " bytes" << endl;
    cout << "num3=" << num3 << ". the storage of long is " << sizeof(num3) << " bytes" << endl;
    cout << "num4=" << num4 << ". the storage of long long is " << sizeof(num4) << " bytes" << endl;
    cout << "num5=" << num5 << ". the storage of float is " << sizeof(num5) << " bytes" << endl;
    cout << "num6=" << num6 << ". the storage of double is " << sizeof(num6) << " bytes" << endl;
    cout << "num7=" << num7 << ". the storage of char is " << sizeof(num7) << " bytes."
         << " The ASCII code of it is " << (int)num7 << endl;
    cout << "num8=" << num8 << ". the storage of char array is " << sizeof(num8) << " bytes" << endl;
    cout << "num9=" << num9 << ". the storage of string is " << sizeof(num9) << " bytes" << endl;
    cout << "num10=" << num10 << ". the storage of bool is " << sizeof(num10) << " bytes" << endl;
    cout << "One week has " << Day << " days. One year has " << month << " months" << endl; //打印方法1
    printf("One week has %d days. One year has %d months\n", Day, month);                   //打印方法2
    system("pause");
    return 0;
}
