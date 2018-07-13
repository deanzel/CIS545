Dean Choi & Binu Joyce
CIS 545 - Assignment 1 - Inter process communication
This assignment is aimed to learn fork() and pipe() functionalities.

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

Child Process #1 (pid: 6757) Read Pipe Output:
- Hi, I am your parent from CIS 345

Parent Process Loop #1 (pid: 6756) Read Pipe Output:
- Message from Child 1: RECEIVED

Child Process #2 (pid: 6758) Read Pipe Output:
- Hi, I am your parent from CIS 345

Parent Process Loop #2 (pid: 6756) Read Pipe Output:
- Message from Child 2: RECEIVED


***************************  Sample Test Run 2:  ***************************

Deans-MBP:~ deanchoi$ /Users/deanchoi/CLionProjects/CIS545/Project1/myexec 

Welcome to Dean and Binu's Inter Process Communication Program.

How many child processes do you want to create?
10

Child Process #1 (pid: 5372) Read Pipe Output:
- Hi, I am your parent from CIS 345

Parent Process Loop #1 (pid: 5370) Read Pipe Output:
- Message from Child 1: RECEIVED

Child Process #2 (pid: 5373) Read Pipe Output:
- Hi, I am your parent from CIS 345

Parent Process Loop #2 (pid: 5370) Read Pipe Output:
- Message from Child 2: RECEIVED

Child Process #3 (pid: 5374) Read Pipe Output:
- Hi, I am your parent from CIS 345

Parent Process Loop #3 (pid: 5370) Read Pipe Output:
- Message from Child 3: RECEIVED

Child Process #4 (pid: 5375) Read Pipe Output:
- Hi, I am your parent from CIS 345

Parent Process Loop #4 (pid: 5370) Read Pipe Output:
- Message from Child 4: RECEIVED

Child Process #5 (pid: 5376) Read Pipe Output:
- Hi, I am your parent from CIS 345

Parent Process Loop #5 (pid: 5370) Read Pipe Output:
- Message from Child 5: RECEIVED

Child Process #6 (pid: 5377) Read Pipe Output:
- Hi, I am your parent from CIS 345

Parent Process Loop #6 (pid: 5370) Read Pipe Output:
- Message from Child 6: RECEIVED

Child Process #7 (pid: 5378) Read Pipe Output:
- Hi, I am your parent from CIS 345

Parent Process Loop #7 (pid: 5370) Read Pipe Output:
- Message from Child 7: RECEIVED

Child Process #8 (pid: 5379) Read Pipe Output:
- Hi, I am your parent from CIS 345

Parent Process Loop #8 (pid: 5370) Read Pipe Output:
- Message from Child 8: RECEIVED

Child Process #9 (pid: 5380) Read Pipe Output:
- Hi, I am your parent from CIS 345

Parent Process Loop #9 (pid: 5370) Read Pipe Output:
- Message from Child 9: RECEIVED

Child Process #10 (pid: 5381) Read Pipe Output:
- Hi, I am your parent from CIS 345

Parent Process Loop #10 (pid: 5370) Read Pipe Output:
- Message from Child 10: RECEIVED

============================================================================
*Existing Bugs: No known bugs 

============================================================================
