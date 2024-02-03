#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
    fork();
    printf("Hello world\n");
}
// terminal: gcc fork.c -o fork && ./fork
