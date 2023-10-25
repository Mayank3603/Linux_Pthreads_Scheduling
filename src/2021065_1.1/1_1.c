#include <stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<math.h>
#include<sched.h>
#include<unistd.h>
#include<time.h>

#define BILLION 1000000000L;

pthread_t threadA;
pthread_t threadB;
pthread_t threadC;
struct sched_param param;
void Count_A();
void Count_B();
void Count_C();
void* launch_A(void * argument);
void* launch_B(void * argument);
void* launch_C(void * argument);


int main(){
    FILE *fPtr;
    fPtr=fopen("Assignment_2_values.txt","w");
    fclose(fPtr);
    
    param.sched_priority=2;
    for (int i=0;i<10;i++){
        param.sched_priority+=2;
        pthread_create(&threadA,NULL,&launch_A,NULL);   
        pthread_create(&threadB,NULL,&launch_B,NULL);
        pthread_create(&threadC,NULL,&launch_C,NULL);
        pthread_join(threadA,NULL);
        pthread_join(threadB,NULL);
        pthread_join(threadC,NULL);
    }
 
    return 0;
}
void Count_A(){    
    long i=1;
    while(i<pow(2,32)){
        i++;
    }
}
void Count_B(){
    long i=1;
    while(i<pow(2,32)){
        i++;
    }
}
void Count_C(){
    long i=1;
    while(i<pow(2,32)){
        i++;
    }
}
void* launch_A(void * argument){
   
    int policy=SCHED_OTHER;
    
    
    pthread_setschedparam(threadA, policy,&param);
    FILE *fptr;
    fptr=fopen("Assignment_2_values.txt","a");
    struct timespec start;
    struct timespec stop;
    double accum;
    
    int return_A_start=clock_gettime( CLOCK_REALTIME, &start)+1;
    if( return_A_start==0 ) {
        perror( "Clock Gettime error" );
        exit( EXIT_FAILURE );
        }
    Count_A();
    int return_A_stop=clock_gettime( CLOCK_REALTIME, &stop)+1;
    if( return_A_stop==0 ) {
        perror("Clock Gettime error" );
        exit( EXIT_FAILURE );
        }
    
    
    accum = (double) ( stop.tv_sec - start.tv_sec ) + (double)( stop.tv_nsec - start.tv_nsec )/(double)BILLION;
    fprintf(fptr,"o: %f\n",accum);
    fclose(fptr);    
    printf( "SCHED_OTHER: %lf\n", accum );
    return EXIT_SUCCESS;

}
void* launch_B(void *argument){
    
    int policy=SCHED_RR;
    pthread_setschedparam(threadB, policy,&param);
    FILE *fptr;
    fptr=fopen("Assignment_2_values.txt","a");
    struct timespec start;
    struct timespec stop;
    double accum;
  
    int return_B_start=clock_gettime( CLOCK_REALTIME, &start)+1;
    if(return_B_start==0 ) {
        perror( "Clock Gettime error" );
        exit( EXIT_FAILURE );
        }
    Count_B();
    int return_B_stop= clock_gettime( CLOCK_REALTIME, &stop) +1;
    if(return_B_stop==0) {
        perror("Clock Gettime error" );
        exit( EXIT_FAILURE );
        }
    
    
    accum = (double) ( stop.tv_sec - start.tv_sec ) + (double)( stop.tv_nsec - start.tv_nsec )/(double)BILLION;
    fprintf(fptr,"r: %f\n",accum);
    fclose(fptr);                      
    printf( "SCHED_RR: %lf\n", accum );
    return EXIT_SUCCESS;

}
void* launch_C(void *argument){
    
    int policy=SCHED_FIFO;
    pthread_setschedparam(threadC, policy,&param);
    FILE *fptr;
    fptr=fopen("Assignment_2_values.txt","a");
    struct timespec start;
    struct timespec stop;
    double accum;
    
    int return_C_start=clock_gettime( CLOCK_REALTIME, &start)+1;
    if( return_C_start==0 ) {
        perror( "Clock Gettime error" );
        exit( EXIT_FAILURE );
        }
    Count_C();
    int return_C_stop=clock_gettime( CLOCK_REALTIME, &stop) +1;
    if( return_C_stop==0 ) {
        perror( "Clock Gettime error" );
        exit( EXIT_FAILURE );
        }
        
    accum = (double) ( stop.tv_sec - start.tv_sec ) + (double)( stop.tv_nsec - start.tv_nsec )/(double)BILLION;
    fprintf(fptr,"f: %f\n",accum);
    fclose(fptr);                  
    printf( "SCHED_FIFO: %lf\n", accum );
    return EXIT_SUCCESS;
}