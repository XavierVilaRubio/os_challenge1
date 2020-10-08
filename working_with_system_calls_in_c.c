#include<stdio.h>
#include<sys/time.h>
#include<sys/types.h>
#include<string.h>
#define TIMES 1000000

int main(int argc, char *argv[]){

    struct timeval start, end;

    int dummy_function(){
        return 3;
    }

    void system_call(){
        printf("SYSTEM CALL\n");

        gettimeofday (&start, NULL);
        for(int i=0; i<TIMES; i++){
            pid_t getpid(void);
        }
        gettimeofday (&end, NULL);

        printf("Time in microseconds: %d microseconds\n", end.tv_usec - start.tv_usec);
    }

    void procedure_call(){
        printf("PROCEDURE CALL\n");

        gettimeofday (&start, NULL);
        for(int i=0; i<TIMES; i++){
            dummy_function();
        }
        gettimeofday (&end, NULL);

        printf("Time in microseconds: %d microseconds\n", end.tv_usec - start.tv_usec);
    }

    if(argc == 2){
        if(strcmp(argv[1], "sys") == 0){
            system_call();
        }else if(strcmp(argv[1], "proc") == 0){
            procedure_call();
        }
    }else{
        system_call();
        sleep(1);
        procedure_call();
    }

    return 0;
}
