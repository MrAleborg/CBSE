#include <stdio.h>

DECLARE_DATA {
  // no data
};

#include <cecilia.h>

void METHOD(s, print)(void *_this, const char *msg) 
{
  int i;
  char* header = ATTRIBUTES.header;
  if (header == NULL) {
    header = (char *)"";
  }
  
  printf("Server: begin printing...\n");
  for (i = 0; i < ATTRIBUTES.count; ++i) {
    printf("%s%s\n", header, msg);
  }
  
  printf("Server: print done\n");
}
