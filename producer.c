//producer.c file
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "producer.h"
#include "timeFormat.h"

void producerLog( int processID, int index, char* stringArray, int caseOption, char* termReason)
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
}






