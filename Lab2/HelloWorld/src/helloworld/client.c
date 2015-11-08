#include<stdio.h>

DECLARE_DATA {
} ;

#include <cecilia.h>

int METHOD(r, main) (void *_this, int argc, char *argv[]){

  CALL(REQUIRED.s, print, "hello world");
  
  CALL(REQUIRED.s, print, "hello world");

  
  return 0;
}
