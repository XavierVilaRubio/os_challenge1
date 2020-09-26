#include<stdio.h>
#include<sys/time.h>
#include<sys/types.h>

int main(){
    int dummy_function(){
	return 3;
    }

    struct timeval start, end;

    gettimeofday (&start, NULL);
    for(int i=0; i<1000000; i++){
	pid_t getpid(void);
    }
    gettimeofday (&end, NULL);

    printf("Time in microseconds: %d microseconds\n", end.tv_usec - start.tv_usec);

    gettimeofday (&start, NULL);
    for(int i=0; i<1000000; i++){
	dummy_function();
    }
    gettimeofday (&end, NULL);

    printf("Time in microseconds: %d microseconds\n", end.tv_usec - start.tv_usec);

    return 0;
}
