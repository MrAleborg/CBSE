#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <pthread.h>
DECLARE_DATA {
	int timer;
};

#include <cecilia.h>

void CONSTRUCTOR (void *_this){
        printf("----------------Timer component built----------------\n");
}


void METHOD(tim, setTimer)(void *_this, const int t){
	DATA.timer=t;
}

void METHOD(tim, startTimer)(void *_this){
printf("Timer started for %d seconds\n", DATA.timer);
clock_t timeout = clock() + DATA.timer*CLOCKS_PER_SEC;
do{
	DATA.timer=timeout-clock();
}while(DATA.timer>0);
if(DATA.timer<0){
	DATA.timer=0;}

//pthread_exit(NULL);
}

int METHOD(tim, getTimer)(void *_this){
	return DATA.timer;
}
