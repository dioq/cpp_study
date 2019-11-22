//
//  study03.cpp
//  CPP
//
//  Created by hello on 2019/11/22.
//  Copyright © 2019 Dio. All rights reserved.
//

#include <iostream>
using namespace std;

class Adder{
public:
    // 构造函数
    Adder(int i = 0) {
        total = i;
    }
    // 对外的接口
    void addNum(int number) {
        total += number;
    }
    // 对外的接口
    int getTotal() {
        return total;
    };
private:
    // 对外隐藏的数据
    int total;
};
void func10(){
    Adder a;
    
    a.addNum(10);
    a.addNum(20);
    a.addNum(30);
    
    cout << "Total " << a.getTotal() <<endl;
}


class Shape {
protected:
    int width, height;
public:
    Shape( int a=0, int b=0) {
        width = a;
        height = b;
    }
    int area() {
        cout << "Parent class area :" <<endl;
        return 0;
    }
};
class Rectangle: public Shape{
public:
    Rectangle( int a=0, int b=0):Shape(a, b) { }
    int area () {
        cout << "Rectangle class area :" <<endl;
        return (width * height);
    }
};
class Triangle: public Shape{
public:
    Triangle( int a=0, int b=0):Shape(a, b) { }
    int area () {
        cout << "Triangle class area :" <<endl;
        return (width * height / 2);
    }
};
void func09(){
    Shape *shape;
    Rectangle rec(10,7);
    Triangle  tri(10,5);
    
    // 存储矩形的地址
    shape = &rec;
    // 调用矩形的求面积函数 area
    shape->area();
    
    // 存储三角形的地址
    shape = &tri;
    // 调用三角形的求面积函数 area
    shape->area();
}
