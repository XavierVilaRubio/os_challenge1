#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/syscall.h>
#include<sys/time.h>
#define __NR_getinfoproc 326

struct procinfo {
    long elapsed_time;
    long start_time;
    long stime;
    long utime;
};

int main(){
        struct procinfo * pi;
        syscall(__NR_getinfoproc, getpid(), &pi);
        printf("start time:: %ld\n", pi->start_time);
        printf("sys time:: %ld\n", pi->stime);
        printf("user time:: %ld\n", pi->utime);
        return 0;
}
