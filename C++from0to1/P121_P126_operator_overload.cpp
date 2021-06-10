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
    //��Ա����ʵ������+��
    Person operator+(Person &p) //�Ӻ���������أ�����������µĶ��壬���Զ����������ͽ����������
    {
        Person temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;
        return temp;
    }
    //���������Ҳ���Է�����������
    Person operator+(int a) //�Ӻ���������أ�����������µĶ��壬���Զ����������ͽ����������
    {
        Person temp;
        temp.m_A = this->m_A + a;
        temp.m_B = this->m_B + a;
        return temp;
    }
};

//ȫ�ֺ���ʵ������+��
// Person operator+(Person &p1, Person &p2)
// {
//     Person temp;
//     temp.m_A = p1.m_A + p2.m_A;
//     temp.m_B = p1.m_B + p2.m_B;
//     return temp;
// }

int main(void)
{
    Person p1;
    Person p2;
    Person p = p1 + p2; // Person +Person
    //Person p = p1.operator+(p2); //��Ա����ʵ������+�ű��ʵ���
    //Person p = operator+(p1,p2)//ȫ�ֺ���ʵ������+�ű��ʵ���
    cout << p.m_A << ";" << p.m_B << endl;
    //���������Ҳ���Է�����������
    Person p3 = p1 + 100; //Person+int
    cout << p3.m_A << ";" << p3.m_B << endl;
    return 0;
}