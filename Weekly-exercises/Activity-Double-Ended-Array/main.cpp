#include <iostream>
#include "ArrayDoPaeDuplo.cpp"
#include <locale>
int main() {
    ArrayDoPaeDuplo<char> levi;
    ArrayDoPaeDuplo<int> gilmar = { 1,2,3 };
    for (int i = 1;i < 10000;++i) {
        levi.push_back('A');
    }
    levi.removeAll(10);
    levi.print();
    levi.printAll();
}
