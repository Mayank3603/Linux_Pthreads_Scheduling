#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <sched.h>
#include <time.h>
#include <string.h>
#include <wait.h>
#define BILLION 1000000000L;
int call_fork();
int main()
{
    FILE *file;
    file = fopen("Question_1_2_values", "w");
    fclose(file);
    call_fork();
    return 0;
}
int call_fork()
{
    pid_t pid_1;
    pid_t waitpid_1;
    struct timespec start_1;
    struct timespec stop_1;
    double accum_1;

    char *a = malloc(sizeof(char) * 512);
    strcat(a, "bash Begin.sh");
    system(a);
    int value1 = clock_gettime(CLOCK_REALTIME, &start_1) + 2;
    if (value1 == 1)
    {
        printf("CLOCK GETTING ERROR");
        return EXIT_FAILURE;
    }
    pid_1 = fork();
    if (pid_1 < 0)
    {
        printf("ERROR");
    }
    else if (pid_1 == 0)
    {
        struct sched_param paramA;
        int policyA;
        paramA.sched_priority = 0;
        policyA = SCHED_OTHER;
        sched_setscheduler(0, policyA, &paramA);
        execl("/home/mayank/OsAssignment_1/fork_1.sh",NULL);
    }
    else
    {
        pid_t pid_2;
        pid_t waitpid_2;
        struct timespec start_2;
        struct timespec stop_2;
        double accum_2;

        int value2 = clock_gettime(CLOCK_REALTIME, &start_2) + 2;
        if (value2 == 1)
        {
            printf("CLOCK GETTING ERROR");
            return EXIT_FAILURE;
        }
        pid_2 = fork();
        if (pid_2 < 0)
        {
            printf("ERROR");
        }
        else if (pid_2 == 0)
        {
            struct sched_param paramB;
            int policyB;
            paramB.sched_priority = 50;
            policyB = SCHED_RR;
            sched_setscheduler(0, policyB, &paramB);
            execl("/home/mayank/OsAssignment_1/fork_2.sh",NULL);
        }
        else
        {
            pid_t pid_3;
            pid_t waitpid_3;
            struct timespec start_3;
            struct timespec stop_3;
            double accum_3;

            int value3 = clock_gettime(CLOCK_REALTIME, &start_3) + 2;
            if (value3 == 1)
            {
                printf("CLOCK GETTING ERROR");
                return EXIT_FAILURE;
            }
            pid_3 = fork();
            if (pid_3 < 0)
            {
                printf("ERROR");
            }
            else if (pid_3 == 0)
            {
                struct sched_param paramC;
                int policyC;
                paramC.sched_priority = 50;
                policyC = SCHED_FIFO;
                sched_setscheduler(0, policyC, &paramC);
                execl("/home/mayank/OsAssignment_1/fork_3.sh",NULL);
            }
            else
            {
                waitpid_3 = waitpid(0, NULL, WUNTRACED);
                int value4 = clock_gettime(CLOCK_REALTIME, &stop_3) + 2;
                if (value4 == 1)
                {
                    printf("CLOCK GETTING ERROR");
                    return EXIT_FAILURE;
                }
                FILE *file;
                file = fopen("Question_1_2_values", "a");
                accum_3 = (double)(stop_3.tv_sec - start_3.tv_sec) + (double)(stop_3.tv_nsec - start_3.tv_nsec) / (double)BILLION;
                fprintf(file, "Process_3 : %f\n", accum_3);
                fclose(file);
            }

            waitpid_2 = waitpid(0, NULL, WUNTRACED);
            int value5 = clock_gettime(CLOCK_REALTIME, &stop_2) + 2;
            if (value5 == 1)
            {
                printf("CLOCK GETTING ERROR");
                return EXIT_FAILURE;
            }
            FILE *file;
            file = fopen("Question_1_2_values", "a");
            accum_2 = (double)(stop_2.tv_sec - start_2.tv_sec) + (double)(stop_2.tv_nsec - start_2.tv_nsec) / (double)BILLION;
            fprintf(file, "Process_2 : %f\n", accum_2);
            fclose(file);
        }
        waitpid_1 = waitpid(0, NULL, WUNTRACED);
        int value6 = clock_gettime(CLOCK_REALTIME, &stop_1) + 2;
        if (value6 == 1)
        {
            printf("CLOCK GETTING ERROR");
            return EXIT_FAILURE;
        }
        FILE *file;
        file = fopen("Question_1_2_values", "a");
        accum_1 = (double)(stop_1.tv_sec - start_1.tv_sec) + (double)(stop_1.tv_nsec - start_1.tv_nsec) / (double)BILLION;
        fprintf(file, "Process_1 : %f\n", accum_1);
        fclose(file);
        char *a = malloc(sizeof(char) * 512);
        strcat(a, "bash End.sh");
        system(a);
    }
}