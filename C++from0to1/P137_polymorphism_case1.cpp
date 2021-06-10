// ��̬�ĺô�����֯�ṹ�������ɶ���ǿ������ǰ�ںͺ�����չ�Լ�ά���Ը�
//
#include <iostream>
#include <string>
using namespace std;
//����������
class BaseCal
{
public:
    virtual int getResult()
    {
        return 0;
    }
    int m_N1;
    int m_N2;
};
//�ӷ��������
class AddCal : public BaseCal
{
    int getResult()
    {
        return m_N1 + m_N2;
    }
};
//�����������
class SubCal : public BaseCal
{
    int getResult()
    {
        return m_N1 - m_N2;
    }
};
//�˷��������
class MulCal : public BaseCal
{
    int getResult()
    {
        return m_N1 * m_N2;
    }
};
//�����������
class DivCal : public BaseCal
{
    int getResult()
    {
        return m_N1 / m_N2;
    }
};

void test01()
{
    //��̬ʹ������:����ָ�������ָ���������
    //�ӷ�����
    BaseCal *abc = new AddCal;
    abc->m_N1 = 10;
    abc->m_N2 = 10;
    cout << abc->m_N1 << "+" << abc->m_N2 << "=" << abc->getResult() << endl;
    delete abc; //new���ٵĶ���ʹ������Ҫ��ʱ����
    //��������
    abc = new SubCal;
    abc->m_N1 = 10;
    abc->m_N2 = 10;
    cout << abc->m_N1 << "-" << abc->m_N2 << "=" << abc->getResult() << endl;
    delete abc; //new���ٵĶ���ʹ������Ҫ��ʱ����
    //�˷�����
    abc = new MulCal;
    abc->m_N1 = 10;
    abc->m_N2 = 10;
    cout << abc->m_N1 << "*" << abc->m_N2 << "=" << abc->getResult() << endl;
    delete abc; //new���ٵĶ���ʹ������Ҫ��ʱ����
    //��������
    abc = new DivCal;
    abc->m_N1 = 10;
    abc->m_N2 = 10;
    cout << abc->m_N1 << "/" << abc->m_N2 << "=" << abc->getResult() << endl;
    delete abc; //new���ٵĶ���ʹ������Ҫ��ʱ����
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