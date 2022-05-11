#include <json.hpp>
#include <fstream>

using namespace std;

ifstream blockchain_file("blockchain.json", ifstream::binary);
blockchain_file >> blockchain;