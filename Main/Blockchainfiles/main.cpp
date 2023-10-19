#include "initialization.cpp"

Blockchain addBlocktochain(Block x)
{
    Blockchain blockchain;
    blockchain.addBlock(x);
    addblock2db(x);
    addblocktoDocument(x,"filename");
    return blockchain;
}

Blockchain test(Blockchain x){
    std:cout << "test program start \n";
    
    Block block;

    x = addBlocktochain(block);
    std::cout << "test program copmlete \n";
    return x;
}

int main() {
    Blockchain x;
    x = initializeNode();
    x = test(x);
    x.printChain();
    //listen()
    //check buffer
}