#include <iostream>
using namespace std;

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

int main() {
	stu XiaoMing;//C++定义变量的方法，可以省略struct
	XiaoMing.name[0] = 'a';
	XiaoMing.score = 100;
	cout << "C++  score : " << XiaoMing.score << endl;

	struct stu XiaoHong;//C语言定义变量的方法，不能省略struct
	XiaoHong.score = 99;
	cout << "C    score : " << XiaoHong.score << endl;

	return 0;
}
