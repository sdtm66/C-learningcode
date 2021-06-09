//构造函数：主要作用在于创建对象时为对象的成员属性赋值，构造函数由编译器自动调用，无须手动调用；
//语法：类名（）{}。1 构造函数，没有返回值也不写void；2 构造函数名与类名相同；
//3 构造函数可以有参数，因此可以发生重载； 4 程序在调用对象的时候会自动调用构造函数，无须手动调用，而且只会调用一次
//分类：有参构造与无参构造（默认构造）；普通构造与拷贝构造。拷贝构造语法：  类名（const 类名 &实例名）
// 三种调用方式：括号法；显示法；隐式转换法
//拷贝构造函数调用的三种情况：1 使用一个已经创建完毕的对象来初始化一个新对象；2 值传递的方式给函数参数传值； 3 以值方式返回局部对象
//默认情况下，c++编译器至少给一个类添加3个函数：1 默认无参构造函数；2 默认析构函数； 3 默认拷贝构造函数，对属性进行值拷贝
//构造函数的调用规则如下：如果用户定义有参构造函数，c++不再提供默认无参构造函数，但会提供默认拷贝构造函数
//如果用户定义拷贝构造函数，c++不再提供其他构造函数

//析构函数：主要作用于对象销毁前系统自动调用，执行一些工作
//语法：~类名（）{}。1 析构函数，没有返回值也不写void；2 析构函数名与类名相同，在名称前面加上符号~；
//3 析构构造函数不可以有参数，因此不可以发生重载；4 程序在调用对象的时候会自动调用构造函数，无须手动调用，而且只会调用一次
//析构函数代码，可以将堆区开辟的数据做释放操作
//
//浅拷贝：简单的赋值拷贝操作,浅拷贝带来的问题是堆区的数据会重新释放，然后就报错了
//深拷贝：在堆区重新申请空间，进行拷贝操作
//编译器默认的拷贝构造函数只执行浅拷贝，
//
//C++类中的成员可以是另一个类的对象，我们称该成员为对象成员.
//当其他类对象作为本类成员，构造时候先构造类对象，再构造自身。析构时顺序相反
//
//静态成员变量：所有对象共享同一份数据；在编译阶段分配内存；类内声明，类外初始化；
//静态成员函数：所有对象共享同一个函数；静态成员函数只能访问静态成员变量
//
//在C++中，类内的成员变量和成员函数分开存储。只有非静态成员变量才属于类的对象上
//空对象占用内存空间为：1.C++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
//
//this指针用于指向被调用的成员函数所属的对象。this指针是隐含在每一个非静态成员函数内d额指针。this指针不需要定义，直接使用即可。
//this指针的用途：当形参和成员变量同名时，可用this指针来区分；在类的非静态成员函数中返回对象本身，可使用return *this
//this指针的本质：是指针常量，指针指向的地址是不可以修改的，但this指针指向的值可以修改
// 在成员函数后面加const，修饰的是this指向，让指针指向的值也不可以修改。 void 函数名（） const {} 。除非该对象的变量是mutable： 如mutable int b；
//在对象前加const，变为常对象，常对象只能调用常函数
#include <iostream>
#include <string>
using namespace std;

class Phone
{
private:
    string brand;
    double price;
    int number;
    static int ID;

public:
    Phone() : brand("Apple"), price(8000), number(8) {}
    Phone(string brand1, double price1, int number1) : brand(brand1), price(price1), number(number1) {}
    //~Phone();
    static void func()
    {
        ID = 88; //静态成员函数只能使用静态成员变量，因为其无法区分普通成员变量的值是来自哪一个对象
        cout << "static void func()函数调用:" << ID << endl;
    }
};
int Phone::ID = 36; //静态成员变量只能在类外初始化

