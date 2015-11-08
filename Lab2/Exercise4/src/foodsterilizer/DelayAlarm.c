#include <stdio.h>
#include <stdlib.h>
#include <time.h>

DECLARE_DATA{
	int problem;
};

#include <cecilia.h>

void CONSTRUCTOR(void *_this){

	time_t t;
        srand((unsigned) time(&t));

        DATA.problem = (rand()%2);

	printf("----------------Delay alarm component built----------------\n");
	if(DATA.problem==0)
		printf("\t-------->  In this scenario a problem will happen : temperature will fall under 140°C\n");
}

int METHOD(d_a, raiseAlarm)(void *_this){
	
	if(DATA.problem==0)
		CALL(REQUIRED.sens, setInitTemp, 125);

	int temp = CALL(REQUIRED.sens, getTemp);
	clock_t timeout = clock() + 5*CLOCKS_PER_SEC;
	
	if(temp<140){
		while(clock()<timeout){
			clock_t t= clock() + CLOCKS_PER_SEC;
			while(clock()<t){}
			temp=CALL(REQUIRED.sens, IncTemp, 140);
			printf("Temperature : %d\n", temp);
			if(temp==140)
				break;
		}
		if(temp<140)
                	return -1;
        	else return 0;
	}
		

return 1;
}

void METHOD(d_a, reInit)(void *_this){
	time_t t;
        srand((unsigned) time(&t));

        DATA.problem = (rand()%2);
	
	printf("----------------Delay alarm component reinitialized----------------\n");
        if(DATA.problem==0)
                printf("\t-------->  In this scenario a problem will happen : temperature will fall under 140°C\n");

}
