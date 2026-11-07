#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int* array, size_t beg, size_t end);

int main() {
    int n = 0;
    scanf("%d", &n);
    int* array = (int*)malloc(n * sizeof(int));
    for (int i = 0;i < n;++i) {
        scanf("%d", &array[i]);
    }
    insertion_sort(array, 0, n - 1);
    for (int i = 0;i < n;++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
    free(array);
}

void insertion_sort(int* array, size_t beg, size_t end) {
    if (beg >= end)
        return;
    insertion_sort(array, beg, end - 1);

    int key_element = array[end];
    int index_to_compare = end - 1;

    while (index_to_compare >= beg && array[index_to_compare] > key_element) {
        array[index_to_compare + 1] = array[index_to_compare];
        --index_to_compare;
    }
    array[index_to_compare + 1] = key_element;
}