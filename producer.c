//producer.c file
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "producer.h"
#include "timeFormat.h"
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/wait.h>
#define MAX_LINE 100
#define MAX_STRING_LENGTH 20
#define SHMSZ 100

void producerLog( int processID, int index, char* stringArray, int caseOption, char* termReason, int bufferNumber, int sleepTime)
{
        int pid = processID;
        int i = index;
        char* word = stringArray;
        char* filename;
        int opt = caseOption;
        int buf = bufferNumber;
        int r = sleepTime;
	char* reason = termReason;

        //set system time
        char* systemTime;
        format_time(systemTime);
        
	//set unique log name
        filename = "prod.log";
        
	FILE *logFile;
        logFile = fopen(filename, "a");
        
	switch(opt)
	{
                case '0':       //initialize log
                        fprintf(logFile, "ProcessID: %d\tIndex: %d", processID, index);
			fprintf(logFile,"%sStarted\n", systemTime);
			break;
                case '1':       //write to buffer
                        format_time(systemTime);
                        fprintf(logFile,"%sRead\t%d\t%s", systemTime, buf, word);
                        break;
		case '2':       //sleeping
                        format_time(systemTime);
                        fprintf(logFile,"%sSleep\t%d", systemTime, r);
                        break;
                case '3':       //checking buffer
                        format_time(systemTime);
                        fprintf(logFile,"%sCheck", systemTime);
                        break;
                case '4':       //process ends
                        format_time(systemTime);
                        fprintf(logFile,"%sTerminated\t%s", systemTime, reason);
                        break;
                default:        //anything else - error
                        perror("Producer Log: not a recognized log option!\n");
                        exit(EXIT_FAILURE);
	}

	//close logFile
	fclose(logFile);
	
	return;
}



void producerWriteToSharedMemory(int shmid, key_t key, char* shm, char* str)
{
	char* line;
	int id = shmid;
	key_t memkey = key;
	char* sharedmem = shm;
	char* s = str;

	if((id = shmget(memkey, SHMSZ, 0666)) < 0)
	{
		perror("Producer failed to access shared memory!");
		exit(EXIT_FAILURE);
	}
	
	if((sharedmem = shmat(id, NULL, 0)) == (char*) -1)
	{
		perror("failed to attach to data space");
		exit(EXIT_FAILURE);
	}
	
	s = shm;

	//read from data file
	FILE *dataFile;

        dataFile = fopen("testdata.txt", "r");

        if(fgets(line, MAX_LINE-1, dataFile) != NULL)
        {
                s = line;
        }

        fclose(dataFile);

        printf("printing s: %s", s);

	//set first character is s to 1, indicating the consumer can read
	*s = 1;	
				
	while ( *shm != 0) 
	{
		sleep(1);
	}


}












