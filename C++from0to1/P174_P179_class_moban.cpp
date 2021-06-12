//��ģ�壺����һ��ͨ���࣬���еĳ�Ա �������Ϳ��Բ������ƶ�����һ�����������������
// template <typename T>
//��ģ��û���Զ������Ƶ���ʹ�÷�ʽ
//��ģ����ģ������б��п�����Ĭ�ϲ���
//��ͨ���еĳ�Ա����һ��ʼ�Ϳ��Դ�������ģ���еĳ�Ա�����ڵ���ʱ�Ŵ���
// ��ģ�����������������1 ָ���������ͣ�2 ����ģ�廯��3 ������ģ�廯
//����ģ�������̳�ʱ�������ע�����
//������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ���������е�����
//�����ָ�����������޷�����������ڴ�
//��������ָ����������T�����ͣ�����Ҳ������ģ��

#include <iostream>
#include <string>
using namespace std;

template <typename NameType = string, typename AgeType = int> //��ģ����ģ������б��п�����Ĭ�ϲ���������Ĭ�ϲ���NameType = string��AgeType = int
class Person
{
public:
    Person(NameType name1, AgeType age1) : name(name1), age(age1) {}
    NameType name;
    AgeType age;
    void showPerson();
};
// ��ģ��ĳ�Ա����������ʵ��
template <typename NameType, typename AgeType> //���������ⲿ����ģ���Ա������ָ��Ĭ��ģ�����
void Person<NameType, AgeType>::showPerson()
{
    cout << "name:" << name << "; age:" << age << endl;
}

// ��ģ�����������������1 ָ���������ͣ�Person<string, int> ��ʹ�õ����
void printPerson1(Person<string, int> &p)
{
    cout << "��ģ�����������������1 ָ����������" << endl;
    p.showPerson();
}
// ��ģ�����������������2 ����ģ�廯
template <typename NameType = string, typename AgeType = int>
void printPerson2(Person<NameType, AgeType> &p)
{
    cout << "��ģ�����������������2 ����ģ�廯" << endl;
    cout << "NameType���������ͣ�" << typeid(NameType).name() << endl;
    cout << "AgeType���������ͣ�" << typeid(AgeType).name() << endl;
    p.showPerson();
}
// ��ģ�����������������3 ������ģ�廯
template <typename T>
void printPerson3(T &p)
{
    cout << "��ģ�����������������3 ������ģ�廯" << endl;
    cout << "T���������ͣ�" << typeid(T).name() << endl;
    p.showPerson();
}

//��ģ����̳�
template <typename NameType = string, typename AgeType = int>
class Father
{
public:
    NameType name;
    AgeType age;
    void showPerson()
    {
        cout << "name:" << name << "; age:" << age << endl;
    }
};
class Son1 : public Father<string, int> //������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ���������е�����
{
};
template <typename T1, typename T2>
class Son2 : public Father<T1, T2> //��������ָ����������T�����ͣ�����Ҳ������ģ��
{
};

void test01()
{
    //Person p1("����", 24); //�����﷨����ģ��û���Զ������Ƶ���ʹ�÷�ʽ
    Person<string, int> p1("����", 24);
    p1.showPerson();
    Person<> p2("��˼", 23); //
    p2.showPerson();
    printPerson1(p2);
    printPerson2(p2);
    printPerson3(p2);

    Son1 p3;
    p3.name = "����";
    p3.age = 34;
    p3.showPerson();
    Son2<string, int> p4;
    p4.name = "����";
    p4.age = 54;
    p4.showPerson();
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