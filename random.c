#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "random.h"

int randgen(){
  int file= open("/dev/random",O_RDONLY);
  //open file at /dev/random which is a file that generates random numbers
  if(file==-1){
    //if error can't be found then print error
    printf("Error: %s\n",strerror(errno));
  }
  int random_num;
  int *buff=&random_num;
  //create the random number and get the address
  int reading=read(file,buff,sizeof(random_num));
  if(reading != 0){
    printf("Error %s\n",strerror(errno));
  }
  //read takes in the file then copies the first few bytes given by last parameter
  //and then puts what it read into the buff which is a pointer
  //leads to editing the random_num
  close(file);
  return random_num
}
