//��Ԫ��Ŀ�ľ�����һ�����������������һ�����е�˽�г�Ա
//�ؼ���friend
//����ʵ�֣�ȫ�ֺ�������Ԫ��������Ԫ����Ա��������Ԫ��
#include <iostream>
#include <string>
using namespace std;

class Building
{
    friend void good(Building *building); //good�������Է���Building�е�˽�г�Ա
    friend class Good;                    //Good����Է���Building�е�˽�г�Ա

public:
    Building() : m_SittingRoom("����"), m_BedRoom("����") {}

public:
    string m_SittingRoom;

private:
    string m_BedRoom;
};

//ȫ�ֺ�����Ϊ��Ԫ
void good(Building *building)
{
    cout << "visiting " << building->m_SittingRoom << endl;
    cout << "visiting " << building->m_BedRoom << endl;
}

//����Ϊ��Ԫ
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