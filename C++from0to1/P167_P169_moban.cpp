//ģ�壺ģ����Ǽ���ͨ�õ���Ŀ�������߸�����
//����ģ�壺C++��һ�ֱ��˼���Ϊ���ͱ�̣���Ҫ���õļ�������ģ��
//C++�ṩ����ģ��ģ�壺����ģ�����ģ��
// ����ģ������ã�����һ��ͨ�ú������亯������ֵ���ͺ��β����Ϳ��Բ������ƶ�����һ�����������������
// �﷨��  template<typename����class T>
// ������������
// template ��������ģ��  typename ���������ķ�����һ���������ͣ�������class����  T ͨ�õ��������ͣ����ƿ����滻��ͨ��Ϊ��д��ĸ
//ע������Զ������Ƶ��������Ƶ���һ������������T���ſ���ʹ�ã�ģ�����ȷ����T���������ͣ��ſ���ʹ��

#include <iostream>
#include <string>
using namespace std;

void swapint(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void swapdouble(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

//����ģ��
template <typename T> //����һ��ģ�壬���߱�������������н����ŵ�T��Ҫ����T��һ��ͨ����������
void my_swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test01()
{
    int a = 10;
    int b = 20;
    swapint(a, b);
    cout << "a=" << a << ";b=" << b << endl;
    double c = 2.0;
    double d = 3.0;
    swapdouble(c, d);
    cout << "c=" << c << ";d=" << d << endl;
    float e = 4.0;
    float f = 5.0;
    //my_swap(e, f);        //�Զ������Ƶ�
    my_swap<float>(e, f); //��ʾָ������
    cout << "e=" << e << ";f=" << f << endl;
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