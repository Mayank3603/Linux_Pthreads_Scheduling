# Linux_Pthreads_Scheduling

1.1 Thread Scheduling
->In this Scheduling , we launch three threads, each of which relies on three different
functions, countA(), countB() and countC(). Each function does the same
thing, i.e. counts from 1 – 232.     
->Thread 1 (call it Thr-A()): Uses SCHED OTHER scheduling discipline
with standard priority (nice:0).
-> Thread 2 (call it Thr-B()): Uses SCHED RR scheduling discipline with
default priority.
-> Thread 3 (call it Thr-C()): Uses SCHED FIFO scheduling discipline with
default priority.
->use the clock gettime() function for obtaining the actual time ticks that
can be used to compute how long it took to complete a function
-> Use of pthread_schedsetparam() to change priority of the threads.
