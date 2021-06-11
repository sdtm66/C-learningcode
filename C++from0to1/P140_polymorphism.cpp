// ��̬ʹ��ʱ����������������Կ��ٵ���������ô����ָ�����ͷ�ʱ�޷����õ��������������
// �����ʽ���������е�����������Ϊ���������ߴ�������
// �������ʹ����������ԣ����Խ������ָ���ͷ�������󣻶���Ҫ�о���ĺ���ʵ��
// �������ʹ���������������Ǵ����������������ڳ����࣬�޷�ʵ��������
// �������﷨�� virtual ~����(){}
// ���鹹�﷨�� virtual ~����()=0��
//             ����::~����(){}
//
//
//

#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "Animal���캯������" << endl;
    }
    virtual ~Animal() //�������������ã��������ָ���ͷ��������ʱ���ɾ�������
    {
        cout << "Animal������������" << endl;
    }
    //virtual ~Animal()=0; //������������,��Ҫ����Ҳ��Ҫʵ��
    virtual void speak() = 0;
};
// Animal::~Animal() //������������ʵ��
// {
//     cout << "Animal������������" << endl;
// }

class Cat : public Animal
{
public:
    Cat(string name) : Name(new string(name))
    {
        cout << "Cat���캯������" << endl;
    }
    ~Cat()
    {
        if (Name != NULL)
        {
            cout << "Cat������������" << endl;
            delete Name;
            Name = NULL;
        }
    }
    virtual void speak()
    {
        cout << *Name << "Сè��˵��" << endl;
    }

    string *Name;
};

void test01()
{
    Animal *animal = new Cat("Tom");
    animal->speak();
    delete animal; //����ָ��������ʱ�򣬲����������������������������������ж������ԣ������ڴ�й©
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