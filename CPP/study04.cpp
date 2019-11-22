//
//  study04.cpp
//  CPP
//
//  Created by hello on 2019/11/22.
//  Copyright © 2019 Dio. All rights reserved.
//

#include <iostream>
using namespace std;

void func12() {
    double* pvalue  = NULL; // 初始化为 null 的指针
    pvalue  = new double;   // 为变量请求内存
    *pvalue = 29494.99;     // 在分配的地址存储值
    cout << "Value of pvalue : " << *pvalue << endl;
    delete pvalue;         // 释放内存
    
    /************************一维数组*************************/
    // 动态分配
    int *array1=new int [10];
    //释放内存
    delete [] array1;
    
    /************************二维数组*************************/
    int **array;
    // 假定数组第一维长度为m, 第二维长度为n
    // 动态分配空间
    int m = 10;
    int n = 10;
    array = new int *[m];
    for( int i=0; i<m; i++ ){
        array[i] = new int [n];
    }
    //释放
    for( int i=0; i<m; i++ ) {
        delete [] array[i];
    }
    delete [] array;
}

// 基类
class Shape {
public:
    // 提供接口框架的纯虚函数
    virtual int getArea() = 0;
    void setWidth(int w) {
        width = w;
    }
    void setHeight(int h){
        height = h;
    }
protected:
    int width;
    int height;
};
// 派生类
class Rectangle: public Shape {
public:
    int getArea() {
        return (width * height);
    }
};
class Triangle: public Shape {
public:
    int getArea() {
        return (width * height)/2;
    }
};
void func11() {
    Rectangle Rect;
    Triangle  Tri;
    
    Rect.setWidth(5);
    Rect.setHeight(7);
    // 输出对象的面积
    cout << "Total Rectangle area: " << Rect.getArea() << endl;
    
    Tri.setWidth(5);
    Tri.setHeight(7);
    // 输出对象的面积
    cout << "Total Triangle area: " << Tri.getArea() << endl;
}
