#include <iostream>
#include "matrix.h"
#include <random>
#include <time.h>

std::string matrixToString(SquareMatrix matrix);


int main() {
    srand(time(NULL));
    int order = 100;
    SquareMatrix matrix = SquareMatrix(order, 2);
    for (int i = 1;i <= order;++i) {
        for (int j = 1;j <= order;++j) {
            matrix.set(i, j, ((int)(rand() % (order*order)) + 1));
        }

    }
    std::cout << matrixToString(matrix) << "\n";
}

std::string matrixToString(SquareMatrix matrix) {
    std::string retorno = "";
    for (int i = 1;i <= matrix.getOrder();++i) {
        retorno += "| ";
        for (int j = 1;j <= matrix.getOrder();++j) {
            retorno += (std::to_string((int)matrix.get(i, j)) + " ");
        }
        retorno += "|\n";
    }
    return retorno;
}