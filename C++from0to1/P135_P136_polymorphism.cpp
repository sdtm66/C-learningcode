// ��̬
//��1����̬��̬���������غ�������������ھ�̬��̬�����ú�����
//��2����̬��̬����������麯��ʵ������ʱ��̬
//��̬��̬�붯̬��̬������
//��1����̬��̬�ĺ�����ַ���  ����׶�ȷ��������ַ
//��2����̬��̬�ĺ�����ַ���  ���н׶�ȷ��������ַ
// ��̬��̬����������1 �м̳й�ϵ��2 ����Ҫ��д������麯��
// ��̬��̬��ʹ�ã������ָ���������ָ���������
#include <iostream>
#include <string>
using namespace std;
//������
class Animal
{
public:
    //�麯��
    virtual void speak()
    {
        cout << "������˵��" << endl;
    }
};
//è��
class Cat : public Animal
{
public:
    //��������д�˸����е��麯���������е��麯�����ڲ����滻��������麯��
    virtual void speak()
    {
        cout << "Сè��˵��" << endl;
    }
};
//ִ��˵���ĺ���
//��ַ��󶨣��ڱ���׶�ȷ��������ַ
//�����ִ����è˵������ô���������ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а󶨣���ַ��󶨣�virtual void speak()
void dospeak(Animal &animal)
{
    animal.speak();
}

void test01()
{
    //�������ָ���������ָ���������ʱ��Animal &animal = cat,������̬
    Cat cat;
    dospeak(cat);
}

void test02()
{
    cout << "size of animal:" << sizeof(Animal) << endl;
    //�麯������ָ��Ĵ�С����һ���ֽڵĴ�С8�ֽڣ�ָ���麯�����������ڻ��¼�麯���ĵ�ַ&Animal::speak
}

int main(void)
{
    test01();
    test02();
    return 0;
}