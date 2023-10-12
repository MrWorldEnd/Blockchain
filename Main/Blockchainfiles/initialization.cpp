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
    createfile(filename);
    createfile(requestbuffer);
    return x;
}

//adding Master node system involves creating a database when node is ctreated
//initialize;createNodeDB
Blockchain initializeMasterNode() {
    Blockchain x;
    x = initializeNode();
    createTable();

}
