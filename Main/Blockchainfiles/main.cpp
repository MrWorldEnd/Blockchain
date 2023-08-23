#include "datalayer.cpp"

std::string filename = CCFileUtils::sharedFileUtils()->fullPathForFilename("blockchain.json");
std::string requestbuffer = CCFileUtils::sharedFileUtils()->fullPathForFilename("buffer.json");

Document blockchainstate;
Document bufferState;
bool is_file_exist(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

Blockchain initializeNode() {
    std::cout << "initializeNode Started\n";
    Blockchain x;
    createTable();
    createfile(filename);
    createfile(requestbuffer);
    return x;
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
