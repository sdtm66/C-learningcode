#include <iostream>
#include <string>
using namespace std;
#define MAX_CONTACT 2

typedef struct Contact
{
    string name;
    int sex;
    int age;
    string tel;
    string address;
} contact;

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
                    cout << "���޸ĺø���ϵ���µ���Ϣ��" << endl;
                    break;
                default:
                    cout << "������0-4֮������֣�" << endl;
                }
                if (flag == 0)
                    break;
            }
            SEX = (p1[i].sex == 1) ? "��" : "Ů";
            cout << "�޸ĺ����ϵ�˵���Ϣ���£�" << endl;
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

int main(void)
{
    int flag;
    //��ʼ��ͨѶ¼
    contact address_book[MAX_CONTACT];
    for (int i = 0; i < MAX_CONTACT; i++)
    {
        contact init = {"0", 0, 0, "0", "0"};
        address_book[i] = init;
    }

    while (1)
    {
        cout << "������0-6����������Ӧ������Ӧһ�²���" << endl;
        cout << "**********************" << endl;
        cout << "**** 1 �����ϵ��  ****" << endl;
        cout << "**** 2 ��ʾ��ϵ��  ****" << endl;
        cout << "**** 3 ɾ����ϵ��  ****" << endl;
        cout << "**** 4 ������ϵ��  ****" << endl;
        cout << "**** 5 �޸���ϵ��  ****" << endl;
        cout << "**** 6 �����ϵ��  ****" << endl;
        cout << "**** 0 �˳�ͨѶ¼  ****" << endl;
        cout << "**********************" << endl;
        cin >> flag;
        switch (flag)
        {
        case 0:
        {
            exit_book(address_book);
            break;
        }
        case 1:
        {
            add_contact(address_book);
            break;
        }
        case 2:
        {
            show_contact(address_book);
            break;
        }
        case 3:
        {
            del_contact(address_book);
            break;
        }
        case 4:
        {
            find_contact(address_book);
            break;
        }
        case 5:
        {
            modify_contact(address_book);
            break;
        }
        case 6:
        {
            clear_contact(address_book);
            break;
        }
        default:
        {
            cout << "����������0-6��������" << endl;
            break;
        }
        }
        if (flag == 0) // ||flag==1 ||flag==2 ||flag==3 ||flag==4 ||flag==5 ||flag==6)
            break;
        system("pause");
        system("CLS");
    }
    return 0;
}