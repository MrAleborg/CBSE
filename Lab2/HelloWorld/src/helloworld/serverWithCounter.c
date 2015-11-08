#include <stdio.h>

DECLARE_DATA {
  int nrOfInvocations;
};

#include <cecilia.h>

void CONSTRUCTOR(void *_this) {
  DATA.nrOfInvocations = 0;
}

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

  DATA.nrOfInvocations++;

  printf("Server: print done (Number of invocations up to now: #%d)\n", DATA.nrOfInvocations);
}
