// C program to implement a two child process and a parent process

// Randomly generates the values of iteration
//Author : Tolulope Akinlabi

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void  ChildProcessOne(void); 
void  ChildProcessTwo(void);               
void  ParentProcess(void);

//Main Code
void main(void){
  int pid, pid1;

  pid = fork();
  if (pid == 0){

    //Child One Process
    ChildProcessOne();
    }
  else{
    pid1 = fork();
    if (pid1 == 0){

      //Calling Child Two Process
      ChildProcessTwo();
    }
    else{

      //Calling Parent Process
      ParentProcess();
      }
    }
  }

//Cild One process
void  ChildProcessOne(void){

  int i, n;
  time_t t;
   
   n = 30;
   
   // Intializes random number generator 
   srand((unsigned) time(&t));
   int random = rand();

   // loop contains random number of iteration but not more tahn 30
   for( i = 0 ; i < n ; i++ ) {
     printf("Child Pid: %d is going to sleep!", getpid());
     sleep(random);
     printf("Child Pid:%d is awake!\n Where is my Parent: ppid %d", 
      getpid(), getppid());
   }
   
   exit(0);
}

//Child Two Process
void  ChildProcessTwo(void){

  int i, n;
  time_t t;
   
   n = 30;
   
   // Intializes random number generator 
   srand((unsigned) time(&t));
   int random = rand();

   // loop contains random number of iteration but not more tahn 30
   for( i = 0 ; i < n ; i++ ) {
     printf("Child Pid: %d is going to sleep!", getpid());
     sleep(random);
     printf("Child Pid: %d is awake!\n Where is my Parent: ppid %d", 
      getpid(), getppid());
   }
   
   exit(0);
}


//Parent Process
void ParentProcess(void){
  int stat; //initializing status
  wait(&stat);
  printf("Child Pid: %d has completed!\n", getpid());
}
