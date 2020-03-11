#include "../Headers/sorting.h"

void insertion_sort(int *t, unsigned int n) {
    int j, i, key;
    for (j=1; j< n-1; j++){
        key = t[j];
        i = j - 1;
        while (i>= 0 && t[i]> key){
            t[i+1]= t[i];
            i = i -1;
        }
        t[j+1]= key;
    }
}

int partition (int *tab, int first, int last){
    int pivot = tab[last];
    int i = first - 1;
    for (int j = first; j < last; j++){
        if (tab[j] <= pivot){
            i = i + 1;
            swap(&tab[i], &tab[j]);
        }
    i = i +1;
    swap(&tab[i], &tab[last]);
    return i;
    }
}

int partition_random (int *tab, int first, int last){
    srand(time(NULL));
    int i= first + rand()%(last - first);
    swap(&tab[i], &tab[last]);
    return partition(tab, first, last);
}

void sort (int *tab, int first, int last){
    if (first < last){
        int q = partition(tab, first, last);
        sort(tab, first, q -1);
        sort(tab, q + 1, last);
    }
}

void quick_sort(int *t, unsigned int n) {
    sort(t, 0, n-1);
}

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
        } czesc_Oliwia
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
    int minItem = rightChild >= *size || heap[leftChild] < heap[rightChild] ? leftChild : rightChild; // TODO: MoÅ¼e zamieniÄ to na ify bo nie jest specjalnie czytelne
    int minItem = rightChild >= *size || heap[leftChild] < heap[rightChild] ? leftChild : rightChild; // TODO: Mo¿e zamieniæ to na ify bo nie jest specjalnie czytelne

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
