#include <iostream>
#include <stdio.h>
#include <string> //�ṩstring���ͱ���
#include <math.h>
using namespace std;

//������ص㣺��ͬ����Ԫ�أ������ڴ洢�棻
int main(void)
{
    int arr1[5] = {1, 2, 3};                      //δ��ʼ����ֵȫΪ0
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //�䳤����
    int i = 0;
    cout << "����arr1��Ԫ�����£�" << endl;
    for (i = 0; i < 5; i++)
        cout << arr1[i] << endl;
    // һά����������;
    cout << "arr1����������ռ�ڴ��С����λ���ֽڣ�Ϊ��" << sizeof(arr1) << endl;        //ͳ�������������ڴ��еĳ���
    cout << "arr1���鵥��Ԫ����ռ�ڴ��С����λ���ֽڣ�Ϊ��" << sizeof(arr1[0]) << endl; //����Ԫ����ռ�ڴ�
    cout << "arr1���������Ԫ�ظ���Ϊ��" << (sizeof(arr1) / sizeof(arr1[0])) << endl;    //ͳ������Ԫ�صĸ���
    cout << "arr1������׵�ַΪ��" << arr1 << endl;
    cout << "arr1�����һ��Ԫ�صĵ�ַΪ��" << &arr1[0] << endl;
    cout << "arr1����ڶ���Ԫ�صĵ�ַΪ��" << &arr1[1] << endl; //���һ��Ԫ�����int 4���ֽ�

    // һά����Ԫ������
    int start = 0;
    int end = (sizeof(arr2) / sizeof(arr2[0])) - 1;
    int temp = arr2[start];
    int j = 0;

    cout << "����ǰ����arr2��Ԫ�����£�" << endl;
    for (i = 0; i < (sizeof(arr2) / sizeof(arr2[0])); i++)
        cout << arr2[i] << "; ";
    cout << endl;

    for (j = 0; ((start + j) != (end - j)) && ((start + j) < (end - j)); j++)
    {
        temp = arr2[start + j];
        arr2[start + j] = arr2[end - j];
        arr2[end - j] = temp;
    }

    cout << "���ú�����arr2��Ԫ�����£�" << endl;
    for (i = 0; i < (sizeof(arr2) / sizeof(arr2[0])); i++)
        cout << arr2[i] << "; ";

    return 0;
}