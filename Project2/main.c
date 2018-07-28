/* Dean Choi & Binu Joyce
 * CIS 545 - Assignment 2 - Sum of square roots using multiple threads
 * Goal - Write a program which uses three threads concurrently to compute the sum of square roots from 1 to n, where
 * n is a multiple of 3 and is specified in the command line.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define ARR_LENGTH 4

double *grand_sum_ptr;
pthread_mutex_t grand_sum_lock;

//critical region update function
void add_all(double t)
{
   pthread_mutex_lock(&grand_sum_lock);   //acquiring lock
   *grand_sum_ptr += t;                   //updating grand_sum
   pthread_mutex_unlock(&grand_sum_lock); //lock release
}

void *sum_of_sqrt(void *arr)
{
  int i;
  double sum = 0.0;
  int *num = (int *)arr;   //retrieving the array values to use
  
  for (i=*num; i<*(num+1); i++)
  {
    sum += sqrt(i);
  }
  add_all(sum);            //function to update the critical region
}

int main(int argc, char *argv[])
{
  double grand_sum = 0;
  int start_points[ARR_LENGTH], n, i, j;
  pthread_t threads[2];
  grand_sum_ptr = &grand_sum;
  
  pthread_mutex_init(&grand_sum_lock, 0);  //mutex initialization
  
  printf("Enter any number (Should be a multiple of three): ");
  scanf("%d", &n);
  
  if (n%3 != 0)
  {
    printf("Invalid entry!\n");
    exit(1);
  }
  else
  {
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
    printf("sum of square roots: %lf \n", grand_sum);
    pthread_mutex_destroy(&grand_sum_lock);
  }
  
    
  
  
  
  
}
