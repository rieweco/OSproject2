//master.c file
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "master.h"


//fork producer and n consumers
//n will be passed as a parameter
pid_t* createProducerAndConsumers(int numberOfConsumers, pid_t* processIDArray)
{
	//create the producer first
	*processIDArray = fork();

	for(int i = 0; i < numberOfConsumers; i++)
	{
		processIDArray[i] = fork();
	
		//if fork() failed... perror
		if(processID < 0)
		{
			perror("Failed to fork() child process!\n");
			exit(EXIT_FAILURE);
		}
	}
	return processIDArray;
}



//signal handling
//create signal handler

