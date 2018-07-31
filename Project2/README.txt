Dean Choi & Binu Joyce
CIS 545 - Assignment 2 - Sum of square roots using multiple threads
The goal is to write a program which uses three threads concurrently to compute the sum of square roots from 1 to n, where n is a multiple of 3 and is specified in the command line.

============================================================================
*Project Description:
This C program will compute the sum of square roots from 1 to n, where n is a multiple of 3, and n is specified in the command line. The program gets the value n from the command line argument (using argc / argv) and converts it to an integer after checking that it is in the right format. Next, it creates two threads using pthread_create(). Then, the main thread computes the sum of square roots from 1 to n/3, while the two child threads compute the sum of the square roots from n/3+1 to 2n/3 and 2n/3+1 to n, respectively, at the same time as the main thread’s calculation using the *sum_of_sqrt function call. All three partial sums are added together to a shared global variable (grand_sum) by each thread at the end of execution. The main thread calls pthread_join() to wait for the termination of the two child threads and then prints the final result.

spirit> ./myexec 9
sum of square roots: 19.306001

============================================================================
*Compiling Instructions:
The source code of this program is "main.c"

It comes with an accompanying Makefile in the project folder. To compile the “myexec” executable binary, just type in the “make” command at the Terminal in the working directory.

If the Makefile is not present, you can compile the executable via gcc in Terminal with the following command:

	gcc -o myexec main.c -I. -lm -lpthread

“-lm” and “-lpthread” options are to include the math and pthread libraries in our executable binary when compiling via GCC.

============================================================================
*Running Instructions:
This program binary takes input directly from the command line, so you must include the number (that is a multiple of 3) after the execution prompt. Thus, the correct execution of this binary has two total arguments where the first is “./myexec” and the second is the number (n) that is a multiple of 3.

	./myexec n

If you do not have the correct number of command line arguments, or if the number that you entered is not a multiple of 3, the program will print out the appropriate error message.

============================================================================

***************************  Sample Test Run:  ***************************

verdi:~/CIS545% make
gcc -o myexec main.c -I. -lm -lpthread

verdi:~/CIS545% ./myexec 9
sum of square roots: 19.306001

verdi:~/CIS545% ./myexec 3
sum of square roots: 4.146264

verdi:~/CIS545% ./myexec 30
sum of square roots: 112.082845

verdi:~/CIS545% ./myexec 9999
sum of square roots: 666616.459197

verdi:~/CIS545% ./myexec 31
The input number is not a multiple of 3...

verdi:~/CIS545% ./myexec 30 3
That is the incorrect number of command line arguments...

verdi:~/CIS545% ./myexec pizza
The command line input is not a number...

verdi:~/CIS545% ./myexec 99
sum of square roots: 661.462947


============================================================================
*Existing Bugs: No known bugs 

============================================================================
