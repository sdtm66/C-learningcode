// �����������������
// �������غ�ʹ�õķ�ʽ�ǳ������ĵ��ã���˳�Ϊ�º���
#include <iostream>
#include <string>
using namespace std;

class MyPrint
{
public:
    //���غ������������
    void operator()(string test)
    {
        cout << test << endl;
    }
};

class MyAdd
{
public:
    int operator()(int a, int b)
    {
        return a + b;
    }
};

void test01()
{
    MyPrint p1;
    p1("Hello!"); //�º���
}

void test02()
{
    MyAdd add;
    int res = add(100, 100);
    cout << "res=" << res << endl;
    //������������
    cout << MyAdd()(100, 200) << endl;
}

int main(void)
{
    test01();
    test02();
    return 0;
}