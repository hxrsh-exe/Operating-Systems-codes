#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    pid_t pid;
    pid = fork();
    if(pid==0){
   	 printf("I am child, my PID=%d and PPID=%d\n", getpid(), getppid());
    }
    else{
   	 printf("I am parent and my PID=%d\n", getpid());
    	sleep(10);
    }
    printf("Terminating PID=%d\n", getpid());
}
// trmnl: gcc zmbie.c -o zmbie && ./zmbie
// trmnl: ps -a


