#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Headers/sorting.h"
#include "Headers/benchmark.h"

unsigned int ns[] = { 10, /* 100, 1000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000*/ };

void (*fill_functions[])(int *, unsigned int) = { fillRandom, fillIncreasing, fillDecreasing, fillVShape };
void (*check_functions[])(int *, unsigned int) = { isRandomTest, isIncreasingTest, isDecreasingTest, isVShapeTest };
void (*sort_functions[])(int *, unsigned int) = { selectionSort, insertionSort, quickSort, heapSort };

char *fill_names[] = { "Random", "Increasing", "Decreasing", "V-Shape" };
char *sort_names[] = { "SelectionSort", "InsertionSort", "QuickSort", "HeapSort" };

int main() {
    for (unsigned int i = 0; i < sizeof(sort_functions) / sizeof(*sort_functions); i++) {
        void (*sort)(int *, unsigned int) = sort_functions[i];

        for (unsigned int j = 0; j < sizeof(fill_functions) / sizeof(*fill_functions); j++) {
            void (*fill)(int *, unsigned int) = fill_functions[j];
            void (*check)(int *, unsigned int) = check_functions[j];

            for (unsigned int k = 0; k < sizeof(ns) / sizeof(*ns); k++) {
                unsigned int n = ns[k];
                int *t = malloc(n * sizeof(*t));

                fill(t, n);
                check(t, n);

                clock_t begin = clock();
                sort(t, n);
                clock_t end = clock();
                isSortedTest(t, n);

                printf("%s\t%s\t%u\t%f\n", sort_names[i], fill_names[j], n, (double)(end - begin) / (double) CLOCKS_PER_SEC);
                free(t);
            }
        }
    }
    return 0;
}
