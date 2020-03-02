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
 * @file stat.h
 * @brief Header file for the stats.c file.
 *
 * Contains structs and function headers for the stats.h file.
 *
 * @author Collin Smith
 * @date March 1st, 2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */

#include <stdlib.h>

/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */

/**
 * @brief Statistical_Values struct holds common statistical values
 * derived from an array.
 *
 * The primary purpose is to reduce the number of parameters
 * in key function definitions. This Struct definition includes
 * a constructor that malloc's space and sets variables.
 *
 * A destructor is unnecessary. free(stats) will free memory.
 *
 * @param unsigned char max The maximum value of an array
 * @param unsigned char min The minimum value of an array
 * @param unsigned char mean The mean value of an array
 * @param unsigned char median The median value of an array.
 *
 * @return Statistical_Values* pointer to a struct
 */

typedef struct {
    unsigned char max;
    unsigned char min;
    unsigned char mean;
    unsigned char median;
} Statistical_Values;

Statistical_Values* create_stats(unsigned char max, unsigned char min,
        unsigned char mean, unsigned char median);

Statistical_Values* create_stats(unsigned char max, unsigned char min,
                                 unsigned char mean, unsigned char median){

    Statistical_Values* v = malloc(sizeof(Statistical_Values));

    v->max = max;
    v->min = min;
    v->mean = mean;
    v->median = median;

    return v;
}

/**
 * @brief Prints the statistical derivatives of an array of numbers
 *
 * This function will print the mean, median, max and min values of
 * a given array.
 *
 * @param stats Statistical_Values* to a struct holding the statistical derivatives
 * of a given array.
 */

void print_statistics(Statistical_Values* stats);

/**
 * @brief Prints the values of an array.
 *
 * @param unsigned char * nums pointer to the array.
 * @param int len number of elements in the array.
 */

void print_array(unsigned char * nums, int len);

/**
 * @brief Calculates the median value of the array.
 *
 * This is going to return the len/2 value of the array after
 * it has been sorted. I am still trying to think of something
 * different but all solutions are at least n lon n so far.
 *
 * @param unsigned char * nums pointer to the array.
 * @param int len number of elements in the array.
 *
 * @return unsigned char median value of numbers in the array
 */
unsigned char find_median(unsigned char * nums, int len);

/**
 * @brief Calculates the mean value of the array.
 *
 * This is going to return an unsigned char so it is going  to
 * truncate anything that would come after the decimal. Just
 * assume it is a floor.
 *
 * @param unsigned char * nums pointer to the array.
 * @param int len number of elements in the array.
 *
 * @return unsigned char mean value of numbers in the array
 */
unsigned char find_mean(unsigned char * nums, int len);

/**
 * @brief  the largest value of the array.
 *
 * @param unsigned char * nums pointer to the array.
 * @param int len number of elements in the array.
 *
 * @return unsigned char max value of numbers in the array
 */

unsigned char find_maximum(unsigned char * nums, int len);

/**
 * @brief  the mallest value of the array.
 *
 * @param unsigned char * nums pointer to the array.
 * @param int len number of elements in the array.
 *
 * @return unsigned char min value of numbers in the array
 */

unsigned char find_minimum(unsigned char * nums, int len);

/**
 * @brief  Sorts the array descending.
 *
 * I arbitrarily chose quick sort so this method is going to
 * call a qsort() helper.
 *
 * @param unsigned char * nums pointer to the array.
 * @param int len number of elements in the array.
 *
 * @return unsigned char max value of numbers in the array
 */
void sort_array(unsigned char * nums, int len);

/**
 * @brief  Sorts the array descending in place using qsort algorithm.
 *
 * @param unsigned char * nums pointer to the array.
 * @param int high higher bound index to .
 * @param int low lower bound index to be sorted.
 */
void qsort_array(unsigned char * nums, int low, int high);

/**
 * @brief  QSort Partition helper puts the pivot number in the right place.
 *
 * This is the method that takes the pivot value and puts elements
 * less than the pivot on the left and elements greater than the
 * pivot on the right of the pivot in the array before placing the
 * pivot.
 *
 * @param unsigned char * nums pointer to the array.
 * @param int high higher bound index to .
 * @param int low lower bound index to be sorted.
 *
 * @return int New partition index
 *
 */
int qsort_partition(unsigned char * nums, int low, int high);

/**
 * @brief  Helper to swap 2 numbers by reference.
 *
 * @param int a number to be swapped
 * @param int b number to be swapped
 *
 */
void swap(unsigned char*a, unsigned char*b);

#endif /* __STATS_H__ */
