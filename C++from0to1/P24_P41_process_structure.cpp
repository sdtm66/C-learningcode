#include <iostream>
#include <stdio.h>
#include <string> //提供string类型变量
#include <math.h>
using namespace std;

int main(void)
{
    int a = 20;
    int b = 30;
    int c = 0;
    int score = 0;
    bool out = false;
    int i = 100;
    int count = 0;
    //三目运算符
    c = (a > b) ? a : b;
    cout << "三目运算符结果：" << c << endl;
    //while循环与switch语句
    while (1)
    {
        cout << "请给这部电影打分（1-10）：" << endl;
        cin >> score;
        switch (score)
        {
        case 10:
        case 9:
        case 8:
            cout << "你认为这是一部优秀的电影。" << endl;
            out = true;
            break;
        case 7:
        case 6:
            cout << "你认为这是一部及格的电影。" << endl;
            out = true;
            break;
        case 5:
        case 4:
        case 3:
        case 2:
        case 1:
            cout << "你认为这是一部不及格的电影。" << endl;
            out = true;
            break;
        default:
            cout << "你必须输入1-10之间的分数" << endl;
            break;
        }
        if (out)
            break;
    }
    // do while循环：水仙花数
    do
    {
        if ((pow((i - i % 100) / 100, 3) + pow(((i % 100) - (i % 100) % 10) / 10, 3) + pow((i % 100) % 10, 3)) == i)
        {
            count += 1;
            cout << "找到第" << count << "个水仙花数： " << i << endl;
        }
        //cout << i << endl;
        i++;
    } while (i <= 999);

    system("pause");
    return 0;
}