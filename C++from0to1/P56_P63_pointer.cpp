#include <iostream>
#include <stdio.h>
#include <string> //提供string类型变量
#include <math.h>
using namespace std;
void bubble_sort(int *arr, int len);

int main(void)
{
    // 指针的定义与使用
    int a = 10;
    int *p = &a;
    cout << &a << endl;
    cout << p << endl;
    cout << "a=" << a << endl;
    cout << "*p=" << *p << endl;
    // 指针所占内存空间
    cout << "size of (int *): " << sizeof(p) << endl; // 64位操作系统，指针占8个字节，无论指向哪种数据类型
    //const
    const int *p2 = &a;       //常量指针：指针指向的值不可以改，指针的指向可以改；*p2=20 错误， p2=&b 正确
    int *const p3 = &a;       // 指针常量：指针指向的不值可以改，指针的指向不可以改；*p3=20 正确， p3=&b 错误
    const int *const p4 = &a; // 指针指向的不值不可以改，指针的指向也不可以改；*p3=20 错误， p3=&b 错误
    //利用指针访问数组中的元素
    int i = 0;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p5 = arr1; //数组名就是数组的首元素地址的标识符
    cout << "利用指针访问数组的第一个元素：" << *p5 << endl;
    p5++; //让指针向后偏移4个字节，指向数组下一元素
    cout << "利用指针访问数组的第二个元素：" << *p5 << endl;
    for (p5 = arr1, i = 0; i < (sizeof(arr1) / sizeof(arr1[0])); p5++, i++)
    {
        cout << "利用指针访问数组的第" << (i + 1) << "个元素：" << *p5 << endl;
    }
    // 冒泡排序函数
    int arr2[] = {1, 3, 2, 5, 4, 6, 10, 8, 9, 7};
    bubble_sort(arr2, sizeof(arr2) / sizeof(arr2[0]));
    cout << "冒泡排序后数组arr2的元素如下：" << endl;
    for (i = 0; i < (sizeof(arr2) / sizeof(arr2[0])); i++)
        cout << arr2[i] << "; ";
    cout << endl;
    return 0;
}

void bubble_sort(int *arr, int len)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    for (i = 0, j = 0; i < (len - j); i = 0, j++)
    {
        for (i = 0; i < (len - j - 1); i++)
        {
            if (arr[i] > arr[i + 1]) // 降序排列只需将条件改为arr3[i] <arr3[i + 1]
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}