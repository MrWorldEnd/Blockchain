#include "datalayer.cpp"

std::string filename =  ("blockchain.json");
std::string requestbuffer =("buffer.json");

Blockchain initializeNode() {
    Blockchain x;
    createTable();
    ofstream MyFile(filename);
    ofstream MyBuffer(requestbuffer);
    x.isvalid();
    x.printChain();
    MyFile.close();
    MyBuffer.close();
    return x;
}

Blockchain test(){
    Blockchain x;
    Block tx;
    x.addBlock(tx);
    addblocktofile(tx,filename);
    addblock2db(tx);
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
