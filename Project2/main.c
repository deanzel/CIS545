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

int start_points[4];
double grand_sum;
pthread_mutex_t grand_sum_lock;

struct Bounds {     //simple struct for the lower and upper bounds of the range of numbers to have their square roots summed
    int start, end;
};


void *sum_of_sqrt(void *bounds) {      //Return sum of square roots from int bounds.start to int bounds.end - 1
    //Cast the void *bounds pointer to the struct pointer
    struct Bounds *b = (struct Bounds *) bounds;
    double sum = 0.0;

    //calculate local sum of square roots
    for (int i = (int) &b->start; i < (int) &b->end; i++) {
        sum += sqrt(i);
    }

    pthread_mutex_lock(&grand_sum_lock);   //acquiring lock
    grand_sum += sum;                   //updating grand_sum by adding t
    pthread_mutex_unlock(&grand_sum_lock); //lock release;

    return NULL;
}


//Make it a command line input
int main(int argc, char *argv[]) {

    double grand_sum = 0;
    pthread_t t1, t2;

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
        else        //Integer is a multiple of 3 so we can continue
        {

            printf("\n%d is the number!!!!!\n", n);

            pthread_mutex_init(&grand_sum_lock, 0);  //mutex initialization

            start_points[0] = 1;
            start_points[1] = n/3+1;
            start_points[2] = 2*n/3+1;
            start_points[3] = n+1;

            struct Bounds bounds1 = { .start = start_points[0], .end = start_points[1]};
            struct Bounds bounds2 = { .start = start_points[1], .end = start_points[2]};
            struct Bounds bounds3 = { .start = start_points[2], .end = start_points[3]};


            pthread_create(&t1, NULL, sum_of_sqrt, (void *) &bounds1);
            pthread_create(&t2, NULL, sum_of_sqrt, (void *) &bounds2);

            sum_of_sqrt(&bounds3);
            pthread_join(t1, NULL);
            pthread_join(t2, NULL);


            printf("\nsum of square roots: %lf \n", grand_sum);
            pthread_mutex_destroy(&grand_sum_lock);
        }

        
    }



  return 0;
  
  
}
