#include <stdio.h>
#include <stdlib.h>
#include <time.h>
DECLARE_DATA {
	int _Status;
};

#include <cecilia.h>

void CONSTRUCTOR(void *_this){

        printf("--------Status component created--------\n");

}



void CONSTRUTOR(void *_this){
	DATA._Status=0;
}

int METHOD(stat, generateStatus)(void *_this){

	time_t t;
	srand((unsigned) time(&t));

	DATA._Status = (rand()%2);

	return DATA._Status;
}

int METHOD(stat, setStatusOff)(void *_this){
	DATA._Status=0;
	return DATA._Status;
}
