#include "../Headers/sorting.h"

void swap(int *src, int *dest) {
    int temp = *src;
    *src = *dest;
    *dest = temp;
}

int findMin(int *arr, unsigned int startingIndex, unsigned int size) {
    unsigned int i;
    int minIndex = startingIndex;
    int minElement = arr[startingIndex];
    for(i = startingIndex; i < size - 1; i++) {
        if(arr[i + 1] < minElement) {
            minIndex = i + 1;
            minElement = arr[i + 1];
        }
    }
    return minIndex;
}

void addItemToHeap(int* heap, int* size, int item) {
    heap[*size] = item;
    upHeapify(heap, *size);
    *size = *size + 1;
}

void upHeapify(int* heap, int index) {
    if(index > 0) {
        int parent = (index - 1) / 2;
        if(heap[index] < heap[parent]) {
            swap(&heap[index], &heap[parent]);
            upHeapify(heap, parent);
        } 
    }
}

int pollHeap(int* heap, int* size) {
    int item = heap[0];
    *size = *size - 1;
    heap[0] = heap[*size];
    downHeapify(heap, 0, size);
    return item;
}

void downHeapify(int* heap, int index, int* size) {
    int leftChild = index * 2 + 1;
    int rightChild = index * 2 + 2;

    if(leftChild >= *size) return;
    int minItem = rightChild >= *size || heap[leftChild] < heap[rightChild] ? leftChild : rightChild; // TODO: Może zamienić to na ify bo nie jest specjalnie czytelne

    if(heap[minItem] < heap[index]) {
        swap(&heap[minItem], &heap[index]);
        downHeapify(heap, minItem, size);
    }
}

void selectionSort(int *arr, unsigned int size) {
    unsigned int i;
    for(i = 0; i < size; i++) {
        int index = findMin(arr, i, size);
        swap(&arr[i], &arr[index]);
    }
}
void insertionSort(int* arr, unsigned int size) { return; }
void quickSort(int* arr, unsigned int size) { return; }

void heapSort(int *arr, unsigned int arrSize) {
    int* heap = malloc(sizeof(int) * arrSize);
    int heapSize = 0;
    unsigned int i;
    for(i = 0; i < arrSize; i++) addItemToHeap(heap, &heapSize, arr[i]);
    for(i = 0; i < arrSize; i++) arr[i] = pollHeap(heap, &heapSize);
}
