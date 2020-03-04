#pragma once

#include <stdlib.h>

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