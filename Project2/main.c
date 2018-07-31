/* Dean Choi & Binu Joyce
 * CIS 545 - Assignment 2 - Sum of square roots using multiple threads
 * Goal - Write a program which uses three threads concurrently to compute the sum of square roots from 1 to n, where
 * n is a multiple of 3 and is specified in the command line.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <ctype.h>
#include <string.h>

#define ARR_LENGTH 4

double *grand_sum_ptr;
pthread_mutex_t grand_sum_lock;

//critical region update function
void add_all(double t) {
   pthread_mutex_lock(&grand_sum_lock);   //acquiring lock
   *grand_sum_ptr += t;                   //updating grand_sum
   pthread_mutex_unlock(&grand_sum_lock); //lock release
}

void *sum_of_sqrt(void *arr) {
  int i;
  double sum = 0.0;
  int *num = (int *)arr;   //retrieving the array values to use
  
  for (i=*num; i<*(num+1); i++)
  {
    sum += sqrt(i);
  }
  add_all(sum);            //function to update the critical region
}


//Make it a command line input
int main(int argc, char *argv[]) {

    if (argc != 2){     //Have more than 2 arguments (or only 1) in command line call
        printf("\nThat is the incorrect number of command line arguments...\n");
        exit(1);

    }
    else {      //Have exactly 2 arguments
        //Check if the 2nd argument string is an integer
        for (int i=0; i < strlen(argv[1]); i++) {
            if (!isdigit(argv[1][i])) {     //Checks each char to see if it is numeric digit; if not, error exit
                printf("\nThe command line input is not a number...\n");
                exit(2);
            }
        }

        //2nd argument is a number so convert that string into an integer n
        int n = atoi(argv[1]);

        if (n%3 != 0)
        {
            printf("\nThe input number is not a multiple of 3...\n");
            exit(3);
        }
        else
        {

            printf("%d is the number!!!!!", n);

            double grand_sum = 0;
            int start_points[ARR_LENGTH], n, i, j;
            pthread_t threads[2];
            grand_sum_ptr = &grand_sum;

            pthread_mutex_init(&grand_sum_lock, 0);  //mutex initialization

            for (i=0; i<ARR_LENGTH; i++)       //loop to update start_points
            {
                start_points[i] = (i*(n/3))+1;
                //printf("start_points[%d] = %d \n", i, start_points[i]);
            }
            j=1;                               //counter for start_point  postions
            for (i=0; i<2; i++)
            {
                pthread_create(&threads[i], NULL, sum_of_sqrt, (void *)&start_points[j]);        //child thread creation
                j++;
            }

            sum_of_sqrt((void *)&start_points[0]);     //main thread's call to sum_of_sqrt()

            for (i=0; i<2; i++)
            {
                pthread_join(threads[i], NULL);    //waiting for all child threads to finish
            }
            printf("\nThe sum of the square roots: %lf \n", grand_sum);
            pthread_mutex_destroy(&grand_sum_lock);
        }




    }



  return 0;
  
  
}
