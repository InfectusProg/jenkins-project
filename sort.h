#ifndef SORT
#define SORT
#include "stringProcessor.h"
#include <string.h>

static inline void swap(char** a, char** b)
{
    char* temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(char** arr, size_t length)
{
    if (length <= 1)
    {
        return;
    }
    size_t piv = 0;
    char* pivot = arr[length - 1];
    for (size_t i = 0; i < length - 1; i++)
    {
        if (strcmp(arr[i], pivot) < 0)
        {
            swap(&arr[i], &arr[piv++]);
        }
    }
    swap(&arr[piv], &arr[length - 1]);
    quick_sort(arr, piv);
    quick_sort(arr + piv + 1, length - piv - 1);
}

#endif // !SORT
