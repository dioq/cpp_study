//
//  study10.cpp
//  CPP
//
//  Created by hello on 2019/11/23.
//  Copyright © 2019 Dio. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;


template <class T>
class Stack {
private:
    vector<T> elems;     // 元素
public:
    void push(T const&);  // 入栈
    void pop();               // 出栈
    T top() const;            // 返回栈顶元素
    bool empty() const{       // 如果为空则返回真。
        return elems.empty();
    }
};
template <class T>
void Stack<T>::push (T const& elem) {
    // 追加传入元素的副本
    elems.push_back(elem);
}
template <class T>
void Stack<T>::pop () {
    if (elems.empty()) {
        throw out_of_range("Stack<>::pop(): empty stack");
    }
    // 删除最后一个元素
    elems.pop_back();
}
template <class T>
T Stack<T>::top () const {
    if (elems.empty()) {
        throw out_of_range("Stack<>::top(): empty stack");
    }
    // 返回最后一个元素的副本
    return elems.back();
}
void func20() {
    try {
        Stack<int>         intStack;  // int 类型的栈
        Stack<string> stringStack;    // string 类型的栈
        
        // 操作 int 类型的栈
        intStack.push(7);
        cout << intStack.top() <<endl;
        
        // 操作 string 类型的栈
        stringStack.push("hello");
        cout << stringStack.top() << endl;
        stringStack.pop();
        stringStack.pop();
    } catch (exception const& ex) {
        cerr << "Exception: " << ex.what() <<endl;
    }
}


template <typename T>
inline T const& Max (T const& a, T const& b) {
    return a < b ? b:a;
}
void func19() {
    int i = 39;
    int j = 20;
    cout << "Max(i, j): " << Max(i, j) << endl;
    
    double f1 = 13.5;
    double f2 = 20.7;
    cout << "Max(f1, f2): " << Max(f1, f2) << endl;
    
    string s1 = "Hello";
    string s2 = "World";
    cout << "Max(s1, s2): " << Max(s1, s2) << endl;
}
