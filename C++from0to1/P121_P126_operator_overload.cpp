//��������صĸ�������е���������½��ж��壬��������һ�ֹ��ܣ�����Ӧ��ͬ����������
// ���ã�ʵ�������Զ����������͵�����
// �������õ��������ͣ�������֪����ν��м���
//
//
//

#include <iostream>
#include <string>
using namespace std;

//�Ӻ����������
// 1 ��Ա��������+��
// 2 ȫ�ֺ�������+��

class Person
{
public:
    Person() : m_A(10), m_B(10){};
    Person(int A, int B) : m_A(A), m_B(B){};

public:
    int m_A;
    int m_B;

public:
    Person operator+(Person &p)
    {
        Person temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;
        return temp;
    }
};

int main(void)
{
    Person p1;
    Person p2;
    Person p = p1 + p2;
    cout << p.m_A << ";" << p.m_B << endl;

    return 0;
}