#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
    pid_t pid;
    pid = fork();
    int odd = 1, even = 0, n = 10, sum_o = 0, sum_e = 0;
    if(pid==0){
   	 printf("I am child, my PID=%d and PPID=%d\n", getpid(), getppid());
   	 while(odd<=n){
   		 sum_o += odd;
   		 odd += 2;
   	 }
   	 printf("Odd sum: %d\n", sum_o);
    }
    else{
   	 printf("I am parent and my PID=%d\n", getpid());
   	 while(even<=n){
   		 sum_e += even;
   		 even+=2;
   	 }
   	 printf("Even sum: %d\n", sum_e);
    }
    printf("Terminating PID=%d\n", getpid());
}
// trmnl: gcc prnt_chld.c -o prnt_chld && ./prnt_chld
