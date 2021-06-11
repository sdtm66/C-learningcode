//������װ
#include <iostream>
#include <string>
using namespace std;

class CPU
{
public:
    virtual void calculate() = 0;
};
class VideoCard
{
public:
    virtual void display() = 0;
};
class Memory
{
public:
    virtual void store() = 0;
};
class Computer
{
public:
    Computer(CPU *cpu, VideoCard *vc, Memory *memory)
    {
        this->cpu = cpu;
        this->vc = vc;
        this->memory = memory;
    }
    ~Computer() //�ṩ�����������ͷ���������ڶ������ڴ�
    {
        if (cpu != NULL)
        {
            delete cpu;
            cpu = NULL;
        }
        if (vc != NULL)
        {
            delete vc;
            vc = NULL;
        }
        if (memory != NULL)
        {
            delete memory;
            memory = NULL;
        }
    }

    void work()
    {
        cpu->calculate();
        vc->display();
        memory->store();
    }

private:
    CPU *cpu;
    VideoCard *vc;
    Memory *memory;
};

//Intel����
class IntelCPU : public CPU
{
public:
    virtual void calculate()
    {
        cout << "Intel��CPU���ڼ�����..." << endl;
    }
};
class IntelVideoCard : public VideoCard
{
public:
    virtual void display()
    {
        cout << "Intel���Կ�������ʾ��..." << endl;
    }
};
class IntelMemory : public Memory
{
public:
    virtual void store()
    {
        cout << "Intel���ڴ����ڴ洢��..." << endl;
    }
};

//���볧��
class LenovaCPU : public CPU
{
public:
    virtual void calculate()
    {
        cout << "Lenova��CPU���ڼ�����..." << endl;
    }
};
class LenovaVideoCard : public VideoCard
{
public:
    virtual void display()
    {
        cout << "Lenova���Կ�������ʾ��..." << endl;
    }
};
class LenovaMemory : public Memory
{
public:
    virtual void store()
    {
        cout << "Lenova���ڴ����ڴ洢��..." << endl;
    }
};

void test01()
{
    //��һ̨�������
    CPU *intelCPU = new IntelCPU;
    VideoCard *intelVideoCard = new IntelVideoCard;
    Memory *intelMemory = new IntelMemory;
    //������һ̨����
    Computer *computer1 = new Computer(intelCPU, intelVideoCard, intelMemory);
    cout << "��һ̨�������ڹ���...." << endl;
    computer1->work();
    cout << "--------------------" << endl;
    delete computer1;
    //�����ڶ�̨����
    Computer *computer2 = new Computer(new LenovaCPU, new LenovaVideoCard, new LenovaMemory);
    cout << "�ڶ�̨�������ڹ���...." << endl;
    computer2->work();
    cout << "--------------------" << endl;
    delete computer2;
    //��������̨����
    Computer *computer3 = new Computer(new IntelCPU, new LenovaVideoCard, new IntelMemory);
    cout << "����̨�������ڹ���...." << endl;
    computer3->work();
    cout << "--------------------" << endl;
    delete computer3;
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