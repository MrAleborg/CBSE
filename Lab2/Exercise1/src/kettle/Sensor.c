#include <stdio.h>
#include <stdlib.h>
#include <time.h>
DECLARE_DATA{
	int temp;
};

#include <cecilia.h>

void CONSTRUCTOR(void *_this){
	
	DATA.temp=0;
        printf("--------Sensor component created--------\n");
	
}


int METHOD(s, IncTemp)(void *_this,  const int volume){

	int step = 1+(100-volume)/2;
	int ToMax = 100-DATA.temp;
	
	time_t t;

	srand((unsigned) time(&t));

	if(step >= ToMax)
		step=ToMax;

	// at least temp+1
	DATA.temp = DATA.temp + rand()%step + 1;
	return DATA.temp;
}
