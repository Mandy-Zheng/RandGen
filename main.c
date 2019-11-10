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
  printf("Generating Random Numbers:\n\n");
  for (i = 0; i < 10; i++) {
    randary[i]=randgen();
    printf("Random %d: %d\n",i+1,randary[i]);
  }
  printf("\nWriting Numbers into the file . . .\n\n");
  int file = open("randfile",O_WRONLY | O_CREAT, 0644);
  if (file==-1){
    printf("Error: %s\n",strerror(errno));
  }
  int writing = write(file, &randary, sizeof(randary));
  if(writing < 0){
    printf("Error %s\n",strerror(errno));
  }
  close(file);
  printf("Reading Numbers into the file . . .\n\n");
  int ary[10];
  int file2 =open("randfile",O_RDONLY);
  if (file2==-1){
    printf("Error: %s\n",strerror(errno));
  }
  int reading = read(file2, &ary, sizeof(randary));
  if(reading < 0){
    printf("Error %s\n",strerror(errno));
  }
  printf("Verification that written values were the same:\n\n");
  for (i = 0; i < 10; i++) {
    printf("Random %d: %d\n",i+1,ary[i]);
  }
  close(file2);
  return 0;
}
