#include <iostream>
#include <stdio.h>
#include <string> //�ṩstring���ͱ���
#include <math.h>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};
//�ṹ��Ƕ��
struct Teacher
{
    string name;
    int age;
    int id;
    struct Student *student;
};
//�ṹ���ַ��Ϊ��������
void printscore(struct Student *pointer);
//����2�ṹ�嶨��
struct Hero
{
    string name;
    int age;
    string sex;
};
void bubble_sort(struct Hero *arr, int len);

/*********************������**************************/
int main(void)
{
    //�ṹ�嶨��
    struct Student s1;
    s1.name = "����";
    s1.age = 18;
    s1.score = 99;
    struct Student s2 = {"����", 17, 98};
    //�ṹ������
    struct Student s3[] = {{"���", 16, 78}, {"���", 19, 89}};
    for (int i = 0; i < (sizeof(s3) / sizeof(s3[1])); i++)
    {
        cout << s3[i].name << endl;
    }
    //�ṹ��(����)ָ��
    struct Student *p;
    p = s3;
    for (int i = 0; i < (sizeof(s3) / sizeof(s3[0])); i++, p++)
    {
        cout << p->name << endl;
    }

    //�ṹ��Ƕ��
    struct Teacher t1;
    t1.name = "���";
    t1.age = 35;
    t1.id = 45678902;
    t1.student = &s1;
    cout << "�����ʦ��ѧ���������ǣ�" << t1.student->name << endl;
    //����1��3����ʦ��ÿλ��ʦ��5��ѧ���������ʦ��ѧ���Ľṹ�壬������ʦ�ṹ���У�����ʦ������һ�����5��ѧ���Ľ�����Ϊ��Ա��ѧ���ĳ�Ա
    struct Student s4[] = {{"���1", 17, 76}, {"���2", 16, 79}, {"���3", 18, 67}, {"���4", 19, 88}, {"���5", 20, 99}};
    struct Student s5[] = {{"ʢ��1", 17, 76}, {"ʢ��2", 16, 79}, {"ʢ��3", 18, 67}, {"ʢ��4", 19, 88}, {"ʢ��5", 20, 99}};
    struct Student s6[] = {{"����1", 17, 76}, {"����2", 16, 79}, {"����3", 18, 67}, {"����4", 19, 88}, {"����5", 20, 99}};
    struct Teacher t_arr[] = {{"���", 36, 12332144, s4}, {"ʢ��", 19, 81232459, s5}, {"����", 19, 86542329, s6}};
    cout << sizeof(t_arr) / sizeof(t_arr[0]) << endl;
    cout << sizeof(t_arr[0].student[0]) << endl; //t_arr[0].student��һ��ָ��ṹ�������е�һ���ṹ��ַ��ָ��

    for (int i = 0; i < (sizeof(t_arr) / sizeof(t_arr[0])); i++)
    {
        for (int j = 0; j < sizeof(s4) / sizeof(s4[0]); j++)
        {
            cout << t_arr[i].name << "��ʦ����ţ�" << t_arr[i].id << "; ���䣺" << t_arr[i].age << "���ĵ�" << (j + 1)
                 << "��ѧ������Ϣ: ������" << t_arr[i].student[j].name << "�����䣺" << t_arr[i].student[j].age << "��������" << t_arr[i].student[j].score << endl;
        }
    }
    // ����2:���һ��Ӣ�۵Ľṹ�壬������Ա���������䣬�Ա𡣴����ṹ�����飬�����д��5��Ӣ�ۣ�ͨ��ð��������㷨���������е�Ӣ�۰���������������У����մ�ӡ�����Ľ��
    struct Hero hero_arr[] = {{"����", 23, "��"}, {"����", 24, "��"}, {"�ŷ�", 21, "��"}, {"����", 20, "��"}, {"����", 18, "Ů"}};
    bubble_sort(hero_arr, sizeof(hero_arr) / sizeof(hero_arr[0]));
    for (int i = 0; i < (sizeof(hero_arr) / sizeof(hero_arr[0])); i++)
    {
        cout << hero_arr[i].name << "�����䣺" << hero_arr[i].age << endl;
    }

    //���ú���
    p = &s1;
    printscore(p);
    return 0;
}

/***********************������������***************************/
//�ṹ���ַ��Ϊ��������
void printscore(struct Student *pointer)
{
    cout << pointer->name << "�ķ����ǣ�" << pointer->score << endl;
}
//�ṹ��ָ����Ϊ������ð�������㷨�����Ķ���
void bubble_sort(struct Hero *arr, int len)
{
    int i = 0;
    int j = 0;
    struct Hero temp;
    for (i = 0, j = 0; i < (len - j); i = 0, j++)
    {
        for (i = 0; i < (len - j - 1); i++)
        {
            if (arr[i].age > arr[i + 1].age) // ��������ֻ�轫������Ϊarr3[i] <arr3[i + 1]
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}