#include "initialization.cpp"
extern Blockchain blockchain;


std::string filename = CCFileUtils::sharedFileUtils()->fullPathForFilename("blockchain.json");
std::string requestbuffer = CCFileUtils::sharedFileUtils()->fullPathForFilename("buffer.json");

Document blockchainstate;
Document bufferState;


void addBlocktochain(Block x)
{
    blockchain.addBlock(x);
    addblock2db(x);
    addblocktoDocument(x);
}
Blockchain test(){
    std:cout << "test program start \n";
    Blockchain x;
    Block block;
    Document jsondata;

    std::cout << "Add to chain \n";
    x.addBlock(block);

    std::cout << "Add to JSON \n";
    jsondata = addblocktoDocument(block,filename);

    std::cout << "Add to DB \n";
    addblock2db(block);

    std::cout << "test program copmlete \n";
    return x;
}



int main() {
    Blockchain x;
    x = initializeNode();
    x = test();
    x.printChain();
    //listen()
    //check buffer
}
