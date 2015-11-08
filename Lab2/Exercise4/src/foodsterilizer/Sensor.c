#include <stdio.h>
#include <stdlib.h>
#include <time.h>
DECLARE_DATA{
        int temp;
};

#include <cecilia.h>

void CONSTRUCTOR (void *_this){
	printf("----------------Sensor component built----------------\n");
}


int METHOD(sens, IncTemp)(void *_this,  const int maxtemp){

        int step = 5;
        int ToMax = maxtemp-DATA.temp;

        time_t t;

        srand((unsigned) time(&t));

        if(step >= ToMax)
                step=ToMax;
	if(DATA.temp == maxtemp)
		return DATA.temp;

        // at least temp+1
        DATA.temp = DATA.temp + rand()%step + 1;
        return DATA.temp;
}

int METHOD(sens, DecTemp)(void *_this,  const int mintemp){

        int step = 25;
        int ToMin = DATA.temp-mintemp;

        time_t t;

        srand((unsigned) time(&t));

        if(step >= ToMin)
                step=ToMin;

        // at least temp-1
        DATA.temp = DATA.temp - rand()%step - 1;
        return DATA.temp;
}

int METHOD(sens, getTemp)(void *_this){
	return DATA.temp;
}

void METHOD(sens, setInitTemp)(void *_this, const int t){
	DATA.temp=t;
}
