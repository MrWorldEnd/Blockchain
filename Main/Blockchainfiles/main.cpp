#include "blockchain.cpp"

std::string filename =  ("blockchain.json");
std::string requestbuffer =("buffer.json");
Blockchain x;

void initializeNode() {
    ofstream MyFile(filename);
    ofstream MyBuffer(requestbuffer);
    x.isvalid();
    x.printChain();
    MyFile.close();
    MyBuffer.close();
}

void test(){
    Packet tx;
    x.addBlock(tx);
    x.addBlock(tx);
    x.addBlock(tx);
    x.addBlock(tx);
    x.addBlock(tx);
}



int main() {
    initializeNode();
    test();
    x.outChain();
    //listen()
    //check buffer
}