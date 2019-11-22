//
//  study02.cpp
//  CPP
//
//  Created by hello on 2019/11/22.
//  Copyright © 2019 Dio. All rights reserved.
//

#include <iostream>
using namespace std;

// 基类 Shape
class Shape {
public:
    void setWidth(int w) {
        width = w;
    }
    void setHeight(int h) {
        height = h;
    }
protected:
    int width;
    int height;
};
// 基类 PaintCost
class PaintCost {
public:
    int getCost(int area) {
        return area * 70;
    }
};
// 派生类
class Rectangle: public Shape, public PaintCost {//C++ 支持多继承
public:
    int getArea() {
        return (width * height);
    }
};
void func08(){
    Rectangle Rect;
    int area;
    
    Rect.setWidth(5);
    Rect.setHeight(7);
    
    area = Rect.getArea();
    
    // 输出对象的面积
    cout << "Total area: " << Rect.getArea() << endl;
    // 输出总花费
    cout << "Total paint cost: $" << Rect.getCost(area) << endl;
}

class Box {
public:
    double length;   // 长度
    double breadth;  // 宽度
    double height;   // 高度
};
void func07(){
    Box Box1;        // 声明 Box1，类型为 Box
    Box Box2;        // 声明 Box2，类型为 Box
    double volume = 0.0;     // 用于存储体积
    
    // box 1 详述
    Box1.height = 5.0;
    Box1.length = 6.0;
    Box1.breadth = 7.0;
    
    // box 2 详述
    Box2.height = 10.0;
    Box2.length = 12.0;
    Box2.breadth = 13.0;
    
    // box 1 的体积
    volume = Box1.height * Box1.length * Box1.breadth;
    cout << "Box1 的体积：" << volume <<endl;
    
    // box 2 的体积
    volume = Box2.height * Box2.length * Box2.breadth;
    cout << "Box2 的体积：" << volume <<endl;
}
