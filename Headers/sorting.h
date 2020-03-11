#pragma once

#include <stdio.h>
#include <stdlib.h>

void swap (int *, int *);
int partition (int *, int, int);
int partition_random (int *, int, int);
int findMin(int*, unsigned int, unsigned int);
void addItemToHeap(int*, int*, int);
void upHeapify(int*, int);
int pollHeap(int*, int*);
void downHeapify(int*, int, int*);

void selectionSort(int*, unsigned int);
void insertionSort(int*, unsigned int);
void quickSort(int*, unsigned int);
void heapSort(int*, unsigned int);
void insertion_sort(int*, unsigned int);
void quick_sort(int *, unsigned int);
void sort (int *, int, int);