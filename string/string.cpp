#include <iostream>
#include <cstring>

using namespace std;

int main() {
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

	return 0;
}
