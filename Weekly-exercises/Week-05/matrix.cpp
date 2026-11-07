#include <iostream>
#include "matrix.h"
#include <string.h>

SquareMatrix::SquareMatrix(size_t order) {
    matrix = new double[(order * order)];
    memset(matrix, 0, sizeof(matrix));
    this->order = order;
    this->type = 1;
}

SquareMatrix::~SquareMatrix() = default;

SquareMatrix::SquareMatrix(size_t order, int type) {
    if (type > 4 || type < 1) throw std::invalid_argument("invalid_type");
    matrix = new double[(order * order)];
    this->order = order;
    memset(matrix, 0, sizeof(matrix));
    this->type = type;
    if (type == 2) {
        for (int i = 0;i < order;++i) {
            for (int j = 0;j < order;++j) {
                if (i == j) {
                    matrix[(i * order) + j] = 1;
                    break;
                }
            }
        }
    }
    else if (type == 3) {
        for (int i = 0;i < order;++i) {
            for (int j = 0;j < order;++j) {
                if (i <= j) {
                    matrix[(i * order) + j] = 1;
                }
            }
        }
    }
    else if (type == 4) {
        for (int i = 0;i < order;++i) {
            for (int j = 0;j < order;++j) {
                if (i >= j) {
                    matrix[(i * order) + j] = 1;
                }
            }
        }
    }

}

double SquareMatrix::get(size_t i, size_t j) {
    if (i > order || i<1 || j>order || j < 1) throw std::out_of_range("index_out_of_range");
    return matrix[((i - 1) * order) + (j - 1)];
}

size_t SquareMatrix::getOrder() {
    return this->order;
}

int SquareMatrix::getType() {
    return this->type;
}

void SquareMatrix::set(size_t i, size_t j, double value) {
    if (i > order || i<1 || j>order || j < 1) throw std::out_of_range("index_out_of_range");
    if(type == 1) matrix[((i - 1) * order) + (j - 1)] = value;
    else if(type == 2) return;
    else if(type == 3 && i<=j) matrix[((i - 1) * order) + (j - 1)] = value;
    else if(type ==4 && i>=j) matrix[((i - 1) * order) + (j - 1)] = value;
}

SquareMatrix SquareMatrix::sum(SquareMatrix& other) {
    if (order != other.getOrder()) throw std::invalid_argument("both_should_have_same_order");
    SquareMatrix result = SquareMatrix(order);
    for (int i = 1;i <= order;++i) {
        for (int j = 1;j <= order;++j) {
            result.set(i, j, (this->get(i, j) + other.get(i, j)));
        }
    }
    return result;
}

SquareMatrix SquareMatrix::multiplication(SquareMatrix& other) {
    if (order != other.getOrder()) throw std::invalid_argument("both_should_have_same_order");
    SquareMatrix result = SquareMatrix(order);
    for (int i = 1;i <= order;++i) {
        for (int j = 1;j <= order;++j) {
            double element_result = 0;
            for (int w = 1;w <= order;++w) {
                element_result += this->get(i, w) * other.get(w, j);
            }
            result.set(i, j, element_result);
        }
    }
    return result;
}

void SquareMatrix::escalarMultiplication(double alpha) {
    for (int i = 1;i <= order;++i) {
        for (int j = 1;j <= order;++j) {
            this->set(i, j, (this->get(i, j) * alpha));
        }
    }
}