#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/syscall.h>
#include<sys/time.h>
#define __NR_getinfoproc 326

/*
int main(){
        struct procinfo * pi;
        syscall(__NR_getinfoproc, getpid(), &pi);
        printf("start time:: %ld\n", pi->start_time);
        printf("sys time:: %ld\n", pi->stime);
        printf("user time:: %ld\n", pi->utime);
        return 0;
}
*/

int main(){
	long start_time;
	long stime;
	long utime;
        syscall(__NR_getinfoproc, getpid(), &start_time, &stime, &utime);
	struct timeval k;
	gettimeofday(&k, NULL);
        printf("elapsed time:: %ld\n", k.tv_sec*1000000+k.tv_usec - start_time);
        printf("start time:: %ld\n", start_time);
        printf("sys time:: %ld\n", stime);
        printf("user time:: %ld\n", utime);
        return 0;
}
