//producer.h
//

#ifndef PRODUCER_H
#define PRODUCER_H

void producerLog( int processID, int index, char* stringArray, int caseOption, char* termReason,int bufferNumber, int sleepTime);

void producerWriteToSharedMemory(int shmid, key_t key, char* shm, char* str);

#endif



