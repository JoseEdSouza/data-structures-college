#include <iostream>
#include <stdlib.h>
#include <random>
#include <time.h>


int roof_array(int* array, size_t beg, size_t end, int roof);

int main() {
    srand(time(NULL));
    int n, roof, random = 0;
    n = rand() % 100 + 10;
    roof = rand() % 500 + 1;
    int* array = { new int[n] };
    for (int i = 0;i < n;++i) {
        random = (rand() % 10 + random);
        array[i] = random;
    }
    std::cout << "n = " << n << "\n";
    std::cout << "roof = " << roof << "\n[ ";
    for (int i = 0;i < n;++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "]\n";
    std::cout << roof_array(array, 0, n - 1, roof) << "\n";
}

int roof_array(int* array, size_t beg, size_t end, int roof) {
    if (array[end] < roof) return -1;
    if (array[end] == roof) return array[end];
    if (array[beg] >= roof) return array[beg];
    if ((end - beg + 1) == 2) {
        if (array[beg] >= roof)
            return array[beg];
        else
            return array[end];
    }
    int mid = (((end - beg) / 2) + beg);
    if (array[mid] == roof)
        return array[mid];
    else if (array[mid] > roof)
        return roof_array(array, beg, mid, roof);
    else
        return roof_array(array, mid, end, roof);
}