Dean Choi & Binu Joyce
CIS 545 - Assignment 2 - Sum of square roots using multiple threads
The goal is to write a program which uses three threads concurrently to compute the sum of square roots from 1 to n, where n is a multiple of 3 and is specified in the command line.

============================================================================
*Project Description:
This C console program will allow the user to create n number of child 
processes and exchange messages between parent process and child processes.

Each child process reads and prints the message sent by the parent process:
        Child Process #1 (pid: 6274) Read Pipe Output:
        - Hi, I am your parent from CIS 345

The parent process also reads and prints the messages it receives from each 
of it child process as below:
        Parent Process Loop #1 (pid: 6271) Read Pipe Output:
        - Message from Child 1: RECEIVED

NOTE: For cases in which the user enters anything other than numbers the 
program will create 2 child processes as that has been set as the default. 

============================================================================
*Compiling Instructions:
The source code of this program is "main.c"

It comes with an accompanying Makefile in the project folder. To compile the “myexec” executable binary, just type in the “make” command at the Terminal. Run the binary by typing in ./myexec

If the Makefile is not present, you can compile the executable via gcc in Terminal with the following command:

		gcc -o myexec main.c -I. -lm

============================================================================
***************************  Sample Test Run 1:  ***************************

jazzconnecthp@jazzconnecthp:~/git/CIS545/Project1$ ./myexec

Welcome to Dean and Binu's Inter Process Communication Program.

How many child processes do you want to create?
ab#



============================================================================
*Existing Bugs: No known bugs 

============================================================================
