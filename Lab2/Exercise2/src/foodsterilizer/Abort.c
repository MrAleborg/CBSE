#include <stdio.h>
#include <stdlib.h>
#include <time.h>
DECLARE_DATA {
};

#include <cecilia.h>

void CONSTRUCTOR (void *_this){
        printf("----------------Abort component built----------------\n");
}


int METHOD(a, stopProduction)(void *_this){

	time_t t;
        srand((unsigned) time(&t));

        int abort = (rand()%2);

        return abort;

}
