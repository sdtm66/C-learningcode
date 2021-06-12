// 函数模板案例
// 利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
// 排序规则从大到小，排序算法为选择排序
// 分别利用char数组和int数组进行测试

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
        int max = i; //认定最大值的下标
        for (int j = i + 1; j < len; j++)
        {
            if (arr[max] < arr[j]) //认定的最大值比遍历出的最大值要小，说明j下标的元素才是真正的最大值
            {
                max = j; //更新最大值的小标
            }
        }
        if (max != i)
        {
            my_swap(arr[i], arr[max]); //交换max和i下标的函数
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