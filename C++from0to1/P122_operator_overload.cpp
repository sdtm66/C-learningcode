// �������������
// ���ã���������Զ������������
// ֻ������ȫ�ֺ������������
// ������������������Ԫ����ʵ������Զ����������ͣ�
#include <iostream>
#include <string>
using namespace std;

class Person
{
    friend ostream &operator<<(ostream &cout, Person p);

public:
    Person(int a, int b) : m_A(a), m_B(b) {}

private:
    int m_A;
    int m_B;
};

//���������<<����
ostream &operator<<(ostream &cout, Person p) //����operator<<(cout,p)�� �� cout << p;
{
    cout << "m_A=" << p.m_A << ";m_B=" << p.m_B << endl;
    return cout; //��ʽ���˼��
}

int main(void)
{
    Person p(10, 20);
    cout << p << endl;
    return 0;
}