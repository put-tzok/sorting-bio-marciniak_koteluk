#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int ns[] = { 10, /* TODO: fill in "n" i.e. instance sizes */ };

void fill_increasing(int *t, unsigned int n) {
    // TODO: implement
}

void fill_decreasing(int *t, unsigned int n) {
    // TODO: implement
}

void fill_vshape(int *t, unsigned int n) {
    // TODO: implement
}

void selection_sort(int *t, unsigned int n) {
    // TODO: implement
}

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

void swap (int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
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

void heap_sort(int *t, unsigned int n) {
    // TODO
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
void (*sort_functions[])(int *, unsigned int) = { selection_sort, insertion_sort, quick_sort, heap_sort };

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
                is_sorted(t, n);

                printf("%s\t%s\t%u\t%f\n", sort_names[i], fill_names[j], n, (double)(end - begin) / (double) CLOCKS_PER_SEC);
                free(t);
            }
        }
    }
    return 0;
}
