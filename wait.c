#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    pid_t pid;
    pid = fork();
    if(pid==0){
   	 printf("I am child, my PID=%d and PPID=%d\n", getpid(), getppid());
    	sleep(10);
    }
    else{
   	 printf("I am parent and my PID=%d\n", getpid());
    	wait(NULL);
    	printf("I am a parent.\n");
    }
    printf("Terminating PID=%d\n", getpid());
}
// trmnl: gcc wait.c -o wait && ./wait
