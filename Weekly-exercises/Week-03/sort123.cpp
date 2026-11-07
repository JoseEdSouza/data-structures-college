#include <iostream>

void sort_123(int* array, size_t size);

int main() {
    int n = 0;
    std::cin >> n;
    int* array = { new int[n] };
    for (int i = 0;i < n;++i) {
        std::cin >> array[i];
    }
    sort_123(array, n);
    for (int i = 0;i < n;++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
    delete array;
}

void sort_123(int* array, size_t size) {
    int elements[] = { 0,0,0 };

    for (int i = 0;i < size;++i) {
        if (array[i] == 1)
            ++elements[0];
        else if (array[i] == 2)
            ++elements[1];
        else
            ++elements[2];
    }

    size_t pos = 0;
    for (int i = 0;i < 3;++i) {
        for (int j = 0;j < elements[i];++j) {
            array[pos] = i + 1;
            ++pos;
        }
    }
}