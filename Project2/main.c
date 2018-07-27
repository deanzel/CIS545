/* Dean Choi & Binu Joyce
 * CIS 545 - Assignment 2 - Sum of square roots using multiple threads
 * Goal - Write a program which uses three threads concurrently to compute the sum of square roots from 1 to n, where
 * n is a multiple of 3 and is specified in the command line.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <sys/wait.h>
#include <pthread.h>

int start_points[4];
double grand_sum;
int grand_sum_lock;



int main(int argc, char *argv[]) {
    printf("Hello, World!\n");
    return 0;



}