// ����ģ�尸��
// ���ú���ģ���װһ������ĺ��������ԶԲ�ͬ�������������������
// �������Ӵ�С�������㷨Ϊѡ������
// �ֱ�����char�����int������в���

#include <iostream>
#include <string>
using namespace std;

template <typename T>
void my_swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void my_sort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int max = i; //�϶����ֵ���±�
        for (int j = i + 1; j < len; j++)
        {
            if (arr[max] < arr[j]) //�϶������ֵ�ȱ����������ֵҪС��˵��j�±��Ԫ�ز������������ֵ
            {
                max = j; //�������ֵ��С��
            }
        }
        if (max != i)
        {
            my_swap(arr[i], arr[max]); //����max��i�±�ĺ���
        }
    }
}

template <typename T>
void my_print(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test01()
{
    char arr[] = "asabeef";
    int arr2[] = {1, 3, 5, 3, 7, 7, 1, 2, 3, 4};
    int len1 = sizeof(arr) / sizeof(arr[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    my_sort(arr, len1);
    my_print(arr, len1);
    my_sort(arr2, len2);
    my_print(arr2, len2);
}

void test02()
{
}

int main(void)
{
    test01();
    test02();
    return 0;
}