#include <stdio.h>
#include <stdlib.h>
#include <time.h>
DECLARE_DATA {
        int _Status;
};

#include <cecilia.h>

void CONSTRUCTOR (void *_this){
        printf("----------------Clean component built----------------\n");
}


int METHOD(c, cleanMachine)(void *_this){

        time_t t;
        srand((unsigned) time(&t));

        DATA._Status = (rand()%2);

        return DATA._Status;
}
