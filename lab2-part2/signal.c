/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int alarmTriggered = 0;
int alarmcount = 0;
long start, end;


void alarmhandler(int signum){ 
  //signal handler
  printf("Hello World!\n");
  sleep(2);
  alarmTriggered = 1;
  alarmcount++;
  alarm(2); //Schedule a SIGALRM for 1 second
}

void timeHandler(){
    printf("The number of time alarms = %d\n", alarmcount);
    end = time(NULL);

    // Calculating total time taken by the program.
	long time_taken = (end - start);
    printf("The total time taken = %ld seconds\n", time_taken); 
}

int main(int argc, char * argv[]){
    signal(SIGALRM,alarmhandler);
    signal(SIGINT,timeHandler);
    start = time(NULL);
    alarm(2); //Schedule a SIGALRM for 1 second
    while(1){
         //register handler to handle SIGALRM  
        alarmTriggered = 0;
  
        while(!alarmTriggered)
            ;

        printf("Turing was right!\n");
 
    }
    
}

