#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Global variable to change it in threads 

int g = 0; 

// The function to be executed by all threads 

void *myThreadFun(void *vargp)
{
	
	// Store the value argument passed to this thread 
	int *myid = (int *)vargp;
		
	// Static variable to observer it's changes 
	static int s = 0; 

	// Changing static and global variables 
	s++;
	g++; 

	// Print the arguement, static and global variables 
	printf("Thread ID: %d, Static %d, Global: %d\n", *myid, s++, g++);
	
}

int main() 
{
	int i; 
	pthread_t tid; 
	
	// Let us create three threads 
	for(i = 0; i < 3; i++)
		pthread_create(&tid, NULL, myThreadFun, (void *)&tid); 

	pthread_exit(NULL);
	return 0; 
}


