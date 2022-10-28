//
// Created by mrworldend on 09/12/2021.
//
//BLockchain constructor
#include <stdio.h>
#include <ctime>
#include <string>

#include "Blockchain.h"
#include "TransactionData.h"
#include <vector>

Blockchain::Blockchain()
{
    Block genesis = creategenesisBlock();
    chain.push_back(genesis);
}

std::vector <Block> Blockchain::getChain() {return chain;}

Block Blockchain::creategenesisBlock()
{
    std::time_t current;
    Packet d;
    Block genesis(0, d, 0);
    return genesis;
}

int Blockchain::getsize(){return chain.size();}

//Bad!! only for demo
void Blockchain::addBlock(Packet d)
{
    int index = (int)chain.size();
    std::size_t previousHash = (int)chain.size() > 0 ? getlatestBlock()->getHash() : 0;
    Block newBlock(index, d, previousHash);
    chain.push_back(newBlock);
}

Block *Blockchain::getlatestBlock(){return &chain.back();}

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

std::string to_string(Block x)
{
    std::string out;
    out = out + "\n\nBlock ==================================================\n";
    out = out + "[\n    { \n" ;
    out = out + "\"Index\": \"" + to_string(x.getIndex()) + "\",\n";
    out = out + "\"Hash\": \"" + to_string(x.getHash()) + "\",\n";
    out = out + "\"PrevHash\": \"" + to_string(x.getPrevHash()) + "\",\n";
    out = out + "\"Transaction Data\": \"" + x.getData().getPayload().getPayloadstr() + "\",\n";
    out = out + "\"SenderKey\": \"" + x.getData().getheader().getsenderKey() + "\",\n";
    out = out + "\"ReceiveKey\": \"" + x.getData().getheader().getreceiverKey() + "\",\n";
    out = out + "\"Timestamp\": \"" + x.getData().getheader().gettimestamp() + "\",\n";
    out = out + "\n    }\n]";
    return out;
}

std::string Blockchain::outChain()
{
    std::vector<Block>::iterator it;
    std::string out;

    for (it = chain.begin(); it != chain.end(); ++it)
    {
        Block current = *it;
        out = out + to_string(current);
    }
}
;
