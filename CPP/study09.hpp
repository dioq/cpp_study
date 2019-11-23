//
//  study09.hpp
//  CPP
//
//  Created by hello on 2019/11/23.
//  Copyright © 2019 Dio. All rights reserved.
//

/*
 C++ 信号处理
 信号是由操作系统传给进程的中断，会提早终止一个程序。在 UNIX、LINUX、Mac OS X 或 Windows 系统上，可以通过按 Ctrl+C 产生中断。
 有些信号不能被程序捕获，但是下表所列信号可以在程序中捕获，并可以基于信号采取适当的动作。这些信号是定义在 C++ 头文件 <csignal> 中
 **/

void func18();//raise() 函数
void func17();//signal() 函数
