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
    cout << "请输入姓名" << endl;
    cin >> name;
    cout << "请输入性别（男：1；女：2）" << endl;
    cin >> sex;
    cout << "请输入年龄" << endl;
    cin >> age;
    cout << "请输入联系电话" << endl;
    cin >> tel;
    cout << "请输入家庭地址" << endl;
    cin >> address;
    contact new_contact = {name, sex, age, tel, address};
    for (index = 0; index < MAX_CONTACT; index++)
    {
        if (p1[index].sex == 0)
        {
            p1[index] = new_contact;
            cout << "添加成功" << endl;
            break;
        }
    }
    if (index == MAX_CONTACT)
    {
        cout << "添加失败：通讯录已满，请删除一些联系人后再添加" << endl;
    }
}

void show_contact(contact *p1)
{
    string SEX;
    cout << "通讯录中所有联系人的信息如下：" << endl;
    for (int i = 0; i < MAX_CONTACT; i++)
    {
        if (p1[i].sex != 0)
        {
            SEX = (p1[i].sex == 1) ? "男" : "女";
            cout << "姓名：" << p1[i].name << "   性别：" << SEX << "   电话：" << p1[i].tel << "   住址：" << p1[i].address << endl;
        }
    }
}

void del_contact(contact *p1)
{
    string delname;
    contact init1 = {"0", 0, 0, "0", "0"};
    int i;
    bool is_deleted = true;
    cout << "请输入您要删除的联系人：" << endl;
    cin >> delname;
    for (i = 0; i < MAX_CONTACT; i++)
    {
        if (p1[i].name == delname)
        {
            p1[i] = init1;
            cout << "删除成功" << endl;
            is_deleted = false;
        }
    }
    if (is_deleted)
    {
        cout << "删除失败：未找到您想删除的联系人" << endl;
    }
}

void find_contact(contact *p1)
{
    string findname;
    int i;
    bool no_found = true;
    string SEX;
    cout << "请输入您要查找的联系人：" << endl;
    cin >> findname;
    for (i = 0; i < MAX_CONTACT; i++)
    {
        if (p1[i].name == findname)
        {
            SEX = (p1[i].sex == 1) ? "男" : "女";
            cout << "查找成功，您所查找的联系人的信息如下：" << endl;
            cout << "姓名：" << p1[i].name << "   性别：" << SEX << "   电话：" << p1[i].tel << "   住址：" << p1[i].address << endl;
            no_found = false;
        }
    }
    if (no_found)
    {
        cout << "查找失败：未找到您想查找的联系人" << endl;
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
    cout << "请输入您要修改的联系人：" << endl;
    cin >> findname;
    for (i = 0; i < MAX_CONTACT; i++)
    {
        if (p1[i].name == findname)
        {
            cout << "已找到您要修改的联系人：" << endl;
            SEX = (p1[i].sex == 1) ? "男" : "女";
            cout << "该联系人的现有信息如下：" << endl;
            cout << "姓名：" << p1[i].name << "   性别：" << SEX << "   电话：" << p1[i].tel << "   住址：" << p1[i].address << endl;
            while (1)
            {
                cout << "请输入您要修改的项目：（0：确认修改并退出；1：修改姓名；2：修改性别；3：修改电话号码； 4：修改地址)" << endl;
                cin >> flag;
                switch (flag)
                {
                case 1:
                    cout << "请输入该联系人新的姓名" << endl;
                    cin >> name;
                    p1[i].name = name;
                    break;
                case 2:
                    cout << "请输入该联系人新的性别（1：男；2：女）" << endl;
                    cin >> sex;
                    p1[i].sex = sex;
                    break;
                case 3:
                    cout << "请输入该联系人新的电话号码" << endl;
                    cin >> tel;
                    p1[i].tel = tel;
                    break;
                case 4:
                    cout << "请输入该联系人新的地址" << endl;
                    cin >> address;
                    p1[i].address = address;
                    break;
                case 0:
                    cout << "已修改好该联系人的信息！" << endl;
                    break;
                default:
                    cout << "请输入0-4之间的数字！" << endl;
                }
                if (flag == 0)
                    break;
            }
            SEX = (p1[i].sex == 1) ? "男" : "女";
            cout << "修改后的该联系人的信息如下：" << endl;
            cout << "姓名：" << p1[i].name << "   性别：" << SEX << "   电话：" << p1[i].tel << "   住址：" << p1[i].address << endl;
            no_modified = false;
        }
    }
    if (no_modified)
    {
        cout << "修改失败：未找到您想修改的联系人" << endl;
    }
}

void clear_contact(contact *p1)
{
    for (int i = 0; i < MAX_CONTACT; i++)
    {
        contact init = {"0", 0, 0, "0", "0"};
        p1[i] = init;
    }
    cout << "通讯录已经清空！" << endl;
}

void exit_book(contact *p1)
{
    cout << "欢迎下次使用！" << endl;
}