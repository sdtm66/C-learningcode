//电脑组装
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
    ~Computer() //提供析构函数，释放三个零件在堆区的内存
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

//Intel厂商
class IntelCPU : public CPU
{
public:
    virtual void calculate()
    {
        cout << "Intel的CPU正在计算中..." << endl;
    }
};
class IntelVideoCard : public VideoCard
{
public:
    virtual void display()
    {
        cout << "Intel的显卡正在显示中..." << endl;
    }
};
class IntelMemory : public Memory
{
public:
    virtual void store()
    {
        cout << "Intel的内存正在存储中..." << endl;
    }
};

//联想厂商
class LenovaCPU : public CPU
{
public:
    virtual void calculate()
    {
        cout << "Lenova的CPU正在计算中..." << endl;
    }
};
class LenovaVideoCard : public VideoCard
{
public:
    virtual void display()
    {
        cout << "Lenova的显卡正在显示中..." << endl;
    }
};
class LenovaMemory : public Memory
{
public:
    virtual void store()
    {
        cout << "Lenova的内存正在存储中..." << endl;
    }
};

void test01()
{
    //第一台电脑零件
    CPU *intelCPU = new IntelCPU;
    VideoCard *intelVideoCard = new IntelVideoCard;
    Memory *intelMemory = new IntelMemory;
    //创建第一台电脑
    Computer *computer1 = new Computer(intelCPU, intelVideoCard, intelMemory);
    cout << "第一台电脑正在工作...." << endl;
    computer1->work();
    cout << "--------------------" << endl;
    delete computer1;
    //创建第二台电脑
    Computer *computer2 = new Computer(new LenovaCPU, new LenovaVideoCard, new LenovaMemory);
    cout << "第二台电脑正在工作...." << endl;
    computer2->work();
    cout << "--------------------" << endl;
    delete computer2;
    //创建第三台电脑
    Computer *computer3 = new Computer(new IntelCPU, new LenovaVideoCard, new IntelMemory);
    cout << "第三台电脑正在工作...." << endl;
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