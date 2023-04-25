#ifndef SORT_H
#define SORT_H

void print_array(const int *array, size_t size);
void swap(int *a, int *b);
void heapify(int *arr, size_t N, int i, size_t S);
void heap_sort(int *array, size_t size);
#endif
