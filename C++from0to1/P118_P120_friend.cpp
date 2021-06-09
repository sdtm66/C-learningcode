//友元的目的就是让一个函数或者类访问另一个类中的私有成员
//关键字friend
//三种实现：全局函数做友元；类做友元；成员函数做友元；
#include <iostream>
#include <string>
using namespace std;

class Building
{
    friend void good(Building *building); //good函数可以访问Building中的私有成员
    friend class Good;                    //Good类可以访问Building中的私有成员

public:
    Building() : m_SittingRoom("客厅"), m_BedRoom("卧室") {}

public:
    string m_SittingRoom;

private:
    string m_BedRoom;
};

//全局函数作为友元
void good(Building *building)
{
    cout << "visiting " << building->m_SittingRoom << endl;
    cout << "visiting " << building->m_BedRoom << endl;
}

//类作为友元
class Good
{
public:
    Good() : building(new Building) {}

public:
    void visit()
    {
        cout << "visiting " << building->m_SittingRoom << endl;
        cout << "visiting " << building->m_BedRoom << endl;
    }
    Building *building;
};

int main(void)
{
    Building b1;
    good(&b1);
    Good g1;
    g1.visit();
    return 0;
}