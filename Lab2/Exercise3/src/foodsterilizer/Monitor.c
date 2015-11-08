#include <stdio.h>
#include <stdlib.h>
#include<time.h>
//#include <pthread.h>

DECLARE_DATA{
	int tempfalls;
};

#include<cecilia.h>

void CONSTRUCTOR (void *_this){

	time_t t;

        srand((unsigned) time(&t));

        DATA.tempfalls = (rand()%2);

        printf("----------------Monitor component built----------------\n");
	if(DATA.tempfalls==0)
		printf("\t--------> In this scenario a problem will happen : temperature will fall under 130°C\n");
}


int METHOD(r, main)(void *_this, int argc, char *argv[]){


char quit='c';
int maxtemp=130;
int temp=0;

do{
	printf("In Monitor component waiting for cleanMachine signal...\n");
	
		while(CALL(REQUIRED.c, cleanMachine)>0){}
	
	printf("Signal received & Larry filled the machine with steam\nStart heating...\n");
		while(temp<maxtemp){
	                clock_t timeout = clock() + 0.5*CLOCKS_PER_SEC;
	                while(clock() < timeout){
	                //waiting before updating the new temperature
	                }
	                temp=CALL(REQUIRED.sens, IncTemp, maxtemp);
	                printf("Temperature : %d\n", temp);
	        }
	
	printf("Heat done now let's wait 30 minutes (assuming that 1 sec = 1 min)...\n");
	
	int timer = 30; // let's say that 1 sec is 1 min...
	//pthread_t timer_thread; //to run timer in background
	
	//	CALL(REQUIRED.tim, setTimer, timer);
	//	if(pthread_create(&timer_thread, NULL, CALL(REQUIRED.tim, startTimer), NULL)==-1){
	//		perror("timer did not start...\n");
	//	return -1;
	//	}
	//	CALL(REQUIRED.tim, startTimer);
	
	//	while(CALL(REQUIRED.tim, getTimer)>0){
	
		clock_t timeout = clock() + timer*CLOCKS_PER_SEC;
		while(clock()<timeout){
			printf("update every 10 sec\n");
			clock_t timeout2= clock() + 10*CLOCKS_PER_SEC;
			while(clock()<timeout2){
			//waiting before update of values
			}
			if(DATA.tempfalls==0){
				CALL(REQUIRED.sens, setInitTemp, 110);
				DATA.tempfalls=-1;
			}
			temp=CALL(REQUIRED.sens, getTemp);
			if(temp<130){
	//			pthread_cancel(timer_thread);
				printf("Temperature fell under 130°C\nLet's heat againg\n");
				while(temp<maxtemp){
	                		clock_t timeout3 = clock() + 0.5*CLOCKS_PER_SEC;
	                		while(clock() < timeout3){
					//waiting before updating the new temperature
	                		}
	                		temp=CALL(REQUIRED.sens, IncTemp, maxtemp);
	                		printf("Temperature : %d\n", temp);
	        		}
				printf("Timeout reset\n");
				timeout = clock() + timer*CLOCKS_PER_SEC;
	//			CALL(REQUIRED.tim, setTimer, timer);
	//		        if(pthread_create(&timer_thread, NULL, CALL(REQUIRED.tim, startTimer), NULL)==-1){
	//              		perror("timer did not start...\n");
	//   		 	return -1;
	//        		}
	//			CALL(REQUIRED.tim, startTimer);
			}
		}
	
		printf("Job is done. Go to Ready For Production component\n"); 
			
		CALL(REQUIRED.rfp, run, 0);

printf("\n\nPRESS q if you want to quit or Enter if you want to simulate an other scenario\n\n");
scanf("%c", &quit);

if(quit!='q'){
	system("clear");
	CALLMINE(mon, reInit);
	CALL(REQUIRED.d_a, reInit);
	CALL(REQUIRED.sens, setInitTemp, 0);
	temp=CALL(REQUIRED.sens, getTemp);
}


}while(quit!='q');	
return 0;
}
	

void METHOD(mon, reInit)(void *_this){
	time_t t;

        srand((unsigned) time(&t));

        DATA.tempfalls = (rand()%2);

        printf("----------------Monitor component reinitialized----------------\n");
        if(DATA.tempfalls==0)
                printf("\t--------> In this scenario a problem will happen : temperature will fall under 130°C\n");

}
