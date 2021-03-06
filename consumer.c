//consumer.c file
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "timeFormat.h"
#include "consumer.h"
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>



#define MAX_STRING_LENGTH 20
#define SHMSZ = 100



//function for consumer to write to its own log file
void consumerLog( int processID, int index, char* stringArray, int caseOption, char* termReason, int bufferNumber, int sleepTime)
{
	int pid = processID;
	int i = index;
	char* word = stringArray;
	char filename[MAX_STRING_LENGTH];
	int opt = caseOption;	
	int buf = bufferNumber;
	int r = sleepTime;
	char* reason = termReason;

	//set system time
	char* systemTime;
	format_time(systemTime);	


	//set unique log name
	filename = "cons" + index + ".log";	

	FILE *logFile;	

	logFile = fopen(filename, "a");
	
	//options for what to write to the logfile
	switch(opt)
	{
		case '0':	//initialize log
			fprintf(logFile, "ProcessID: %d\tIndex: %d", processID, index);
			format_time(systemTime);
			fprintf(logFile,"%sStarted\n", systemTime);
			break;
		case '1':	//reading from buffer
			format_time(systemTime);
			fprintf(logFile,"%sRead\t%d\t%s", systemTime, buf, word);
			break;
		case '2':	//sleeping
			format_time(systemTime);
			fprintf(logFile,"%sSleep\t%d", systemTime, r);
			break;
		case '3':	//checking buffer
			format_time(systemTime);
			fprintf(logFile,"%sCheck", systemTime);
			break;
		case '4':	//attempt write to master log
			format_time(systemTime);
			fprintf(logFile,"%sAttempt to write master log", systemTime);
			break;
		case '5':	//master log write success
			format_time(systemTime);
			fprintf(logFile,"%sWrote master log", systemTime);
			break;
 		case '6':	//process ends
			format_time(systemTime);
			fprintf(logFile,"%sTerminated\t%s", systemTime, reason);
			break;
		default:	//anything else - error
			perror("Consumer Log: not a recognized log option!\n");
			exit(EXIT_FAILURE);
	}
		
	//close file
	fclose(logFile);
}




void consumerReadFromSharedMemory(int shmid, key_t key, char* sharedmem, char* str)
{
	int id = shmid;
	key_t memkey = key;
	char* shm = sharedmem;
	char* s = str;

	if((id = shmget(memkey, SHMSZ, 0666)) < )
	{
		perror("Failed to locate shared memory!");
		exit(EXIT_FAILURE);
	}
	
	if((shm = shmat(id, NULL, 0)) == (char*) -1)
	{
		perror("Failed to attach to dataspace");
		exit(EXIT_FAILURE);
	}
	
	if(*shm == 1)
	{
		s = shm;
		printf("consumer read: %s\n", s);
	}
	else
	{
		sleep(1);
	}

}















