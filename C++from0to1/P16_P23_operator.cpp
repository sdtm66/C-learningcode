#include <iostream>
#include <stdio.h>
#include <string> //�ṩstring���ͱ���
using namespace std;

int main(void)
{
    /* �������� */
    int a = 6;
    int b = 3;
    bool flag_true = true;
    bool flag_false = false;
    /* ��ӡ��� */
    //���������
    cout << "a + b =" << a + b << endl;
    cout << "a - b =" << a - b << endl;
    cout << "a * b =" << a * b << endl;
    cout << "a / b =" << a / b << endl;
    cout << "a % b =" << a % b << endl;
    cout << "++a=" << ++a << endl;
    cout << "--b =" << --b << endl;
    //��ֵ�����
    a += 3;
    cout << "a += 3-->a = " << a << endl;
    a -= 3;
    cout << "a -= 3-->a = " << a << endl;
    a *= 3;
    cout << "a *= 3-->a = " << a << endl;
    a /= 3;
    cout << "a /= 3-->a = " << a << endl;
    //�Ƚ������
    cout << "a==b = " << (a == b) << endl;
    cout << "a!=b = " << (a != b) << endl;
    cout << "a>b = " << (a > b) << endl;
    cout << "a>=b = " << (a >= b) << endl;
    cout << "a<b = " << (a < b) << endl;
    cout << "a<=b = " << (a <= b) << endl;
    //�߼������
    cout << "!true = " << (!flag_true) << endl;
    cout << "true && false = " << (flag_true && flag_false) << endl;
    cout << "true || false = " << (flag_true || flag_false) << endl;

    system("pause");
    return 0;
}