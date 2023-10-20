#include "initialization.cpp"

Blockchain consensusmechanism(Blockchain x)
{
    if(!x.isvalid())
    {
        Blockchain y;
        return y;
    }else
    {        
        return x;}
}

Blockchain addBlocktochain(Block x)
{
    Blockchain blockchain;
    Block y;
    y = blockchain.getlatestBlock();
    x.setPrevHash(y.getHash());
    x.setIndex(y.getIndex() + 1);
    blockchain.addBlock(x);
    addblock2db(x);
    addblocktoDocument(x,"filename");
    blockchain = consensusmechanism(blockchain);
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