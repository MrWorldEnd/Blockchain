#include "datalayer.cpp"

bool is_file_exist(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

Blockchain initializeNode() {
    std::cout << "initializeNode Started\n";
    Blockchain x;
    createTable();
    createfile("blockchain.json");
    createfile("buffer.json");
    return x;
}

//adding Master node system involves creating a database when node is ctreated
//initialize;createNodeDB
Blockchain initializeMasterNode() {
    Blockchain x;
    x = initializeNode();
    createTable();
    return x;
}
