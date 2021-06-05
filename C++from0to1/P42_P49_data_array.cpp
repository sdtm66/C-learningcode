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
    int arr3[] = {2, 1, 4, 3, 5, 7, 8, 9, 6, 12, 10, 11};
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

    // 冒泡排序(升序排列)
    cout << endl;
    cout << "冒泡排序前数组arr3的元素如下：" << endl;
    for (i = 0; i < (sizeof(arr3) / sizeof(arr3[0])); i++)
        cout << arr3[i] << "; ";
    cout << endl;

    for (i = 0, j = 0; i < ((sizeof(arr3) / sizeof(arr3[0])) - j); i = 0, j++)
    {
        for (i = 0; i < ((sizeof(arr3) / sizeof(arr3[0])) - j - 1); i++)
        {
            if (arr3[i] > arr3[i + 1]) // 降序排列只需将条件改为arr3[i] <arr3[i + 1]
            {
                temp = arr3[i];
                arr3[i] = arr3[i + 1];
                arr3[i + 1] = temp;
            }
        }
    }

    cout << "冒泡排序后数组arr3的元素如下：" << endl;
    for (i = 0; i < (sizeof(arr3) / sizeof(arr3[0])); i++)
        cout << arr3[i] << "; ";
    cout << endl;

    //二维数组
    int arr4[][3] = {{1, 2, 3}, {4, 5, 6}};

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << arr4[i][j] << " ";
        }
        cout << endl;
    }

    cout << "arr4整个数组所占内存大小（单位：字节）为：" << sizeof(arr4) << endl;
    cout << "arr4数组一行元素所占内存大小（单位：字节）为：" << sizeof(arr4[0]) << endl;
    cout << "arr4数每个元素所占内存大小（单位：字节）为：" << sizeof(arr4[0][0]) << endl;
    cout << "arr4数每行的元素个数(列数)为：" << (sizeof(arr4[0]) / sizeof(arr4[0][0])) << endl;
    cout << "arr4整个数组的元素个数为：" << (sizeof(arr4) / sizeof(arr4[0][0])) << endl; //统计数组元素的个数
    cout << "arr4数组的首地址为：" << arr4 << endl;
    cout << "arr4数组第一个元素的地址为：" << &arr4[0][0] << endl;
    cout << "arr4数组第二个元素的地址为：" << &arr4[0][1] << endl; //与第一个元素相差int 4个字节
    cout << "arr4数组第二列首元素的地址为：" << &arr4[1][0] << endl;

    // 二维数组案例：打印三个总成绩
    int arr5[][3] = {{91, 92, 93}, {94, 95, 96}, {97, 98, 99}};
    int sum;
    string names[] = {"张三", "李四", "王五"};

    for (i = 0; i < 3; i++)
    {
        sum = 0;
        for (j = 0; j < 3; j++)
        {
            sum += arr5[i][j];
        }
        cout << names[i] << "的总成绩为" << sum << endl;
    }
    return 0;
}