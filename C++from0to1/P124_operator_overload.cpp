// ��ֵ���������
// Ĭ������£�c++���������ٸ�һ�������3��������1 Ĭ���޲ι��캯�����޲Σ�������Ϊ�գ���2 Ĭ�������������޲Σ�������Ϊ�գ���
//3 Ĭ�Ͽ������캯���������Խ���ֵ������4 ��ֵ�����operator=,�����Խ���ֵ����
// �������������ָ�����������ֵ����ʱҲ�������ǳ��������
#include <iostream>
#include <string>
using namespace std;

class Person
{
    friend void test01();

public:
    Person(int age) : m_Age(new int(age)) {}
    ~Person()
    {
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
    }
    //���ظ�ֵ�����
    Person &operator=(Person &p)
    {
        //�������ṩ����ǳ������
        //m_Age = p.m_Age;
        //Ӧ���ж��Ƿ��������ڶ�������������ͷŸɾ���Ȼ�������
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
        m_Age = new int(*p.m_Age); //������������¿���һ�������ڴ�
        return *this;              //���ض�������
    }

private:
    int *m_Age;
};

void test01()
{
    Person p1(18);
    Person p2(20);
    Person p3(30);
    p3 = p2 = p1;
    cout << *p1.m_Age << endl;
    cout << *p2.m_Age << endl;
    cout << *p3.m_Age << endl;
}

int main(void)
{
    test01();
    return 0;
}
