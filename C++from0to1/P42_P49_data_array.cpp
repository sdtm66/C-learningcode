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
    int arr3[] = {2, 1, 4, 3, 5, 7, 8, 9, 6, 12, 10, 11};
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

    // ð������(��������)
    cout << endl;
    cout << "ð������ǰ����arr3��Ԫ�����£�" << endl;
    for (i = 0; i < (sizeof(arr3) / sizeof(arr3[0])); i++)
        cout << arr3[i] << "; ";
    cout << endl;

    for (i = 0, j = 0; i < ((sizeof(arr3) / sizeof(arr3[0])) - j); i = 0, j++)
    {
        for (i = 0; i < ((sizeof(arr3) / sizeof(arr3[0])) - j - 1); i++)
        {
            if (arr3[i] > arr3[i + 1]) // ��������ֻ�轫������Ϊarr3[i] <arr3[i + 1]
            {
                temp = arr3[i];
                arr3[i] = arr3[i + 1];
                arr3[i + 1] = temp;
            }
        }
    }

    cout << "ð�����������arr3��Ԫ�����£�" << endl;
    for (i = 0; i < (sizeof(arr3) / sizeof(arr3[0])); i++)
        cout << arr3[i] << "; ";
    cout << endl;

    //��ά����
    int arr4[][3] = {{1, 2, 3}, {4, 5, 6}};

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << arr4[i][j] << " ";
        }
        cout << endl;
    }

    cout << "arr4����������ռ�ڴ��С����λ���ֽڣ�Ϊ��" << sizeof(arr4) << endl;
    cout << "arr4����һ��Ԫ����ռ�ڴ��С����λ���ֽڣ�Ϊ��" << sizeof(arr4[0]) << endl;
    cout << "arr4��ÿ��Ԫ����ռ�ڴ��С����λ���ֽڣ�Ϊ��" << sizeof(arr4[0][0]) << endl;
    cout << "arr4��ÿ�е�Ԫ�ظ���(����)Ϊ��" << (sizeof(arr4[0]) / sizeof(arr4[0][0])) << endl;
    cout << "arr4���������Ԫ�ظ���Ϊ��" << (sizeof(arr4) / sizeof(arr4[0][0])) << endl; //ͳ������Ԫ�صĸ���
    cout << "arr4������׵�ַΪ��" << arr4 << endl;
    cout << "arr4�����һ��Ԫ�صĵ�ַΪ��" << &arr4[0][0] << endl;
    cout << "arr4����ڶ���Ԫ�صĵ�ַΪ��" << &arr4[0][1] << endl; //���һ��Ԫ�����int 4���ֽ�
    cout << "arr4����ڶ�����Ԫ�صĵ�ַΪ��" << &arr4[1][0] << endl;

    // ��ά���鰸������ӡ�����ܳɼ�
    int arr5[][3] = {{91, 92, 93}, {94, 95, 96}, {97, 98, 99}};
    int sum;
    string names[] = {"����", "����", "����"};

    for (i = 0; i < 3; i++)
    {
        sum = 0;
        for (j = 0; j < 3; j++)
        {
            sum += arr5[i][j];
        }
        cout << names[i] << "���ܳɼ�Ϊ" << sum << endl;
    }
    return 0;
}