#include <iostream>
#include <string>
using namespace std;

//��Ĭ��ֵ�βεĺ������﷨�� ����ֵ���� ������������=Ĭ��ֵ��{}
// ���ĳ��λ�ò�����Ĭ��ֵ����ô�����λ�����󣬴������ң�����Ҫ��Ĭ��ֵ
//�������������Ĭ��ֵ������ʵ�ֵ�ʱ��Ͳ�����Ĭ��ֵ
int sum(int a = 10, int b = 20, int c = 30);

//����ռλ�������﷨�� ����ֵ���� ���������������ͣ�{}
void func(int a, int)
{
    cout << "�ú�����ռλ����" << endl;
}

//�������أ�������������ͬ����߸����ԡ�����������ͬһ�������£���������ͬ�������������Ͳ�ͬ���߸�����ͬ����˳��ͬ�� ע�⣺�����ķ���ֵ��������Ϊ�������ص�����
void add()
{
    cout << "�ú���������" << endl;
}
int add(int a, int b)
{
    return a + b;
}
//����Ҳ������Ϊ�������ص�����
void ini(int &a)
{
    cout << "ini (int &a)����" << endl;
}
void ini(const int &a)
{
    cout << "ini (const int &a)����" << endl;
}
//������������Ĭ�ϲ������ж�����
int mul(int a, int b)
{
    return a * b;
}
int mul(int a, int b, int c = 10)
{
    return a * b * c;
}

int main(void)
{
    cout << sum() << endl;
    add();
    int b = add(4, 5);
    cout << b << endl;
    ini(10);   // int &a =10�����Ϸ���const int &a =10�����Ի����void ini (const int &a)
    ini(b);    // int &a =b  �Ϸ�;��Ϊb�ɶ���д�����Ի����void ini (int &a)����void ini (const int &a) ������ ʵ��Ϊֻ�ɶ�
    mul(1, 1); //�����˶�����
    return 0;
}

//��Ĭ��ֵ�βεĺ���
int sum(int a, int b, int c)
{
    return a + b + c;
}
