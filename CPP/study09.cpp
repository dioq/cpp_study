//
//  study09.cpp
//  CPP
//
//  Created by hello on 2019/11/23.
//  Copyright © 2019 Dio. All rights reserved.
//

#include <iostream>
#include <csignal>
#include <unistd.h>

using namespace std;


/*
 您可以使用函数 raise() 生成信号，该函数带有一个整数信号编号作为参数
 **/
void signalHandler2(int signum) {
    cout << "Interrupt signal (" << signum << ") received.\n";
    // 清理并关闭
    // 终止程序
    exit(signum);
}
void func18() {
    int i = 0;
    // 注册信号 SIGINT 和信号处理程序
    signal(SIGINT, signalHandler2);
    
    while(++i){
        cout << "Going to sleep...." << endl;
        if( i == 3 ){
            raise(SIGINT);
        }
        sleep(1);
    }
}


/*
 C++ 信号处理库提供了 signal 函数，用来捕获突发事件。
 这个函数接收两个参数：第一个参数是一个整数，代表了信号的编号；第二个参数是一个指向信号处理函数的指针。
 让我们编写一个简单的 C++ 程序，使用 signal() 函数捕获 SIGINT 信号。不管您想在程序中捕获什么信号，您都必须使用 signal 函数来注册信号，并将其与信号处理程序相关联。
 **/
void signalHandler(int signum) {
    cout << "Interrupt signal (" << signum << ") received.\n";
    // 清理并关闭
    // 终止程序
    exit(signum);
}
void func17() {
    // 注册信号 SIGINT 和信号处理程序
    signal(SIGINT, signalHandler);
    while(1){
        cout << "Going to sleep...." << endl;
        sleep(1);
    }
}
