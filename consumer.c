//consumer.c file
//
#include <stdio.h>
#include <stdlib.h>
#include "timeFormat.h"


#define MAX_STRING_LENGTH 20




//function for consumer to write to its own log file
void consumerLog( int processID, int index, char* stringArray)
{
	int pid = processID;
	int i = index;
	char* word = stringArray;
	char filename[MAX_STRING_LENGTH];
	
	//set unique log name
	filename = "cons." + index + "log";	

	FILE *logFile;
	
	logFile = fopen(filename, "a");
	fprinf(fileLog, "ProcessID: %d\tIndex: %d", processID, index);
	fputs("Started\n", logFile);
		



	//close file
	fclose(logFile);
	
	





}

