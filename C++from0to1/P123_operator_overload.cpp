// �������������
// ǰ�õ����������ã����õ�������ֵ

#include <iostream>
#include <string>
using namespace std;

class MyInteger
{
    friend ostream &operator<<(ostream &cout, MyInteger p);

public:
    MyInteger() : m_Num(0){};
    //����ǰ��++�����
    MyInteger &operator++() //����������Ϊ��һֱ��һ�����ݽ��в�����
    {
        m_Num++;      //�Ƚ���++����
        return *this; //�ٽ�������
    }
    //���غ���++�����
    MyInteger operator++(int)
    //����ֵ����Ϊtemp��ַ�ں���������ͻᱻ���٣�int ����ռλ������������������ǰ�úͺ��õ�����operator++()����ǰ�õ������أ�operator++(int)������õ�������
    {
        MyInteger temp = *this; //�ȼ�¼��ʱ���
        m_Num++;                //�ٽ���++����
        return temp;            //�ٽ�������
    }

private:
    int m_Num;
};
ostream &operator<<(ostream &cout, MyInteger p) //����operator<<(cout,p)�� �� cout << p;
{
    cout << p.m_Num << endl;
    return cout; //��ʽ���˼��
}

int main(void)
{
    //����ǰ��++�����
    MyInteger i;
    cout << ++(++i) << endl;
    //���غ���++�����
    MyInteger j;
    cout << j++ << endl;
    cout << j << endl;
    return 0;
}