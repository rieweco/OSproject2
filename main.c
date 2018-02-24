//main.c
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <getopt.h>
#include "makeargv.h"
#include <errno.h>

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
	
	char* line[MAX_LINE];
	
	//make sure only 3 args are entered
	if(argc != 3)
	{
		perror("Incorrect number of arguments!\n");
		exit(EXIT_FAILURE);
	}
	
	//check option read
	while((opt = getopt(argc, argv, "n:")) != -1)
        {
                switch(opt)
                {
                        set program limit
                        case 'n': numberOfConsumers = atoi(optarg);
                        fprintf(stderr, "Number of consumers set to: %d\n", numberOfConsumers);
                        break;
                default: perror("Incorrect Argument!");
                        exit(EXIT_FAILURE);
                }
        }
	
	//set size of processID array to producer + number of consumers
	int totalNumberOfProcesses = numberOfConsumers + 1;
	processIDArray = (pid_t)malloc(sizeof(pid_t) * totalNumberOfProcesses);

		




	return 0;
}	
