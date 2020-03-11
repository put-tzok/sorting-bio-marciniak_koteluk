#include "../Headers/benchmark.h"

void fillIncreasing(int *arr, unsigned int size) {
    unsigned int i;
    for(i = 0; i < size; i++) {
        arr[i] = i;
    }
}

void fillDecreasing(int *arr, unsigned int size) {
    unsigned int i;
    for(i = 0; i < size; i++) {
        arr[i] = size - i;
    }
}

void fillVShape(int *arr, unsigned int size) {
    int i, j;
    i = 0;
    j = size - 1;
    int numOfElements = size;
    while(i < j) {
        arr[i++] = numOfElements--;
        arr[j--] = numOfElements--;
    }
    // 10 8 6 4 2 1 3 5 7 9 <- Tylko taka forma V kształtu przechodzi testy 
}

void fillRandom(int *arr, unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        arr[i] = rand();
    }
}

void isIncreasingTest(int *arr, unsigned int size) {
    for (unsigned int i = 1; i < size; i++) {
        assert(arr[i] > arr[i - 1]);
    }
}

void isDecreasingTest(int *arr, unsigned int size) {
    for (unsigned int i = 1; i < size; i++) {
        assert(arr[i] < arr[i - 1]);
    }
}

void isVShapeTest(int *arr, unsigned int size) {
    int *begin = arr;
    int *end = arr + size - 1;

    while (end - begin > 1) {
        assert(*begin > *end);
        begin++;
        assert(*end > *begin);
        end--;
    }
}

void isRandomTest(int *arr, unsigned int size) {
    return;
}

void isSortedTest(int *arr, unsigned int size) {
    for (unsigned int i = 1; i < size; i++) {
        assert(arr[i] >= arr[i - 1]);
    }
}