//制作饮品
#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    virtual void boil() = 0; //煮水
    virtual void brew() = 0; //冲泡
    virtual void pour() = 0; //倒入杯中
    virtual void put() = 0;  //加入辅料
    void makedrink()
    {
        boil();
        brew();
        pour();
        put();
    }
};
class Coffee : public Base
{
public:
    virtual void boil()
    {
        cout << "煮农夫山泉" << endl;
    }
    virtual void brew()
    {
        cout << "冲泡咖啡" << endl;
    }
    virtual void pour()
    {
        cout << "倒入杯中" << endl;
    }
    virtual void put()
    {
        cout << "加入糖和牛奶" << endl;
    }
};
class Tea : public Base
{
public:
    virtual void boil()
    {
        cout << "煮泉水" << endl;
    }
    virtual void brew()
    {
        cout << "煮泡茶叶" << endl;
    }
    virtual void pour()
    {
        cout << "倒入杯中" << endl;
    }
    virtual void put()
    {
        cout << "煮农夫山泉" << endl;
    }
};

void do_work(Base *abs)
{
    abs->makedrink();
    delete abs;
}

void test01()
{
    //制作咖啡
    do_work(new Coffee);
    cout << "---------------" << endl;
    do_work(new Tea);
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