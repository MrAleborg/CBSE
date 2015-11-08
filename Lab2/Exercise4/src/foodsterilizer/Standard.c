#include <stdio.h>
#include <stdlib.h>
#include <time.h>

DECLARE_DATA{
};

#include <cecilia.h>

void CONSTRUCTOR(void *_this){

        printf("----------------Standardization component built----------------\n");
}


int METHOD(r, checkRawProductReady)(void *_this){

        time_t t;
        srand((unsigned) time(&t));
	int _Status = -1;
	int cream=-1;

	printf("In standardization : waiting for separating milk\n");
	while(_Status!=0){
        	_Status = (rand()%2);
	}
	printf("milk separated\n");
	
	printf("which percentage of cream do you prefer???\n");
	scanf("%d%*c",&cream);

	int mixed=0;
	while(mixed<cream){
		
		clock_t timer = clock() + 0.3*CLOCKS_PER_SEC;
		while(clock()<timer){}
		mixed+=1;
		printf("mixing : %d\n", mixed);	
	}
	printf("Mixed and ready!!!\n");


        return _Status;
}

int METHOD(r, checkRawProductFinished)(void *_this){

        time_t t;
        srand((unsigned) time(&t));

        int _Status = (rand()%2);

        return _Status;

}
