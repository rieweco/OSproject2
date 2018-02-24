//timeFormat.c
//
#include <time.h>
#include <stdio.h>


//function for formatting time fo local time for logs
//will store formatted string into output
//format:  HH:MM:SS 


void format_time(char *output)
{
	time_t rawtime;
	struct tm * timeinfo;
	
	time( &rawtime);
	timeinfo = localtime (&rawtime);
	
	sprintf(output, "%d:%d:%d ", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}
