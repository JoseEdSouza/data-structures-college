/**
 * main.cpp
 *
 * This file contains the main `main` function that is responsible for interacting with the user and performing
 * disease diagnosis based on the decision tree. The program prompts the user to answer a series of questions about
 * symptoms and then provides a diagnosis based on the provided answers.
 *
 * The program uses the `DecisionTreeDoPae` class to interact with the decision tree, ask questions to the user,
 * and obtain the final diagnosis.
 *
 * Author: José Vinícius Evangelista Dias de Souza
 */

#include "diseaseDecisionTree.h"
#include <iostream>
#include "decisionTreeDoPae.h"
#define nl '\n'
#define str std::string

int main() {
    bool again = true;
    while (again) {
        std::cout << "\n>>===System===<<\nDeseja começar(y/n): ";
        str res;
        std::cin >> res;
        if (res == "y")
            diseasePrognosisTree.ask();
        else if (res == "n") {
            std::cout << "bye bye!"<<nl;
            again = false;
        }
        else
            std::cout << "invalid Comand, try again."<<nl;
    }
}

#undef nl
#undef str