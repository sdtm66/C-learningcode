//�ڶ�̬�У�ͨ���������麯����ʵ���Ǻ�������ģ���Ҫ���ǵ�����д������
//��˿��Խ��麯����Ϊ���麯��
//���麯���﷨��virtual ����ֵ���� ������ (�����б�) = 0��
// ���������˴��麯���������Ҳ��Ϊ������
//��������ص㣺�޷�ʵ�����������������д�������е��麯��������Ҳ���ڳ�����

#include <iostream>
#include <string>
using namespace std;

class Base //�����ࣺ�޷�ʵ�����������������д�������е��麯��������Ҳ���ڳ�����
{
public:
    virtual void func() = 0; //���麯��
};
class Son : public Base
{
public:
    virtual void func()
    {
        cout << "func��������" << endl;
    }
};

void test01()
{
    Base *base = new Son;
    base->func();
}

void test02()
{
}

int main(void)
{
    test01();
    test02();
    return 0;
}