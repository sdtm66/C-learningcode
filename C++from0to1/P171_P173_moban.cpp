//��ͨ�����뺯��ģ�������
// ��ͨ��������ʱ���Է����Զ�����ת������ʽ����ת����
// ����ģ�����ʱ����������Զ������Ƶ������ᷢ����ʽ����ת��
// ���������ʾָ�����͵ķ�ʽ�����Է�����ʽ����ת��
// �ܽ᣺����ʹ����ʾָ�����͵ķ�ʽ�����ú���ģ�壬��Ϊ�����Լ�ȷ��ͨ������T
// ���ù������£�
// 1 �������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
// 2 ����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
// 3 ����ģ��Ҳ��������
// 4 �������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
// �ܽ᣺��Ȼ�ṩ�˺���ģ�壬��þͲ�Ҫ�ṩ��ͨ�������������׳��ֶ����ԣ�
// �����ԣ��Զ�����������
//���þ��廯��ģ�壬���Խ���Զ������͵�ͨ�û�
// ѧϰģ�岢����Ϊ��дģ�壬������STL�ܹ�����ϵͳ�ṩ��ģ��
#include <iostream>
#include <string>
using namespace std;

int my_add(int a, int b)
{
    cout << "���õ�һ������" << endl;
    return a + b;
}

template <typename T>
T my_add(T a, T b)
{
    cout << "���õڶ�������" << endl;
    return a + b;
}

template <typename T>
T my_add(T a, T b, T c)
{
    cout << "���õ���������" << endl;
    return a + b + c;
}
//�Զ��������������ú���ģ��Ƚ�
class Person
{
public:
    Person(string name1, int age1) : name(name1), age(age1) {}

public:
    string name;
    int age;
};
//���þ��廯Person�İ汾ʵ�ִ��룬���廯���ȵ���
template <class T>
bool my_compare(T &a, T &b)
{
    if (a == b)
    {
        return true;
    }
    else
    {
        return true;
    }
}

template <>
bool my_compare(Person &p1, Person &p2)
{
    if ((p1.name == p2.name) && (p2.age == p2.age))
    {
        return true;
    }
    else
    {
        return false;
    }
};

void test01()
{
    int a = 10;
    char b = 'b';
    char c = 'c';
    cout << my_add(a, b) << endl; //�������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ������������ʽ����ת����charת����int
    //cout << my_add2(a, b) << endl; //�Զ������Ƶ������ᷢ����ʽ����ת��
    cout << my_add<int>(a, b) << endl;     //��ʾָ�����ͣ�������ʽ����ת����charת����int
    cout << my_add<>(a, 20) << endl;       //����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
    cout << my_add<int>(a, b, 20) << endl; //����ģ��Ҳ��������
    cout << my_add(b, c) << endl;          // �������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
}

void test02()
{
    Person p1("Tom", 23);
    Person p2("Tom", 23);
    bool res = my_compare(p1, p2);
    if (res)
    {
        cout << "p1==p2" << endl;
    }
    else
    {
        cout << "p1!=p2" << endl;
    }
}

int main(void)
{
    test01();
    test02();
    return 0;
}