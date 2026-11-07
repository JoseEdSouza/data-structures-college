#pragma once
#include <iostream>

class SquareMatrix {
private:
    /*
    tipo = 1: Matriz generica qualquer

    tipo = 2: Matriz identidade: A matriz identidade é formada apenas apenas pelos valores zero e um.
    Os 1's estarão na diagonal principal e os zeros nas demais célula.

    tipo = 3: Matriz triangular superior: É uma matriz quadrada tal que os elementos que estão abaixo da diagonal principal
    são todos nulos.

    tipo = 4: Matriz triangular inferior: É uma matriz quadrada tal que os elementos que estão acima da diagonal principal
    são todos nulos.
    */
    int type;
    size_t order;//Ordem da matriz quadrada

    /*
    A matriz quadrada será implementada como um vetor.
    */
    double* matrix;
public:
    SquareMatrix(size_t ordem);
    /*
    Construtor para a matriz quadrada para tipos específicos
    tipo = 1: Matriz generica qualquer
    tipo = 2: Matriz identidade
    tipo = 3: Matriz triangular superior
    tipo = 4: Matriz triangular inferior
    */
    SquareMatrix(size_t ordem, int tipo);
    size_t getOrder();
    ~SquareMatrix();
    /*
    Retorna o tipo da matriz
    */
    int getType();
    /*
    Retorna o valor da célula de indice linha i e coluna j.
    Esse método deve sempre ser usado quando for acessar um valor de uma célula da matriz.
    */
    double get(size_t i, size_t j);
    /*
    Setar o valor na indice linha i e coluna j
    */
    void set(size_t i, size_t j, double value);

    /*
    Realiza a operação de soma de duas matrizes quadradas de mesma ordem.
    Gera e retorna uma nova matriz com o resultado da soma das matrizes.
    */
    SquareMatrix sum(SquareMatrix& other);

    /*
    Realiza a operação de multiplicacao de duas matrizes quadradas de mesma ordem.
    Gera e retorna uma nova matriz com o resultado da multiplicacao das matrizes.
    */
    SquareMatrix multiplication(SquareMatrix& other);

    /*
    Aplica a operação de multiplicacao por um escalar na matriz do objeto.
    A operação por um escala multiplicada cada elemento da matriz pelo número.
    */
    void escalarMultiplication(double alpha);
};









