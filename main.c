//main.c
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <getopt.h>
#include "makeargv.h"
#include <errno.h>
#include "consumer.h"
#include "producer.h"
#include "master.h"

#define SHMSZ 100
#define MAX_BUFFER 100
#define MAX_LINE 100
#define MAX_RUNNING 20
#define DEFAULT_CONSUMERS 10
#define MAX_RUNTIME 100


int main(int argc, char *argv[])
{
	
	//create array of processIDs
	pid_t* processIDArray;

	int numberOfConsumers = DEFAULT_CONSUMERS;
	int opt = 0;
	
	char line[MAX_LINE];

	if(argc == 1)
	{
		fprintf(stderr, "Number of consumers set to default: %d\n", numberOfConsumers);
	}	
	//make sure only 3 args are entered
	else if(argc == 3)	
	{
		//check option read
		while((opt = getopt(argc, argv, "n:")) != -1)
        	{
                	switch(opt)
                	{
                       		//set program limit
                        	case 'n': numberOfConsumers = atoi(argv[2]);
                        		fprintf(stderr, "Number of consumers set to: %d\n", numberOfConsumers);
                        		break;
                		default: perror("Incorrect Argument!");
                        	exit(EXIT_FAILURE);
                	}
        	}
	}
	else 
	{
		perror("Incorrect number of arguments!\n");
                exit(EXIT_FAILURE);
	}
	
	//set size of processID array to producer + number of consumers
	int totalNumberOfProcesses = numberOfConsumers + 1;
	processIDArray = (pid_t*)malloc(sizeof(pid_t) * totalNumberOfProcesses);

	//generate producer and consumer processes
	processIDArray = createProducerAndConsumers(numberOfConsumers, processIDArray);
	
	for(int x = 0;x < sizeof(processIDArray); x++)
	{
		if(pid == 0)
		{
       			printf("Child %d  My Parent is %d \n\n", getpid(), getppid());
    		}
		else if(pid > 0)
		{
        		printf("Parent %d \n\n", getpid());
    		}	
	}	
	
	//set up shared memory
	int id;
	key_t key;
	char* shm;
	char* s;

	key = 1227;

	if((id = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0)
	{
		perror("Failed to create shared memory!");
		exit(EXIT_FAILURE);
	}
	
	if((shm = shmat(id, NULL, 0)) == (char*)-1)  
	{
		perror("Failed to attach shared memory to data space!");
		exit(EXIT_FAILURE);
	}
	
	//set first character in buffer to 0 
	//the 0 indicates the producer can write.
	//if it were a 1, then the consumer could read.
	s = shm;
	*s = 0;
		

	return 0;
}	
