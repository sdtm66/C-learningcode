#include <iostream>
#include <stdio.h>
#include <string> //�ṩstring���ͱ���
#include <math.h>
using namespace std;
void bubble_sort(int *arr, int len);

int main(void)
{
    // ָ��Ķ�����ʹ��
    int a = 10;
    int *p = &a;
    cout << &a << endl;
    cout << p << endl;
    cout << "a=" << a << endl;
    cout << "*p=" << *p << endl;
    // ָ����ռ�ڴ�ռ�
    cout << "size of (int *): " << sizeof(p) << endl; // 64λ����ϵͳ��ָ��ռ8���ֽڣ�����ָ��������������
    //const
    const int *p2 = &a;       //����ָ�룺ָ��ָ���ֵ�����Ըģ�ָ���ָ����Ըģ�*p2=20 ���� p2=&b ��ȷ
    int *const p3 = &a;       // ָ�볣����ָ��ָ��Ĳ�ֵ���Ըģ�ָ���ָ�򲻿��Ըģ�*p3=20 ��ȷ�� p3=&b ����
    const int *const p4 = &a; // ָ��ָ��Ĳ�ֵ�����Ըģ�ָ���ָ��Ҳ�����Ըģ�*p3=20 ���� p3=&b ����
    //����ָ����������е�Ԫ��
    int i = 0;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p5 = arr1; //�����������������Ԫ�ص�ַ�ı�ʶ��
    cout << "����ָ���������ĵ�һ��Ԫ�أ�" << *p5 << endl;
    p5++; //��ָ�����ƫ��4���ֽڣ�ָ��������һԪ��
    cout << "����ָ���������ĵڶ���Ԫ�أ�" << *p5 << endl;
    for (p5 = arr1, i = 0; i < (sizeof(arr1) / sizeof(arr1[0])); p5++, i++)
    {
        cout << "����ָ���������ĵ�" << (i + 1) << "��Ԫ�أ�" << *p5 << endl;
    }
    // ð��������
    int arr2[] = {1, 3, 2, 5, 4, 6, 10, 8, 9, 7};
    bubble_sort(arr2, sizeof(arr2) / sizeof(arr2[0]));
    cout << "ð�����������arr2��Ԫ�����£�" << endl;
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
            if (arr[i] > arr[i + 1]) // ��������ֻ�轫������Ϊarr3[i] <arr3[i + 1]
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}