#include<stdio.h>
#include<sys/time.h>
#include<sys/types.h>
#include<string.h>
#define TIMES 1000000

int main(int argc, char *argv[]){

//    struct timeval {
//        time_t      tv_sec;       Number of whole seconds of elapsed time
//        long int    tv_usec;      Number of microseconds of rest of elapsed time minus tv_sec. Always less than one million
//    };
    struct timeval start, end;

    long nanosec(struct timeval t){
        return((t.tv_sec*1000000+t.tv_usec)*1000);
    }

    int dummy_function(){
        return 3;
    }

    float avgTimeSysCall, avgTimeProcCall;

    void system_call(){
        printf("\nSYSTEM CALL\n");

        gettimeofday (&start, NULL);
        for(int i=0; i<TIMES; i++){
            pid_t getpid(void);
        }
        gettimeofday (&end, NULL);

        float totalTime=(nanosec(end)-nanosec(start));
        printf("Total time in microseconds: %f microseconds\n", totalTime);

        avgTimeSysCall=(totalTime/(TIMES)*1.0);
        printf("Average time in microseconds: %f microseconds\n", avgTimeSysCall);
    }

    void procedure_call(){
        printf("\nPROCEDURE CALL\n");

        gettimeofday (&start, NULL);
        for(int i=0; i<TIMES; i++){
            dummy_function();
        }
        gettimeofday (&end, NULL);

        float totalTime=(nanosec(end)-nanosec(start));
        printf("Total time in microseconds: %f microseconds\n", totalTime);

        avgTimeProcCall=(totalTime/(TIMES)*1.0);
        printf("Average time in microseconds: %f microseconds\n", avgTimeProcCall);
    }

    if(argc == 2){
        if(strcmp(argv[1], "sys") == 0){
            system_call();
        }else if(strcmp(argv[1], "proc") == 0){
            procedure_call();
        }
    }else{
        system_call();
//        sleep(1);
        procedure_call();
        if(avgTimeSysCall > avgTimeProcCall){
            printf("\nThe difference is: %f microseconds\n", avgTimeSysCall - avgTimeProcCall);
        }else{
            printf("\nThe difference is: %f microseconds\n", avgTimeProcCall - avgTimeSysCall);
        }
    }

    return 0;
}
