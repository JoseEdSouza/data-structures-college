/**
 * The above code is a testing code for the BinaryTreeDoPae class.
 * the code insert and removes numbers randomly and prints the values of the nodes in the binary tree.
*/

#include <iostream>
#include "BinaryTreeDoPae.h"
#include <random>
#include <time.h>

int main(){
    srand(time(NULL));
    BinaryTreeDoPae<int> teste;
    int randnum = rand()%1000 +1;
    for(int i =0; i< randnum ;++i){
        teste.insert(rand()%100 +1);
        int another_randnum = rand()%100 +1;
        if(teste.remove(another_randnum))
            std::cout<<another_randnum<<" removed!\n";
        else std::cout<<another_randnum<<" not find\n";
    }
    teste.print_values();
}