#include <iostream>
#include <string>
using namespace std;

#define MAX_CONTACT 1000

typedef struct Contact
{
    string name;
    int sex;
    int age;
    string tel;
    string address;
} contact;

void add_contact(contact *p1);
void show_contact(contact *p1);
void del_contact(contact *p1);
void find_contact(contact *p1);
void modify_contact(contact *p1);
void clear_contact(contact *p1);
void exit_book(contact *p1);