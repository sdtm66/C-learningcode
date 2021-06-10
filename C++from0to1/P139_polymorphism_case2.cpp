//������Ʒ
#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    virtual void boil() = 0; //��ˮ
    virtual void brew() = 0; //����
    virtual void pour() = 0; //���뱭��
    virtual void put() = 0;  //���븨��
    void makedrink()
    {
        boil();
        brew();
        pour();
        put();
    }
};
class Coffee : public Base
{
public:
    virtual void boil()
    {
        cout << "��ũ��ɽȪ" << endl;
    }
    virtual void brew()
    {
        cout << "���ݿ���" << endl;
    }
    virtual void pour()
    {
        cout << "���뱭��" << endl;
    }
    virtual void put()
    {
        cout << "�����Ǻ�ţ��" << endl;
    }
};
class Tea : public Base
{
public:
    virtual void boil()
    {
        cout << "��Ȫˮ" << endl;
    }
    virtual void brew()
    {
        cout << "���ݲ�Ҷ" << endl;
    }
    virtual void pour()
    {
        cout << "���뱭��" << endl;
    }
    virtual void put()
    {
        cout << "��ũ��ɽȪ" << endl;
    }
};

void do_work(Base *abs)
{
    abs->makedrink();
    delete abs;
}

void test01()
{
    //��������
    do_work(new Coffee);
    cout << "---------------" << endl;
    do_work(new Tea);
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