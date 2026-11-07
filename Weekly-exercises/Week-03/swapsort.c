#include <stdio.h>
#include <stdlib.h>

void swap_sort(int* array, size_t size);

int main() {
    int n = 0;
    scanf("%d", &n);
    int* array = (int*)malloc(n * sizeof(int));
    for (int i = 0;i < n;++i) {
        scanf("%d", &array[i]);
    }
    swap_sort(array, n);
    for (int i = 0;i < n;++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
    free(array);
}

void swap_sort(int* array, size_t size) {
    for (int i = 0;i < size - 1;++i) {
        for (int j = 0;j < size - i - 1;++j) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}