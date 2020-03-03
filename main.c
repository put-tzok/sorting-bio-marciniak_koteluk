#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// TEMPORARY
void heap_add(int* heap, int* size, int el);
void heap_up(int* heap, int index);
int heap_poll(int* heap, int* size);
void heap_down(int* heap, int index, int* size);
void heap_sort(int *t, unsigned int n);

unsigned int ns[] = { 10, 100, 1000, 10000, 20000, 30000, 40000, 50000, 60000  /* TODO: fill in "n" i.e. instance sizes */ };

void fill_increasing(int *t, unsigned int n) {
    unsigned int i;
    for(i = 0; i < n; i++) {
        t[i] = i;
    }
}

void fill_decreasing(int *t, unsigned int n) {
    unsigned int i;
    for(i = 0; i < n; i++) {
        t[i] = n - i;
    }
}

void fill_vshape(int *t, unsigned int n) {
    int i, j;
    i = 0;
    j = n - 1;
    int numOfElements = n;
    while(i < j) {
        t[i++] = numOfElements--;
        t[j--] = numOfElements--;
    }
    // 10 8 6 4 2 1 3 5 7 9
}

void swap(int *src, int *dest) {
    int temp = *src;
    *src = *dest;
    *dest = temp;
}

int find_min(int *t, unsigned int b, unsigned int n) {
    unsigned int i;
    int minIndex = b;
    int minEl = t[b];
    for(i = b; i < n - 1; i++) {
        if(t[i + 1] < minEl) {
            minIndex = i + 1;
            minEl = t[i + 1];
        }
    }
    return minIndex;
}

void selection_sort(int *t, unsigned int n) {
    unsigned int i;
    for(i = 0; i < n; i++) {
        int index = find_min(t, i, n);
        swap(&t[i], &t[index]);
    }
}

void insertion_sort(int *t, unsigned int n) {
    // TODO: implement
}

void quick_sort(int *t, unsigned int n) {
    // TODO: implement
}

void heap_add(int* heap, int* size, int el) {
    heap[*size] = el;
    heap_up(heap, *size);
    *size = *size + 1;
}

void heap_up(int* heap, int index) {
    if(index > 0) {
        int parent = (index - 1) / 2;
        if(heap[index] < heap[parent]) {
            swap(&heap[index], &heap[parent]);
            heap_up(heap, parent);
        } 
    }
}

int heap_poll(int* heap, int* size) {
    int el = heap[0];
    *size = *size - 1;
    heap[0] = heap[*size];
    heap_down(heap, 0, size);
    return el;
}

void heap_down(int* heap, int index, int* size) {
    int l = index * 2 + 1;
    int r = index * 2 + 2;

    if(l >= *size) return;
    int min = r >= *size || heap[l] < heap[r] ? l : r;

    if(heap[min] < heap[index]) {
        swap(&heap[min], &heap[index]);
        heap_down(heap, min, size);
    }
}

void heap_sort(int *t, unsigned int n) {
    int* heap = malloc(sizeof(int) * n);
    int size = 0;
    unsigned int i;
    for(i = 0; i < n; i++) heap_add(heap, &size, t[i]);
    for(i = 0; i < n; i++) t[i] = heap_poll(heap, &size);
}

void fill_random(int *t, unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        t[i] = rand();
    }
}

void is_random(int *t, unsigned int n) {
    return;
}

void is_increasing(int *t, unsigned int n) {
    for (unsigned int i = 1; i < n; i++) {
        assert(t[i] > t[i - 1]);
    }
}

void is_decreasing(int *t, unsigned int n) {
    for (unsigned int i = 1; i < n; i++) {
        assert(t[i] < t[i - 1]);
    }
}

void is_vshape(int *t, unsigned int n) {
    int *begin = t;
    int *end = t + n - 1;

    while (end - begin > 1) {
        assert(*begin > *end);
        begin++;
        assert(*end > *begin);
        end--;
    }
}

void is_sorted(int *t, unsigned int n) {
    for (unsigned int i = 1; i < n; i++) {
        assert(t[i] >= t[i - 1]);
    }
}

void (*fill_functions[])(int *, unsigned int) = { fill_random, fill_increasing, fill_decreasing, fill_vshape };
void (*check_functions[])(int *, unsigned int) = { is_random, is_increasing, is_decreasing, is_vshape };
void (*sort_functions[])(int *, unsigned int) = { selection_sort, heap_sort, insertion_sort, quick_sort };

char *fill_names[] = { "Random", "Increasing", "Decreasing", "V-Shape" };
char *sort_names[] = { "SelectionSort", "HeapSort", "InsertionSort", "QuickSort" };

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
                is_sorted(t, n);

                printf("%s\t%s\t%u\t%f\n", sort_names[i], fill_names[j], n, (double)(end - begin) / (double) CLOCKS_PER_SEC);
                free(t);
            }
        }
    }
    return 0;
}
