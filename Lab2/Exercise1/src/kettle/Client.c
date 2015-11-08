#include <stdio.h>
#include<time.h>

DECLARE_DATA{};

#include<cecilia.h>

void CONSTRUCTOR(void *_this){

	printf("--------Client component created--------\n");

}


int METHOD(r, main)(void *_this, int argc, char *argv[]){

int temp=0;
int volume=0;

	printf("Volume (cL) : ?\n");
	scanf("%d", &volume);

	if(volume<=0){
		printf("\n\nKettle is empty... \nSorry but we won't waste energy warming air because you cannot make tea with air \nAnd it's better for the planet :)\n\n");
		return -1;
	}

	if(volume>100){
		printf("\n\nCongratulation you tested your limits and made the kettle overflow!!!\nNow you must wipe... :/\nFortunately there still is 1L in the kettle!!! So you can prepare tea\n\n");
		volume=100;
	}

	while(!CALL(REQUIRED.stat, generateStatus)){
	// empty loop to wait that the kettle is on
	}
	printf("Kettle is on\n");

	while(temp<100){
		clock_t timeout = clock() + 2*CLOCKS_PER_SEC;
		while(clock() < timeout){
		//waiting before updating the new temperature
		}
		temp=CALL(REQUIRED.s, IncTemp, volume);
		printf("Water temperature : %d\n", temp);
	}

	if(CALL(REQUIRED.stat, setStatusOff)!=0){
		printf("An error occured setting status off\n");
		return -1;
	}
	printf("Kettle off\n");

return 0;
}

