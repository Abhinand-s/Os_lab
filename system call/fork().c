#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
    int pid;
    pid = fork();
    if(pid<0){
        printf("fork failed");
        exit(1);
    }
    else if(pid==0){
        execlp("/bin/date","date",NULL);
        exit(0);
    }
    else{
        printf("process id %d",getpid());
        wait(NULL);
        exit(0);
    }
    return 0;
}