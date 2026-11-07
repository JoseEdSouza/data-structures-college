#include <iostream>
#include <algorithm>
#include "Queue.cpp"


Queue<std::string> split(std::string str, char del);

int main() {
    std::string frase;
    std::getline(std::cin, frase);
    Queue<std::string> str_queue = split(frase, ' ');

    while (!str_queue.empty()) {
        std::cout << str_queue.pop();
        if (!str_queue.empty()) std::cout << " ";
    }
    std::cout << "\n";
}

Queue<std::string> split(std::string str, char del) {
    Queue<std::string> str_queue = Queue<std::string>();
    std::string iStr;
    for (char c : str) {
        if (c != del)
            iStr.push_back(c);
        else {
            if (!iStr.empty()) {
                std::reverse(iStr.begin(), iStr.end());
                str_queue.push(iStr);
            }
            iStr = "";
        }
    }
    if (!iStr.empty()) {
        std::reverse(iStr.begin(), iStr.end());
        str_queue.push(iStr);
    }
    return str_queue;
}