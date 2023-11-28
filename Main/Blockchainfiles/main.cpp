#include "node.cpp"

int main() {
    Blockchain x;
    x = initializeNode();
    x = test(x);
    x.printChain();
    //listen()
    //check buffer
}