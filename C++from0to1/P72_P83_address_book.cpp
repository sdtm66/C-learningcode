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
        cout << "请输入0-6的整数，相应整数对应一下操作" << endl;
        cout << "**********************" << endl;
        cout << "**** 1 添加联系人  ****" << endl;
        cout << "**** 2 显示联系人  ****" << endl;
        cout << "**** 3 删除联系人  ****" << endl;
        cout << "**** 4 查找联系人  ****" << endl;
        cout << "**** 5 修改联系人  ****" << endl;
        cout << "**** 6 清空联系人  ****" << endl;
        cout << "**** 0 退出通讯录  ****" << endl;
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
            cout << "您必须输入0-6的整数！" << endl;
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