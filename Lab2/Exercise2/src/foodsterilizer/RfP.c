#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <pthread.h>
DECLARE_DATA {
};

#include <cecilia.h>

void CONSTRUCTOR (void *_this){
        printf("----------------RfP component built----------------\n");
}


void METHOD(m, run)(void *_this, const int presterilized){

	int temp=130;
	int maxtemp=140;
	int mintemp=20;

//	int timer = 5; 

	if(presterilized==0){

printf("In RfP component. We received the presterilized signal and are waiting for raw production ready one...\n");
		
		while(CALL(REQUIRED.r, checkRawProductReady)!=0){}

//		pthread_t timer_thread; //to run timer in background
	
		CALL(REQUIRED.sens, setInitTemp, temp);
	

printf("Signal received, let's heat the machine a bit more...\n");
		while(temp<maxtemp){
	                clock_t timeout = clock() + 0.5*CLOCKS_PER_SEC;
	                while(clock() < timeout){
	                //waiting before updating the new temperature
	                }
	                temp=CALL(REQUIRED.sens, IncTemp, maxtemp);
	                printf("Temperature : %d\n", temp);
	        }
	
//	        CALL(REQUIRED.tim, setTimer, timer);
//	        if(pthread_create(&timer_thread, NULL, CALL(REQUIRED.tim, startTimer), NULL)==-1){
//	                perror("timer did not start...\n");
//	        }
//		else{
//		CALL(REQUIRED.tim, startTimer);
printf("Now we must wait 5 seconds\n");
			clock_t timeout = clock() + 5*CLOCKS_PER_SEC;
			while(clock()<timeout){
				//waiting
			}
printf("It's time to cool the system\n");
			while(temp>mintemp){
	        	        timeout = clock() + 0.5*CLOCKS_PER_SEC;
	        	        while(clock() < timeout){
	        	        //waiting before updating the new temperature
	        	        }
	        	        temp=CALL(REQUIRED.sens, DecTemp, mintemp);
	        	        printf("Temperature : %d\n", temp);
	        	}
		
			int end=1;
printf("Now we are waiting from the end signal\n");
			while(end==1){
                                        int stop = CALL(REQUIRED.a, stopProduction);
                                        int finished = CALL(REQUIRED.r, checkRawProductFinished);
                                        if(stop == 0){
                                                printf("Larry stoped the production!!!!!\n");
                                                end=0;
                                        }
                                        else if(finished == 0){
                                                printf("Row product finished normaly\n");
                                                end=0;
                                        }

                                }
		}
}

