#include <iostream>
#include <stdio.h>
#include <string> //提供string类型变量
#include <math.h>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};
//结构体嵌套
struct Teacher
{
    string name;
    int age;
    int id;
    struct Student *student;
};
//结构体地址作为函数参数
void printscore(struct Student *pointer);
//案例2结构体定义
struct Hero
{
    string name;
    int age;
    string sex;
};
void bubble_sort(struct Hero *arr, int len);

/*********************主函数**************************/
int main(void)
{
    //结构体定义
    struct Student s1;
    s1.name = "张三";
    s1.age = 18;
    s1.score = 99;
    struct Student s2 = {"李四", 17, 98};
    //结构体数组
    struct Student s3[] = {{"万达", 16, 78}, {"深度", 19, 89}};
    for (int i = 0; i < (sizeof(s3) / sizeof(s3[1])); i++)
    {
        cout << s3[i].name << endl;
    }
    //结构体(数组)指针
    struct Student *p;
    p = s3;
    for (int i = 0; i < (sizeof(s3) / sizeof(s3[0])); i++, p++)
    {
        cout << p->name << endl;
    }

    //结构体嵌套
    struct Teacher t1;
    t1.name = "李红";
    t1.age = 35;
    t1.id = 45678902;
    t1.student = &s1;
    cout << "李红老师的学生的姓名是：" << t1.student->name << endl;
    //案例1：3名老师，每位老师带5名学生。设计老师和学术的结构体，其中老师结构体中，有老师姓名和一个存放5名学生的教组作为成员。学术的成员
    struct Student s4[] = {{"万达1", 17, 76}, {"万达2", 16, 79}, {"万达3", 18, 67}, {"万达4", 19, 88}, {"万达5", 20, 99}};
    struct Student s5[] = {{"盛大1", 17, 76}, {"盛大2", 16, 79}, {"盛大3", 18, 67}, {"盛大4", 19, 88}, {"盛大5", 20, 99}};
    struct Student s6[] = {{"塞法1", 17, 76}, {"塞法2", 16, 79}, {"塞法3", 18, 67}, {"塞法4", 19, 88}, {"塞法5", 20, 99}};
    struct Teacher t_arr[] = {{"万达", 36, 12332144, s4}, {"盛大", 19, 81232459, s5}, {"塞法", 19, 86542329, s6}};
    cout << sizeof(t_arr) / sizeof(t_arr[0]) << endl;
    cout << sizeof(t_arr[0].student[0]) << endl; //t_arr[0].student是一个指向结构体数组中第一个结构地址的指针

    for (int i = 0; i < (sizeof(t_arr) / sizeof(t_arr[0])); i++)
    {
        for (int j = 0; j < sizeof(s4) / sizeof(s4[0]); j++)
        {
            cout << t_arr[i].name << "老师（编号：" << t_arr[i].id << "; 年龄：" << t_arr[i].age << "）的第" << (j + 1)
                 << "个学生的信息: 姓名：" << t_arr[i].student[j].name << "；年龄：" << t_arr[i].student[j].age << "；分数：" << t_arr[i].student[j].score << endl;
        }
    }
    // 案例2:设计一个英雄的结构体，包括成员姓名，年龄，性别。创建结构体数组，数组中存放5名英雄，通过冒泡排序的算法，将数组中的英雄按年龄进行升序排列，最终打印排序后的结果
    struct Hero hero_arr[] = {{"关羽", 23, "男"}, {"刘备", 24, "男"}, {"张飞", 21, "男"}, {"赵云", 20, "男"}, {"貂蝉", 18, "女"}};
    bubble_sort(hero_arr, sizeof(hero_arr) / sizeof(hero_arr[0]));
    for (int i = 0; i < (sizeof(hero_arr) / sizeof(hero_arr[0])); i++)
    {
        cout << hero_arr[i].name << "，年龄：" << hero_arr[i].age << endl;
    }

    //调用函数
    p = &s1;
    printscore(p);
    return 0;
}

/***********************其他函数定义***************************/
//结构体地址作为函数参数
void printscore(struct Student *pointer)
{
    cout << pointer->name << "的分数是：" << pointer->score << endl;
}
//结构体指针作为参数的冒泡排序算法函数的定义
void bubble_sort(struct Hero *arr, int len)
{
    int i = 0;
    int j = 0;
    struct Hero temp;
    for (i = 0, j = 0; i < (len - j); i = 0, j++)
    {
        for (i = 0; i < (len - j - 1); i++)
        {
            if (arr[i].age > arr[i + 1].age) // 降序排列只需将条件改为arr3[i] <arr3[i + 1]
            {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}