#include <iostream>

int partition(int* array, int beg, int end);
void quicksort(int* array, int beg, int end);

int main() {
    int n = 0;
    std::cin >> n;
    int* array = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    quicksort(array, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
    delete[] array;
}

int partition(int* array, int beg, int end) {
    int pivot = array[end];
    int i = beg - 1;
    for (int j = beg; j < end; ++j) {
        if (array[j] <= pivot) {
            i++;
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[i + 1], array[end]);
    return i + 1;
}

void quicksort(int* array, int beg, int end) {
    if (beg < end) {
        int pivotIndex = partition(array, beg, end);
        quicksort(array, beg, pivotIndex - 1);
        quicksort(array, pivotIndex + 1, end);
    }
}