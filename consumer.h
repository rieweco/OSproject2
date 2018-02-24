//consumer.h
//

#ifndef CONSUMER_H
#define CONSUMER_H

void consumerLog( int processID, int index, char* stringArray, int caseOption, char* termReason, int bufferNumber, int sleepTime);

void consumerReadFromSharedMemory(int shmid, key_t key, char* sharedmem, char* str);

#endif

