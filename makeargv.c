//makearv.c

#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>

int makeargv(const char* s, const char* delims, char*** argvp) 
{
    	int error;
    	int i;
    	int numTokens;
    	const char* startNewString;
    	char* t = NULL;
    
    	if((s == NULL) || (delims == NULL) || (argvp == NULL))
	{
        	errno = EINVAL;
        	return -1;
    	}
    
    	*argvp = NULL;
    	startNewString = s + strspn(s, delims); 
    
    	if((t = malloc(strlen(startNewString) + 1)) == NULL) 
	{ 
		return -1; 
	}
    
    	strcpy(t, startNewString);
    	numTokens = 0;

    	if(strtok(t, delims) != NULL)
	{
        	for(numTokens = 1; strtok(NULL, delims) != NULL; numTokens++);
   	}

	if((*argvp = malloc((numTokens + 1) * sizeof(char*))) == NULL)
	{
        	error = errno;
        	free(t);
        	errno = error;
        	return -1;
    	}
	
	if(numTokens == 0) 
	{
        	free(t);
    	} else 
	{
        	strcpy(t, startNewString);
        	**argvp = strtok(t, delims);
        
        	for(i = 1; i < numTokens; i++)
            	{
			*((*argvp) + i) = strtok(NULL, delims);
        	}
	}
    
    	*((*argvp) + numTokens) = NULL;
    	return numTokens;
}
