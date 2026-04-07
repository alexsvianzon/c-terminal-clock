#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
  // had to try out argc and argv
  printf("Has %d arguments.\n", argc);

  // get the time
  char buff[80]; // NEVER name the character buffer "time"
  time_t rawtime = time(NULL);
  struct tm *fmttime = localtime(&rawtime);

  // format and print time
  strftime(buff, sizeof(buff), "%c", fmttime);
  printf("The current time is: %s\n", buff);

  return 0;
}
