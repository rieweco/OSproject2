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
	pid_t childpid = 0;
	int n = DEFAULT_CONSUMERS;
	int opt = 0;

	return 0;
}	
