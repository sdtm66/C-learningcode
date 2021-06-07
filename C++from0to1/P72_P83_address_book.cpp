#include <iostream>
#include "P72_P83_address_book_function.h"
#include <string>
using namespace std;

int main(void)
{
    int flag;
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
        if (flag == 0)
            break;
        system("pause");
        system("CLS");
    }

    return 0;
}