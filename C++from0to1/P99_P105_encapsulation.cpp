// c++���������������ԣ���װ���̳����̬
// ��װ������1������������Ϊ��Ϊһ�����壬�����
// ��װ������2����װ�����ʱ�����԰����Ժ���Ϊ���ڲ�ͬ��Ȩ���£����Կ��ơ�
// ���ʵ�Ȩ�������֣�
// ��1��public ����Ȩ�� ������Է��ʣ�
// ��2��protected ����Ȩ�� ���ڿ��Է��� ���ⲻ�ɷ��� ������Լ̳�
// ��3��private ˽��Ȩ�� ���ڿ��Է��� ���ⲻ�ɷ��� ���಻�ɼ̳�
// �﷨��  class ����������Ȩ�ޣ�����/��Ϊ��
//���е����Ժ���Ϊ������ͳһ��Ϊ��Ա
//���� ��Ա���� ��Ա����
//��Ϊ ��Ա���� ��Ա����
// ��c++��struct��class��Ψһ��������Ĭ�ϵķ���Ȩ�޲�ͬ��structĬ��Ȩ��Ϊ������classĬ��Ȩ��Ϊ˽��
// �����г�Ա��������Ϊ˽�У������Լ����ƶ�дȨ��
// ����дȨ�ޣ����ǿ��Լ�����ݵ���Ч��
#include <iostream>
#include <string>
#define PI 3.1415926
using namespace std;

//���һ��Բ�࣬��Բ���ܳ�
class Circle
{
public:
    double radius;
    double calculate_perimeter()
    {
        return 2 * PI * radius;
    }
};

class Person
{
public:
    string name;

public:
    void init()
    {
        name = "����";
        car = "����";
        wife = "����";
    }

protected:
    string car;

private:
    string wife;
};

int main(void)
{
    Circle c1; //ʵ����һ������
    cout << "������Բ�İ뾶��" << endl;
    cin >> c1.radius;
    cout << "Բ���ܳ�Ϊ��" << c1.calculate_perimeter() << endl;

    Person p1;
    p1.init();
    cout << p1.name << endl;

    return 0;
}