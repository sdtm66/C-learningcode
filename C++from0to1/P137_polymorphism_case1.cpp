// 多态的好处：组织结构清晰；可读性强；对于前期和后期扩展以及维护性高
//
#include <iostream>
#include <string>
using namespace std;
//计算器基类
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
//加法计算机类
class AddCal : public BaseCal
{
    int getResult()
    {
        return m_N1 + m_N2;
    }
};
//减法计算机类
class SubCal : public BaseCal
{
    int getResult()
    {
        return m_N1 - m_N2;
    }
};
//乘法计算机类
class MulCal : public BaseCal
{
    int getResult()
    {
        return m_N1 * m_N2;
    }
};
//除法计算机类
class DivCal : public BaseCal
{
    int getResult()
    {
        return m_N1 / m_N2;
    }
};

void test01()
{
    //多态使用条件:父类指针或引用指向子类对象
    //加法运算
    BaseCal *abc = new AddCal;
    abc->m_N1 = 10;
    abc->m_N2 = 10;
    cout << abc->m_N1 << "+" << abc->m_N2 << "=" << abc->getResult() << endl;
    delete abc; //new开辟的堆区使用完需要及时销毁
    //减法运算
    abc = new SubCal;
    abc->m_N1 = 10;
    abc->m_N2 = 10;
    cout << abc->m_N1 << "-" << abc->m_N2 << "=" << abc->getResult() << endl;
    delete abc; //new开辟的堆区使用完需要及时销毁
    //乘法运算
    abc = new MulCal;
    abc->m_N1 = 10;
    abc->m_N2 = 10;
    cout << abc->m_N1 << "*" << abc->m_N2 << "=" << abc->getResult() << endl;
    delete abc; //new开辟的堆区使用完需要及时销毁
    //除法运算
    abc = new DivCal;
    abc->m_N1 = 10;
    abc->m_N2 = 10;
    cout << abc->m_N1 << "/" << abc->m_N2 << "=" << abc->getResult() << endl;
    delete abc; //new开辟的堆区使用完需要及时销毁
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