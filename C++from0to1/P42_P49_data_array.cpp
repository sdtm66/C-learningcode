#include <iostream>
#include <stdio.h>
#include <string> //提供string类型变量
#include <math.h>
using namespace std;

//数组的特点：相同类型元素；连续内存储存；
int main(void)
{
    int arr1[5] = {1, 2, 3};                      //未初始化的值全为0
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //变长数组
    int i = 0;
    cout << "数组arr1的元素如下：" << endl;
    for (i = 0; i < 5; i++)
        cout << arr1[i] << endl;
    // 一维数组名的用途
    cout << "arr1整个数组所占内存大小（单位：字节）为：" << sizeof(arr1) << endl;        //统计整个数组在内存中的长度
    cout << "arr1数组单个元素所占内存大小（单位：字节）为：" << sizeof(arr1[0]) << endl; //单个元素所占内存
    cout << "arr1整个数组的元素个数为：" << (sizeof(arr1) / sizeof(arr1[0])) << endl;    //统计数组元素的个数
    cout << "arr1数组的首地址为：" << arr1 << endl;
    cout << "arr1数组第一个元素的地址为：" << &arr1[0] << endl;
    cout << "arr1数组第二个元素的地址为：" << &arr1[1] << endl; //与第一个元素相差int 4个字节

    // 一维数组元素逆置
    int start = 0;
    int end = (sizeof(arr2) / sizeof(arr2[0])) - 1;
    int temp = arr2[start];
    int j = 0;

    cout << "逆置前数组arr2的元素如下：" << endl;
    for (i = 0; i < (sizeof(arr2) / sizeof(arr2[0])); i++)
        cout << arr2[i] << "; ";
    cout << endl;

    for (j = 0; ((start + j) != (end - j)) && ((start + j) < (end - j)); j++)
    {
        temp = arr2[start + j];
        arr2[start + j] = arr2[end - j];
        arr2[end - j] = temp;
    }

    cout << "逆置后数组arr2的元素如下：" << endl;
    for (i = 0; i < (sizeof(arr2) / sizeof(arr2[0])); i++)
        cout << arr2[i] << "; ";

    return 0;
}