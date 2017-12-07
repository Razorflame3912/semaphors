#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <dirent.h>

#define KEY 2319

int main(int argc, char * argv[]){
  int sem;
  if(!strncmp(argv[1],"-c", 2)){
    sem = semget(KEY,1,0666 |IPC_CREAT | IPC_EXCL | IPC_SET);
    if(sem == -1){
      printf("already exists\n");
      return 0;
    }
    semctl(sem,0,SETVAL,atoi(argv[2]));
    printf("semaphore created\n");
  }
  else if(!strncmp(argv[1],"-v", 2)){
    sem = semget(KEY,1,0666);    
    printf("semaphore value: %d\n",semctl(sem,0,GETVAL,0));
  }
  else if(!strncmp(argv[1],"-r", 2)){
    sem = semget(KEY,1,0666);
    semctl(sem,0,IPC_RMID,0);
    printf("semaphore value: %d\n",semctl(sem,0,GETVAL,0));
  }
  else{
    printf("Unrecognized input.\n");
  }
    return 0;
}
