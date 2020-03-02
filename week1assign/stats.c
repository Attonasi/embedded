/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief This file takes a given array and finds some common statistical values
 *        for the numbers in that array.
 *
 * A general C refresher assignment. There are some simple functions for finding
 * Max, Min, Mean and Median values in an array and a qsort implementation for
 * sorting.
 *
 * @author Collin Smith
 * @date March 1st, 2020
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
//#define SIZE 4
#define SIZE (40)

void main() {

//    unsigned char test[SIZE] = {1,6,3,2};

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */

  Statistical_Values * stats = create_stats(0, 0, 0, 0);

  /* Statistics and Printing Functions Go Here */

  print_array(test, SIZE);

  stats->median = find_median(test, SIZE);
  stats->mean = find_mean(test, SIZE);
  stats->max = find_maximum(test, SIZE);
  stats->min = find_minimum(test, SIZE);

  print_statistics(stats);

  /* Should be Sorted */
  print_array(test, SIZE);

  free(stats);
}

/* Add other Implementation File Code Here */

void print_statistics(Statistical_Values * stats) {

    printf(" \n Maximum value:\t %u", stats->max);
    printf(" \n Minimum value:\t %u", stats->min);
    printf(" \n Mean value:\t %u", stats->mean);
    printf(" \n Median value:\t %u", stats->median);
}

void print_array(unsigned char * nums, int len) {

    printf("\n********* Array Elements **********\n\n[ ");
    for ( int i = 0; i < len; i++) {
        if (i==len-1) {
            printf("%u ]", nums[i]);
            break;
        }
        if ( i%10==0 && i>0) {
            printf("\n");
        }
        printf("%u, ", nums[i]);
    }
    printf("\n\n ******************************* \n");
}

unsigned char find_median(unsigned char * nums, int len) {
    sort_array(nums, len);

    return nums[len/2];
}

unsigned char find_mean(unsigned char * nums, int len) {

    int sum = 0;
    for ( int i = 0; i < len; i++) {
        sum = sum + nums[i];
    }
    unsigned char ret = sum/len;
    return ret;
}

unsigned char find_maximum(unsigned char * nums, int len) {
    unsigned char max = 0;

    for (int i = 0; i < len; i++) {
        if (nums[i] > max) { max = nums[i]; }
    }
    return max;
}

unsigned char find_minimum(unsigned char * nums, int len) {
    unsigned char min = 255;

    for (int i = 0; i < len; i++) {
        if (nums[i] < min) { min = nums[i]; }
    }
    return min;
}

void sort_array(unsigned char * nums, int len) {
    qsort_array(nums, 0, len-1);
}

/* qsort implementation */

void qsort_array(unsigned char * nums, int low, int high) {

    if (low < high) {
        int pivot_index = qsort_partition(nums, low, high);

        qsort_array(nums, low, pivot_index-1);
        qsort_array(nums, pivot_index+1, high);
    }
}

int qsort_partition(unsigned char * nums, int low, int high) {

    int i = low;
    for (int j = low; j <= high; j++) {
        if (nums[j] < nums[high]) {
            swap(&nums[i], &nums[j]);
            i++;
        }
    }
    swap(&nums[i], &nums[high]);
    return i;
}

void swap(unsigned char* a, unsigned char* b){
    if(*a==*b){ return; }
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}