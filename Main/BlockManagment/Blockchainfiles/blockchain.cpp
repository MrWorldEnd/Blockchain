
#include <stdio.h>
#include <ctime>
#include <string>
#include <vector>
#include "blockchain.h"

using namespace std;

int Blockchain::getsize(){return chain.size();}

bool Blockchain::isvalid()
{
    std::vector<Block>::iterator it;

    for (it = chain.begin(); it != chain.end(); ++it)
    {
        Block currentBlock = *it;
        if (!currentBlock.isValid())
            return false;

        if (chain.size() >= 2)
        {
            Block previouseBlock = *(it - 1);
            if (currentBlock.getPrevHash() != previouseBlock.getHash())
                return false;
        }
    }
    return true;
}

void Blockchain::printChain()
{
    std::vector<Block>::iterator it;

    for (it = chain.begin(); it != chain.end(); ++it)
    {
        Block current = *it;

        std::cout << "\n\nBlock ==================================================\n";
        std::cout << current;
    }
}
//Bad!! only for demo
void Blockchain::addBlock(TxDataset d)
{
    int index = (int)chain.size();
    std::string previousHash = chain[index].getHash();
    Block newBlock(index, d, previousHash);
    chain.push_back(newBlock);
    //add block to json
    addblock2db(newBlock);
};