#include <iostream>
#include <stdio.h>
#include <string> //�ṩstring���ͱ���
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
    int j = 1;
    int count = 0;

    //��Ŀ�����
    c = (a > b) ? a : b;
    cout << "��Ŀ����������" << c << endl;

    //whileѭ����switch���
    while (1)
    {
        cout << "����ⲿ��Ӱ��֣�1-10����" << endl;
        cin >> score;
        switch (score)
        {
        case 10:
        case 9:
        case 8:
            cout << "����Ϊ����һ������ĵ�Ӱ��" << endl;
            out = true;
            break;
        case 7:
        case 6:
            cout << "����Ϊ����һ������ĵ�Ӱ��" << endl;
            out = true;
            break;
        case 5:
        case 4:
        case 3:
        case 2:
        case 1:
            cout << "����Ϊ����һ��������ĵ�Ӱ��" << endl;
            out = true;
            break;
        default:
            cout << "���������1-10֮��ķ���" << endl;
            break;
        }
        if (out)
            break;
    }

    // do whileѭ����ˮ�ɻ�������λ�����η�+ʮλ�����η�+��λ�����η�=��������֣�
    do
    {
        if ((pow((i - i % 100) / 100, 3) + pow(((i % 100) - (i % 100) % 10) / 10, 3) + pow((i % 100) % 10, 3)) == i)
        {
            count += 1;
            cout << "�ҵ���" << count << "��ˮ�ɻ����� " << i << endl;
        }
        //cout << i << endl;
        i++;
    } while (i <= 999);

    // forѭ����䣺������(��1-100��������ָ�λ����7����������ʮλ����7�����߸�������7�ı�������ӡ�����ӣ�����ֱ�Ӵ�ӡ����)
    for (i = 1; i < 100; i++)
    {
        if ((i % 10 == 7) || ((i - i % 10) / 10 == 7) || (i % 7 == 0))
            cout << "������" << endl;
        else
            cout << i << endl;
    }

    // Ƕ��ѭ�����˷��ھ���
    for (i = 1; i < 10; i++)
    {
        for (j = 1; j < 10; j++)
        {
            cout << i << "��" << j << "=" << (i * j) << endl;
        }
    }

    // go to���
    cout << "1" << endl;
    goto flag;
    cout << "2" << endl;
    cout << "3" << endl;
flag:
    cout << "4" << endl;
    cout << "5" << endl;

    system("pause");
    return 0;
}