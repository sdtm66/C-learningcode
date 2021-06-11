//�ļ�����
//��������ʱ���������ݶ�������ʱ���ݣ�����һ�����н������ᱻ�ͷ�
//ͨ���ļ����Խ����ݳ־û�
//C++�ж��ļ�������Ҫ����ͷ�ļ�<fstream>
// �ļ����ͣ�
//��1���ı��ļ����ļ����ı���ASCII����ʽ�洢�ڼ������
//��2���������ļ����ļ����ı��Ķ�������ʽ�洢�ڼ�����У��û�һ�㲻��ֱ�Ӷ�������
//�����ı��ļ��������ࣺofstream�ࣺ���ļ���ifstream�ࣺд�ļ���fstream�ࣺ��д�ļ�
// д�ļ���1 ����ͷ�ļ� #include <fstream> 2 ���������� ofstream ofs�� 3 ���ļ� ofs.open��'�ļ�·��'���򿪷�ʽ�� 4 д���� ofs << "д�������" 5 �ر��ļ� ofs.close����
// �ļ��򿪷�ʽ��iOS::in Ϊ���ļ������ļ���ios::out Ϊд�ļ������ļ���ios::ate ��ʼλ�ã��ļ�β����
// ios::app ͨ��׷�ӷ�ʽд�ļ���ios::trunc ����ļ����ڣ���ɾ���ٴ�����ios::binary �����Ʒ�ʽ
// ע�⣺�ļ��򿪷�ʽ�������ʹ�ã�����|�����������磺�ö����Ʒ�ʽд�ļ�  ios::binary | ios::out
//���ļ���1 ����ͷ�ļ� #include <fstream> 2 ���������� ifstream ofs�� 3 ���ļ� ifs.open��'�ļ�·��'���򿪷�ʽ�� 4 ������ ���ַ�ʽ��ȡ 5 �ر��ļ� ifs.close����
#include <iostream>
#include <string>
#include <fstream> //����ͷ�ļ� #include <fstream>
using namespace std;

void test01()
{
    ofstream ofs("test.txt", ios::out); //���������󲢴��ļ�
    ofs << "����������" << endl;        //д����
    ofs << "����������" << endl;        //д����
    ofs.close();                        //�ر��ļ�
}

void test02()
{
    ifstream ifs;
    ifs.open("test.txt", ios::in);
    if (!ifs.is_open()) //����is_open�����ж��ļ��Ƿ�򿪳ɹ�
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    //��һ�ֶ����ݷ���
    // char buf[1024] = {0};
    // while (ifs >> buf)
    // {
    //     cout << buf << endl;
    // }
    //�ڶ��ֶ����ݷ���
    // char buf[1024] = {0};
    // while (ifs.getline(buf, sizeof(buf)))
    // {
    //     cout << buf << endl;
    // }
    //�����ֶ����ݷ���
    // string buf;
    // while (getline(ifs, buf))
    // {
    //     cout << buf << endl;
    // }
    //�����ֶ����ݷ���
    char c;
    while ((c = ifs.get()) != EOF) //EOF end of file
    {
        cout << c;
    }

    ifs.close();
}

int main(void)
{
    //test01();
    test02();
    return 0;
}