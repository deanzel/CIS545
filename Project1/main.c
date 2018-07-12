/* Dean Choi & Binu Joyce
 * CIS 545 - Assignment 1 - Inter process communication
 * Goal - Write an inter process communication program in C language to exchange messages between parent process and
 * child processes. This assignment is aimed to learn fork() and pipe() functionalities.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>

int numChild = 2;   //default number of child processes

char* parentmsg = "Hi, I am your parent from CIS 345";        //33 characters (+ 1 null operator)
//childmsg will be concatenation of childmsg1 + number i + childmsg2 (will differ if more digits in i)
char* childmsg1 = "Message from Child ";            //19 characters
char* childmsg2 = ": RECEIVED";                     //10 characters


int main() {
    pid_t pid;

    printf("\nWelcome to Dean and Binu's Inter Process Communication Program.\n");
    printf("\nHow many child processes do you want to create?\n");
    scanf("%d", &numChild);


    if (numChild > 0) {
        //Before creating child processes with fork(), must create the 2*n pipes in parent process. Need two unidirectional
        //pipes for each Child process to have 2-way communication with the Parent Process. We'll statically allocate the
        //memory for the filedescriptor 2d array of the pipes.

        int **fd = calloc((size_t) numChild, sizeof(int *));
        int i;
        for (i = 0; i < 2*numChild; i++) {
            fd[i] = calloc(2, sizeof(int));
        }


        //fork() declaration statements for n Child processes along with creating 2 pipes for each child
        for (i=0; i<numChild; i++){
            //First create pipe1 (2i) and pipe2 (2i+1)
            if (pipe(fd[2*i]) < 0) {        //make this Parent(write,1)-to-Child(read,0) pipe
                printf("\nCannot create pipe for Child %d...", (i+1));
                exit(1);
            }
            if (pipe(fd[2*i+1]) < 0) {      //make this Child(write,1)-to-Parent(read,0) pipe
                printf("\nCannot create pipe for Child %d...", (i+1));
                exit(1);
            }

            //How many digits in the integer i
            int idigits = floor(log10 (abs(i+1))) + 1;


            if ((pid = fork()) == 0){
                //Child process and int i will determine which child iteration it is

                //Child Process will read from Pipe1 and receive Parent's message and print it
                size_t buffsize = strlen(parentmsg) + 1;
                char message1[buffsize];

                if (read(fd[2*i][0], message1, buffsize) != -1){
                    printf("\nChild Process #%d's Read Pipe Output:\n", (i+1));
                    printf("%s\n", message1);
                }
                else {      //Pipe read failed.
                    printf("\nChild #%d's pipe read failed.\n", (i+1));
                }
                close(fd[2*i][0]);     //optional for child?
                close(fd[2*i][1]);


                //Create child message string with specific number i
                buffsize = strlen(childmsg1) + strlen(childmsg2) + idigits + 1;
                char message2[buffsize];
                char numi[idigits + 1];
                sprintf(numi, "%d", (i+1));

                strcpy(message2, childmsg1);
                strcat(message2, numi);
                strcat(message2, childmsg2);

                //Child Process will write to Pipe2 and send child's message to Parent
                if (write(fd[2*i+1][1], message2, buffsize) == -1) {      //If -1. Pipe write failed.
                    printf("\nChild #%d's write to Pipe failed.", (i+1));
                }
                close(fd[2*i + 1][0]);     //optional?
                close(fd[2*i + 1][1]);

                //Terminate child process (don't need to close pipes since killing process)
                exit(1);


            }
            else if (pid > 0){
                //Parent process of Child Loop #i
                //Parent process must first send/write the parentmsg via Pipe1 to the Child
                if (write(fd[2*i][1], parentmsg, strlen(parentmsg) + 1) == -1) {      //If -1. Pipe write failed.
                    printf("\nParent Loop #%d's write to Pipe failed.", (i+1));
                }
                close(fd[2*i][0]);     //close pipe1 after writing to it
                close(fd[2*i][1]);

                //parent process after writing to pipe1 will wait for the forked child process to terminate before continuing.
                wait(NULL);


                size_t buffsize = strlen(childmsg1) + strlen(childmsg2) + idigits + 1;
                char childmsg[buffsize];
                //Parent Process will read from Pipe2 the child's message
                if (read(fd[2*i + 1][0], childmsg, buffsize) != -1){
                    printf("\nParent Process Loop #%d's Read Pipe Output:\n", (i+1));
                    printf("%s\n", childmsg);
                }
                else {      //Pipe read failed.
                    printf("\nParent Loop #%d's pipe read failed.", (i+1));
                }
                close(fd[2*i + 1][0]);
                close(fd[2*i + 1][1]);


            }

            else {
                //Failed to fork child
                printf("\nFailed to fork Child #%d...\n", (i+1));
            }

        }

    }

    else {
        //User does not specify creation of any child processes, so give error message and end program.
        printf("\nYou must have 1 or more child processes for this to work...\n");
    }



    return 0;

}