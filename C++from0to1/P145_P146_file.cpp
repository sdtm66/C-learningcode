//�������ļ���д
//�򿪷�ʽָ��Ϊios::binary
//�����Ʒ�ʽд�ļ���Ҫ������������ó�Ա����write
//����ԭ�� ostream& write(const char * buffer,int len);
//�������ͣ��ַ�ָ��bufferָ���ڴ���һ�δ洢�ռ䣬len�Ƕ�д�ֳ�
//������д�ļ������˿��Բ���int��char���������������⣬�����Բ����Զ�����������
//�����Ʒ�ʽ���ļ���Ҫ������������ó�Ա����read
//����ԭ��ostream& read(char * buffer,int len);
//
#include <iostream>
#include <string>
#include <fstream> //����ͷ�ļ� #include <fstream>
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
    Person p = {"����", 17};
    ofs.write((const char *)&p, sizeof(Person)); //�����Ʒ�ʽд�ļ���Ҫ������������ó�Ա����write
    ofs.close();
}

void test02()
{
    ifstream ifs("person.txt", ios::binary | ios::in);
    if (!ifs.is_open()) //����is_open�����ж��ļ��Ƿ�򿪳ɹ�
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    Person p1;
    ifs.read((char *)&p1, sizeof(Person)); //�����Ʒ�ʽ���ļ���Ҫ������������ó�Ա����read
    cout << p1.m_Age << ";" << p1.m_Name << endl;
    ifs.close();
}

int main(void)
{
    test01();
    test02();
    return 0;
}