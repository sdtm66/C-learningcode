//文件操作
//程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放
//通过文件可以将数据持久化
//C++中对文件操作需要包含头文件<fstream>
// 文件类型：
//（1）文本文件：文件以文本的ASCII码形式存储在计算机中
//（2）二进制文件：文件以文本的二进制形式存储在计算机中，用户一般不能直接读懂他们
//操作文本文件的三大类：ofstream类：读文件；ifstream类：写文件；fstream类：读写文件
// 写文件：1 包含头文件 #include <fstream> 2 创建流对象 ofstream ofs； 3 打开文件 ofs.open（'文件路径'，打开方式） 4 写数据 ofs << "写入的数据" 5 关闭文件 ofs.close（）
// 文件打开方式：iOS::in 为读文件而打开文件；ios::out 为写文件而打开文件；ios::ate 初始位置：文件尾部；
// ios::app 通过追加方式写文件；ios::trunc 如果文件存在，先删除再创建；ios::binary 二进制方式
// 注意：文件打开方式可以配合使用，利用|操作符。例如：用二进制方式写文件  ios::binary | ios::out
//读文件：1 包含头文件 #include <fstream> 2 创建流对象 ifstream ofs； 3 打开文件 ifs.open（'文件路径'，打开方式） 4 读数据 四种方式读取 5 关闭文件 ifs.close（）
#include <iostream>
#include <string>
#include <fstream> //包含头文件 #include <fstream>
using namespace std;

void test01()
{
    ofstream ofs("test.txt", ios::out); //创建流对象并打开文件
    ofs << "姓名：张三" << endl;        //写数据
    ofs << "姓名：李四" << endl;        //写数据
    ofs.close();                        //关闭文件
}

void test02()
{
    ifstream ifs;
    ifs.open("test.txt", ios::in);
    if (!ifs.is_open()) //利用is_open函数判断文件是否打开成功
    {
        cout << "文件打开失败" << endl;
        return;
    }
    //第一种读数据方法
    // char buf[1024] = {0};
    // while (ifs >> buf)
    // {
    //     cout << buf << endl;
    // }
    //第二种读数据方法
    // char buf[1024] = {0};
    // while (ifs.getline(buf, sizeof(buf)))
    // {
    //     cout << buf << endl;
    // }
    //第三种读数据方法
    // string buf;
    // while (getline(ifs, buf))
    // {
    //     cout << buf << endl;
    // }
    //第四种读数据方法
    char c;
    while ((c = ifs.get()) != EOF) //EOF end of file
    {
        cout << c;
    }

    ifs.close();
}

int main(void)
{
    //test01();
    test02();
    return 0;
}