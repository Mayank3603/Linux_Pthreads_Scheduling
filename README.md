# Linux_Pthreads_Scheduling

## 1.1 Thread Scheduling
- Three Threads for three different functions , Each function does the same
thing, i.e. counts from 1 – 232.    
   
- Thread 1 (call it Thr-A()): Uses SCHED OTHER 
- Thread 2 (call it Thr-B()): Uses SCHED RR
- Thread 3 (call it Thr-C()): Uses SCHED FIFO 
- Use the clock gettime() function o compute how long it took to complete a function
- Use of pthread_schedsetparam() to change priority of the threads.

#### 1.1 Result (Histogram)

![Graph1_1](https://github.com/Mayank3603/Linux_Pthreads_Scheduling/assets/107765257/51a3ef95-1749-4c98-ad8f-a806787ea501)

#### 1.1 Time Taken for different Scheduling Patterns :

https://github.com/Mayank3603/Linux_Pthreads_Scheduling/blob/main/src/2021065_1.1/Time_Taken.txt

#### For Further Understanding :

https://github.com/Mayank3603/Linux_Pthreads_Scheduling/blob/main/src/2021065_1.1/Documentation_1.1.pdf

## 1.2 Process Sceduling 
