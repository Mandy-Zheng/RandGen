#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "random.h"

int main(int argc, char const *argv[]) {
  int randary[10];
  int i;
  printf("Generating Random Numbers:\n");
  for (i = 0; i < 10; i++) {
    randary[i]=rand_num();
    printf("Random %d: %d\n",i,randary[i]);
  }
  printf("Writing Numbers into the file . . .\n");
  int file = open("randfile",O_WRONLY | O_CREAT, 0644);
  if (file==-1){
    printf("Error: %s\n",strerror(errno));
  }
  int writing = write(file, &randary, sizeof(randary));
  if(writing != 0){
    printf("Error %s\n",strerror(errno));
  }
  close(file);
  printf("Reading Numbers into the file . . .\n");
  int ary[10];
  int file =open("randfile",O_RDONLY);
  if (file==-1){
    printf("Error: %s\n",strerror(errno));
  }
  int reading = read(file, &ary, sizeof(randary));
  if(reading != 0){
    printf("Error %s\n",strerror(errno));
  printf("\nVerification that written values were the same:\n");
  for (i = 0; i < 10; i++) {
    printf("Random %d: %d\n",i,ary[i]);
  }
  close(file);
  return 0;
}
