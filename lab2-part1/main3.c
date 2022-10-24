// C program to implement a two child process and a parent process

// Randomly generates the values of iteration
//Author : Tolulope Akinlabi

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void  ChildProcessOne(void);              
void  ParentProcess(int);

//Main Code
void main(void){
  int pid, pid1;
  int i;

  for(i=0; i<2; i++){

      pid = fork();
      if (pid == 0){
        //Child One Process
        ChildProcessOne();
      }
      else if(pid < 0){
        printf("Error while forking child!");
        exit(0);  
      }
  }

  for(i=0; i<2; i++){
      pid = wait(NULL);
      //Calling Parent Process
      ParentProcess(pid);
  }
    
  
}

//Cild One process
void  ChildProcessOne(void){

  int i, n;

   // Intializes random number generator 
   srand(getpid());
   int random = rand();
   n = random % 31;

   // loop contains random number of iteration but not more tahn 30
   for( i = 0 ; i < n ; i++ ) {
     printf("Child Pid: %d is going to sleep!\n", getpid());

     sleep(rand() % 11);
     printf("Child Pid:%d is awake!\n Where is my Parent: ppid %d\n", 
      getpid(), getppid());
   }
   
   exit(0);
}

//Parent Process
void ParentProcess(int chpid){
  int stat; //initializing status
  printf("Child Pid: %d has completed!\n", chpid);
}
