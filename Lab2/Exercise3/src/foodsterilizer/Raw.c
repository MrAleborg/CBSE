#include <stdio.h>
#include <stdlib.h>
#include <time.h>
DECLARE_DATA {
        int _Status;
};

#include <cecilia.h>

void CONSTRUCTOR (void *_this){
        printf("----------------Raw product component built----------------\n");
}


int METHOD(r, checkRawProductReady)(void *_this){

        time_t t;
        srand((unsigned) time(&t));

        DATA._Status = (rand()%2);

        return DATA._Status;
}

int METHOD(r, checkRawProductFinished)(void *_this){

	time_t t;
        srand((unsigned) time(&t));

        DATA._Status = (rand()%2);

        return DATA._Status;

}
