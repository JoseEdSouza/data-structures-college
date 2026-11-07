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