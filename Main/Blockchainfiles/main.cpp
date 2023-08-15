#include "datalayer.cpp"

std::string filename =  ("blockchain.json");
std::string requestbuffer =("buffer.json");

Blockchain initializeNode() {
    std::cout << "initializeNode Started\n";
    Blockchain x;
    createTable();
    ofstream myFile(filename);
    ofstream myBuffer(requestbuffer);
    x.isvalid();
    x.printChain();
    myFile.close();
    myBuffer.close();
    std::cout << "initializeNode completed\n";
    return x;
}

Blockchain test(){
    std:cout << "test program start \n";
    Blockchain x;
    Block block;

    std::cout << "Add to chain \n";
    x.addBlock(block);
    std::cout << "Add to JSON \n";
    addblocktofile(block,filename);
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
