#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5

struct thread_data
{
	int thread_id;
	char *message;
};

void *PrintHello2(void *threadarg)
{
	struct thread_data *my_data;
	my_data = (struct thread_data *)threadarg;
	string show = "Thread ID = " + to_string(my_data->thread_id) + "\nMessage = " + my_data->message + "\n******** end ********\n";
	cout << show;
	pthread_exit(NULL);
}
/*
   这个实例演示了如何通过结构传递多个参数。您可以在线程回调中传递任意的数据类型，因为它指向 void
 **/
int main()
{
	pthread_t threads[NUM_THREADS];
	struct thread_data td[NUM_THREADS];
	int rc;
	int i;

	for (i = 0; i < NUM_THREADS; i++)
	{
		cout << "main() : creating thread, " << i << endl;
		td[i].thread_id = i;
		td[i].message = (char *)"This is message";
		rc = pthread_create(&threads[i], NULL, PrintHello2, (void *)&td[i]);
		if (rc)
		{
			cout << "Error:unable to create thread," << rc << endl;
			exit(-1);
		}
	}
	pthread_exit(NULL);

	return 0;
}
