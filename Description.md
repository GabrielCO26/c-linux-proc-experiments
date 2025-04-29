# c-linux-proc-experiments
This repository contains a collection of C programs designed to explore and understand how processes work in Linux. It includes practical examples using system calls like fork(), exec(), wait(), and signal handling, covering fundamental concepts of low-level process management.


## varios.c
varios.c is a C program that performs n consecutive fork() system calls to create a process tree. Each process enters an infinite while loop to remain active, allowing the user to observe the process hierarchy in real time. By running ps lf in another terminal, users can see the PID (Process ID) and PPID (Parent Process ID) of each running process. The program is intended to illustrate how processes are spawned and organized in Linux

## sumasec.c
sumasec.c is a C program where the parent process creates n child processes. Each child generates and prints a sequence of integers starting from its creation index i up to 2*(i + 1) - 1. The child calculates the sum of its sequence and returns it to the parent. The parent then displays the sums returned by each child along with their respective PIDs.