class Person
{
private:
    string name;
    int age;
    string tel;
    int *height;

public:
    //无参构造函数（默认构造函数）;初始化列表赋初值
    Person() : name("潘航"), age(25), tel("18818216215"), height(new int(180))
    {
        // name = "潘航";
        // age = 25;
        // tel = "18818216215";
        // height = new int(180);
        cout << "Person无参构造函数调用，创建的对象信息："
             << "姓名：" << name << "; 年龄：" << age << "; 电话号码：" << tel << "; 身高：" << *height << endl;
    }
    //有参构造函数;初始化列表赋初值
    Person(string name1, int age1, string tel1, int height1) : name(name1), age(age1), tel(tel1), height(new int(height1))
    {
        // name = name1;
        // age = age1;
        // tel = tel1;
        // height = new int(height1);
        cout << "Person有参构造函数调用，创建的对象信息："
             << "姓名：" << name << "; 年龄：" << age << "; 电话号码：" << tel << "; 身高：" << *height << endl;
    }
    //拷贝构造函数
    Person(const Person &p) : name(p.name), age(p.age), tel(p.tel), height(new int(*p.height)) //类对象的常量引用
    {
        // name = p.name;
        // age = p.age;
        // tel = p.tel;
        // //height = p.height;编译器默认执行这行代码，即浅拷贝，会带来堆区重复释放的问题
        // height = new int(*p.height); // 深拷贝：在堆区重新申请空间，进行拷贝操作
        cout << "Person拷贝构造函数调用，创建的对象信息："
             << "姓名：" << name << "; 年龄：" << age << "; 电话号码：" << tel << "; 身高：" << *height << endl;
    }

    ~Person()
    {
        cout << "Person析构函数调用，销毁的对象信息："
             << "姓名：" << name << "; 年龄：" << age << "; 电话号码：" << tel << "; 身高：" << *height << endl;
        if (height != NULL)
        {
            delete height;
            height = NULL;
        }
    }

public:
    void showinfo()
    {
        cout << "姓名：" << name << "; 年龄：" << age << "; 电话号码：" << tel << "; 身高：" << *height << endl;
    }
};

class Storage
{
private:
    //只有非静态成员变量才属于类的对象上，即创建的所有对象都只有4个字节
    int a;                 //非静态成员变量 属于类的对象上
    static int b;          //静态成员变量 不属于类的对象上
    void func() {}         //非静态成员函数 不属于类的对象上
    static void func1() {} //静态成员函数 不属于类的对象上
};
int Storage::b = 10;

class Age
{
public:
    int age;

public:
    Age() : age(0) {}
    Age(int age)
    {
        this->age = age;
    }
    Age &addage(Age &p)
    {
        //如果对象指针为空，则返回原对象，提高代码的健壮性
        if (this == NULL)
        {
            return *this;
        }
        this->age += p.age;
        return *this; //在类的非静态成员函数中返回对象本身，可使用return *this
    }
    void showage()
    {
        cout << "age值： " << this->age << endl;
    }
};

int main(void)
{
    //括号法调用构造函数
    Person p1;                                   //无参构造
    Person p2("李丽娜", 25, "15151801379", 165); //有参构造
    Person p3(p2);                               //拷贝构造
    cout << "p1的信息：" << endl;
    p1.showinfo();
    cout << "p2的信息：" << endl;
    p2.showinfo();
    cout << "p3的信息：" << endl;
    p3.showinfo();
    //显示法调用构造函数
    Person p4;                                            //无参构造
    Person p5 = Person("李丽娜", 25, "15151801379", 165); //有参构造；Person("李丽娜", 25, "15151801379")是匿名对象：当前执行结束后，系统会立即回收掉匿名对象
    Person p6 = Person(p5);                               //拷贝构造；不要单独利用拷贝构造函数，初始化匿名对象，Person(p5)；编译器会认为Person(p5)==Person p5
    //隐式转换法
    Person p7 = p5; //拷贝构造

    //静态成员函数
    //访问方式1：通过对象访问
    Phone phone1;
    phone1.func();

    //访问方式2：通过类名访问
    Phone::func();

    //对象内存
    Storage s1;
    cout << "size of s1: " << sizeof(s1) << endl;

    //this指针
    Age age1;
    Age age2(10);
    age1.addage(age2).addage(age2); //链式编程思想
    cout << "age1的age值： " << age1.age << endl;
    //空指针
    Age *age3 = NULL;
    age3->showage();

    cout << "请按任意键结束程序..." << endl;
    cout << "程序结束时，创建的所有变量和对象数据将被销毁！" << endl;
    system("pause");
    return 0;
}