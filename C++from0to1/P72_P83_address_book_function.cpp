#include <iostream>
#include "P72_P83_address_book_function.h"
#include <string>
using namespace std;

void add_contact(contact *p1)
{
    string name;
    int sex;
    int age;
    string tel;
    int index;
    string address;
    cout << "����������" << endl;
    cin >> name;
    cout << "�������Ա��У�1��Ů��2��" << endl;
    cin >> sex;
    cout << "����������" << endl;
    cin >> age;
    cout << "��������ϵ�绰" << endl;
    cin >> tel;
    cout << "�������ͥ��ַ" << endl;
    cin >> address;
    contact new_contact = {name, sex, age, tel, address};
    for (index = 0; index < MAX_CONTACT; index++)
    {
        if (p1[index].sex == 0)
        {
            p1[index] = new_contact;
            cout << "��ӳɹ�" << endl;
            break;
        }
    }
    if (index == MAX_CONTACT)
    {
        cout << "���ʧ�ܣ�ͨѶ¼��������ɾ��һЩ��ϵ�˺������" << endl;
    }
}

void show_contact(contact *p1)
{
    string SEX;
    cout << "ͨѶ¼��������ϵ�˵���Ϣ���£�" << endl;
    for (int i = 0; i < MAX_CONTACT; i++)
    {
        if (p1[i].sex != 0)
        {
            SEX = (p1[i].sex == 1) ? "��" : "Ů";
            cout << "������" << p1[i].name << "   �Ա�" << SEX << "   �绰��" << p1[i].tel << "   סַ��" << p1[i].address << endl;
        }
    }
}

void del_contact(contact *p1)
{
    string delname;
    contact init1 = {"0", 0, 0, "0", "0"};
    int i;
    bool is_deleted = true;
    cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
    cin >> delname;
    for (i = 0; i < MAX_CONTACT; i++)
    {
        if (p1[i].name == delname)
        {
            p1[i] = init1;
            cout << "ɾ���ɹ�" << endl;
            is_deleted = false;
        }
    }
    if (is_deleted)
    {
        cout << "ɾ��ʧ�ܣ�δ�ҵ�����ɾ������ϵ��" << endl;
    }
}

void find_contact(contact *p1)
{
    string findname;
    int i;
    bool no_found = true;
    string SEX;
    cout << "��������Ҫ���ҵ���ϵ�ˣ�" << endl;
    cin >> findname;
    for (i = 0; i < MAX_CONTACT; i++)
    {
        if (p1[i].name == findname)
        {
            SEX = (p1[i].sex == 1) ? "��" : "Ů";
            cout << "���ҳɹ����������ҵ���ϵ�˵���Ϣ���£�" << endl;
            cout << "������" << p1[i].name << "   �Ա�" << SEX << "   �绰��" << p1[i].tel << "   סַ��" << p1[i].address << endl;
            no_found = false;
        }
    }
    if (no_found)
    {
        cout << "����ʧ�ܣ�δ�ҵ�������ҵ���ϵ��" << endl;
    }
}

void modify_contact(contact *p1)
{
    string name;
    int sex;
    int age;
    string tel;
    int index;
    string address;
    string findname;
    int i, flag;
    bool no_modified = true;
    string SEX;
    cout << "��������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
    cin >> findname;
    for (i = 0; i < MAX_CONTACT; i++)
    {
        if (p1[i].name == findname)
        {
            cout << "���ҵ���Ҫ�޸ĵ���ϵ�ˣ�" << endl;
            SEX = (p1[i].sex == 1) ? "��" : "Ů";
            cout << "����ϵ�˵�������Ϣ���£�" << endl;
            cout << "������" << p1[i].name << "   �Ա�" << SEX << "   �绰��" << p1[i].tel << "   סַ��" << p1[i].address << endl;
            while (1)
            {
                cout << "��������Ҫ�޸ĵ���Ŀ����0��ȷ���޸Ĳ��˳���1���޸�������2���޸��Ա�3���޸ĵ绰���룻 4���޸ĵ�ַ)" << endl;
                cin >> flag;
                switch (flag)
                {
                case 1:
                    cout << "���������ϵ���µ�����" << endl;
                    cin >> name;
                    p1[i].name = name;
                    break;
                case 2:
                    cout << "���������ϵ���µ��Ա�1���У�2��Ů��" << endl;
                    cin >> sex;
                    p1[i].sex = sex;
                    break;
                case 3:
                    cout << "���������ϵ���µĵ绰����" << endl;
                    cin >> tel;
                    p1[i].tel = tel;
                    break;
                case 4:
                    cout << "���������ϵ���µĵ�ַ" << endl;
                    cin >> address;
                    p1[i].address = address;
                    break;
                case 0:
                    cout << "���޸ĺø���ϵ�˵���Ϣ��" << endl;
                    break;
                default:
                    cout << "������0-4֮������֣�" << endl;
                }
                if (flag == 0)
                    break;
            }
            SEX = (p1[i].sex == 1) ? "��" : "Ů";
            cout << "�޸ĺ�ĸ���ϵ�˵���Ϣ���£�" << endl;
            cout << "������" << p1[i].name << "   �Ա�" << SEX << "   �绰��" << p1[i].tel << "   סַ��" << p1[i].address << endl;
            no_modified = false;
        }
    }
    if (no_modified)
    {
        cout << "�޸�ʧ�ܣ�δ�ҵ������޸ĵ���ϵ��" << endl;
    }
}

void clear_contact(contact *p1)
{
    for (int i = 0; i < MAX_CONTACT; i++)
    {
        contact init = {"0", 0, 0, "0", "0"};
        p1[i] = init;
    }
    cout << "ͨѶ¼�Ѿ���գ�" << endl;
}

void exit_book(contact *p1)
{
    cout << "��ӭ�´�ʹ�ã�" << endl;
}