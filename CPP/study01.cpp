//
//  study01.cpp
//  CPP
//
//  Created by hello on 2019/11/22.
//  Copyright © 2019 Dio. All rights reserved.
//

#include <iostream>
using namespace std;

#include <iomanip>
using std::setw;

#include <cstring>
#include <string>


/*
 C语言的结构体和C++的结构体的区别:
 1.定义好结构体之后，使用这个结构体类型的时候，C语言里需要写关键字 struct ，而 C++里可以省略不写
 2.C的结构体内不允许有函数存在，C++允许有内部成员函数，且允许该函数是虚函数。
 所以C的结构体是没有构造函数、析构函数、和this指针的。
 3.C的结构体对内部成员变量的访问权限只能是public，而C++允许public,protected,private三种。
 4.C语言的结构体是不可以继承的，C++的结构体是可以从其他的结构体或者类继承过来的。
 **/
//定义好结构体类型
struct stu {
    char name[10];//注意，因为结构体是一种类型，所以不能在定义这种类型时初始化变量。
    int score;
};
void func06(){
    stu XiaoMing;//C++定义变量的方法，可以省略struct
    XiaoMing.name[0] = 'a';
    XiaoMing.score = 100;
    cout << "C++  score : " << XiaoMing.score << endl;
    struct stu XiaoHong;//C语言定义变量的方法，不能省略struct
    XiaoHong.score = 99;
    cout << "C    score : " << XiaoHong.score << endl;
}

/*
 引用变量是一个别名，也就是说，它是某个已存在变量的另一个名字。一旦把引用初始化为某个变量，就可以使用该引用名称或变量名称来指向变量。
 
 引用很容易与指针混淆，它们之间有三个主要的不同：
 不存在空引用。引用必须连接到一块合法的内存。
 一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。
 引用必须在创建时被初始化。指针可以在任何时间被初始化。
 **/
void func05() {
    // 声明简单的变量
    int    i;
    double d;
    
    // 声明引用变量
    int&    r = i;
    double& s = d;
    
    i = 5;
    cout << "Value of i : " << i << endl;
    cout << "Value of i reference : " << r  << endl;
    
    d = 11.7;
    cout << "Value of d : " << d << endl;
    cout << "Value of d reference : " << s  << endl;
}

void func04(){
    int  var = 20;   // 实际变量的声明
    int  *ip;        // 指针变量的声明
    
    ip = &var;       // 在指针变量中存储 var 的地址
    
    cout << "Value of var variable: ";
    cout << var << endl;
    
    // 输出在指针变量中存储的地址
    cout << "Address stored in ip variable: ";
    cout << ip << endl;
    
    // 访问指针中地址的值
    cout << "Value of *ip variable: ";
    cout << *ip << endl;
}

void func03(){
    char str1[11] = "Hello";
    char str2[11] = "World";
    char str3[11];
    unsigned long len;
    
    // 复制 str1 到 str3
    strcpy(str3, str1);
    cout << "strcpy(str3, str1) : " << str3 << endl;
    
    // 连接 str1 和 str2
    strcat(str1, str2);
    cout << "strcat(str1, str2): " << str1 << endl;
    
    // 连接后，str1 的总长度
    len = strlen(str1);
    cout << "strlen(str1) : " << len << endl;
    
    /******************** C++ 中的 String 类 **********************/
    cout << "******************** C++ 中的 String 类 **********************" << endl;
    string str10 = "Hello";
    string str20 = "World";
    string str30;
    unsigned long len0;
    
    // 复制 str10 到 str30
    str30 = str10;
    cout << "str30 : " << str30 << endl;
    
    // 连接 str10 和 str20
    str30 = str10 + str20;
    cout << "str10 + str20 : " << str30 << endl;
    
    // 连接后，str30 的总长度
    len0 = str30.size();
    cout << "str30.size() :  " << len0 << endl;
}

/*
 static 存储类指示编译器在程序的生命周期内保持局部变量的存在，而不需要在每次它进入和离开作用域时进行创建和销毁。因此，使用 static 修饰局部变量可以在函数调用之间保持局部变量的值。
 static 修饰符也可以应用于全局变量。当 static 修饰全局变量时，会使变量的作用域限制在声明它的文件内。
 在 C++ 中，当 static 用在类数据成员上时，会导致仅有一个该成员的副本被类的所有对象共享。
 **/
//函数声明
void func02Test(void);
static int count2 = 10; /* 全局变量 */
void func02() {
    while(count2--) {
        func02Test();
    }
}
// 函数定义
void func02Test(void) {
    static int i = 5; // 局部静态变量
    i++;
    cout << "变量 i 为 " << i ;
    cout << " , 变量 count2 为 " << count2 << endl;
}

void func01() {
    int n[10]; // n 是一个包含 10 个整数的数组
    // 初始化数组元素
    for (int i = 0; i < 10; i++) {
        n[i] = i + 100; // 设置元素 i 为 i + 100
    }
    cout << "Element" << setw(13) << "Value" << endl;
    
    // 输出数组中每个元素的值
    for (int j = 0; j < 10; j++) {
        cout << setw(7)<< j << setw(13) << n[j] << endl;
    }
}
