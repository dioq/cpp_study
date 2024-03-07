#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

using namespace std;

#define NUM_THREADS 5

void *wait(void *threadid)
{
	int tid = *((int *)threadid);
	sleep(1);
	string show = "Sleeping in thread\nThread with id : " + to_string(tid) + "     ...exiting\n";
	cout << show;
	pthread_exit(NULL);
}
/*
   pthread_join() 子程序阻碍调用程序，直到指定的 threadid 线程终止为止。当创建一个线程时，它的某个属性会定义它是否是可连接的（joinable）或可分离的（detached）。只有创建时定义为可连接的线程才可以被连接。如果线程创建时被定义为可分离的，则它永远也不能被连接。
   这个实例演示了如何使用 pthread_join() 函数来等待线程的完成。
 **/
int main()
{
	pthread_t threads[NUM_THREADS];
	int indexes[NUM_THREADS]; // 用数组来保存i的值
	pthread_attr_t attr;
	void *status;

	// 初始化并设置线程为可连接的（joinable）
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	int rc;
	int i;
	for (i = 0; i < NUM_THREADS; i++)
	{
		cout << "main() : creating thread, " << i << endl;
		indexes[i] = i;
		rc = pthread_create(&threads[i], NULL, wait, (void *)&(indexes[i]));
		if (rc)
		{
			cout << "Error:unable to create thread," << rc << endl;
			exit(-1);
		}
	}

	// 删除属性，并等待其他线程
	pthread_attr_destroy(&attr);
	for (i = 0; i < NUM_THREADS; i++)
	{
		rc = pthread_join(threads[i], &status);
		if (rc)
		{
			cout << "Error:unable to join," << rc << endl;
			exit(-1);
		}
		string show1 = "Main: completed thread id :" + to_string(i) + "  exiting with status :";
		cout << show1 << status << endl;
	}

	cout << "Main: program exiting." << endl;
	pthread_exit(NULL);

	return 0;
}
