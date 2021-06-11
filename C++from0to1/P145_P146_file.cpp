//二进制文件读写
//打开方式指定为ios::binary
//二进制方式写文件主要利用流对象调用成员函数write
//函数原型 ostream& write(const char * buffer,int len);
//参数解释：字符指针buffer指向内存中一段存储空间，len是读写字长
//二进制写文件，除了可以操作int，char等内置数据类型外，还可以操作自定义数据类型
//二进制方式读文件主要利用流对象调用成员函数read
//函数原型ostream& read(char * buffer,int len);
//
#include <iostream>
#include <string>
#include <fstream> //包含头文件 #include <fstream>
using namespace std;

class Person
{
public:
    char m_Name[64];
    int m_Age;
};

void test01()
{
    ofstream ofs("person.txt", ios::binary | ios::out);
    Person p = {"王五", 17};
    ofs.write((const char *)&p, sizeof(Person)); //二进制方式写文件主要利用流对象调用成员函数write
    ofs.close();
}

void test02()
{
    ifstream ifs("person.txt", ios::binary | ios::in);
    if (!ifs.is_open()) //利用is_open函数判断文件是否打开成功
    {
        cout << "文件打开失败" << endl;
        return;
    }
    Person p1;
    ifs.read((char *)&p1, sizeof(Person)); //二进制方式读文件主要利用流对象调用成员函数read
    cout << p1.m_Age << ";" << p1.m_Name << endl;
    ifs.close();
}

int main(void)
{
    test01();
    test02();
    return 0;
}