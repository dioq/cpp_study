#include <iostream>
using namespace std;

int main()
{
	double *pvalue = NULL; // 初始化为 null 的指针
	pvalue = new double;   // 为变量请求内存
	*pvalue = 29494.99;	   // 在分配的地址存储值
	cout << "Value of pvalue : " << *pvalue << endl;
	delete pvalue; // 释放内存

	/************************一维数组*************************/
	// 动态分配
	int *array1 = new int[10];
	// 释放内存
	delete[] array1;

	/************************二维数组*************************/
	int **array;
	// 假定数组第一维长度为m, 第二维长度为n
	// 动态分配空间
	int m = 10;
	int n = 10;
	array = new int *[m];
	for (int i = 0; i < m; i++)
	{
		array[i] = new int[n];
	}
	// 释放
	for (int i = 0; i < m; i++)
	{
		delete[] array[i];
	}
	delete[] array;

	return 0;
}
