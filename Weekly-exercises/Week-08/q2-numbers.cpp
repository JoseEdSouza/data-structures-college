#include <iostream>
#include "Queue.cpp"
#include "Stack.cpp"

void positives_negatives(int* numbers, int n);

int main() {
    int n = 0;
    std::cin >> n;
    int* numbers = new int[n];
    for (int i = 0;i < n;++i) {
        std::cin>>numbers[i];
    }
    positives_negatives(numbers,n);
    delete[] numbers;
}

void positives_negatives(int* numbers, int n) {
    Queue<int> negatives;
    Stack<int> positives;
    for (int i = 0;i < n;++i) {
        if (numbers[i] < 0) negatives.push(numbers[i]);
        else positives.push(numbers[i]);
    }
    while (!negatives.empty()) {
        std::cout << negatives.pop() << " ";
    }
    while (!positives.empty()) {
        std::cout << positives.pop() << " ";
    }
    std::cout << "\n";
}