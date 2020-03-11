#ifndef SORTING_H_INCLUDED
#define SORTING_H_INCLUDED

#pragma once
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int*, unsigned int);
void swap (int *, int *);
int partition (int *, int, int);
int partition_random (int *, int, int);
void sort (int *, int, int);
void quick_sort(int *, unsigned int);

int findMin(int*, unsigned int, unsigned int);
void swap(int*, int*);

void addItemToHeap(int*, int*, int);
void upHeapify(int*, int);
int pollHeap(int*, int*);
void downHeapify(int*, int, int*);

void selectionSort(int*, unsigned int);
void insertionSort(int*, unsigned int);
void quickSort(int*, unsigned int);
void heapSort(int*, unsigned int);

#endif // SORTING_H_INCLUDED
