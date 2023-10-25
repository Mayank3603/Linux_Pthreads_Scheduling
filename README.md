# Linux_Pthreads_Scheduling

## 1.1 Thread Scheduling
- Three Threads for three different functions , Each function does the same
thing, i.e. counts from 1 – 232.    
   
- Thread 1 (call it Thr-A()): Uses SCHED OTHER 
- Thread 2 (call it Thr-B()): Uses SCHED RR
- Thread 3 (call it Thr-C()): Uses SCHED FIFO 
- Use the clock gettime() function o compute how long it took to complete a function
- Use of pthread_schedsetparam() to change priority of the threads.
