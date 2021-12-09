//
// Created by mrworldend on 09/12/2021.
//
//BLockchain constructor
#include <stdio.h>
#include <ctime>
#include <string>

#include "Block.h"
#include "Blockchain.h"

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
    TransactionData d(0, "GenesisBlock", "GenesisBlock", time(&current));
    Block genesis(0, d, hash1(0));
    return genesis;
}

int Blockchain::getsize(){return chain.size();}

//Bad!! only for demo
void Blockchain::addBlock(TransactionData d)
{
    int index = (int)chain.size();
    std::size_t previousHash = (int)chain.size() > 0 ? getlatestBlock()->getHash() : 0;
    Block newBlock(index, d, previousHash);
    chain.push_back(newBlock);
}

Block *Blockchain::getlatestBlock(){return &chain.back();}

bool Blockchain::isvalid()
{
    vector<Block>::iterator it;

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
        printf("\n\nBlock ==================================================");
        printf("\nIndex: %d", current.data.getIndex());
        printf("\nAmount: %f", current.data.amount);
        printf("\nSenderKey: %s", current.data.senderKey.c_str());
        printf("\nReceiveKey: ",current.data.receiverKey.c_str());
        printf("\nTimestamp: %ld", current.data.timestamp);
        printf("\nHash: %zu", current.getHash());
        printf("\nPreviouse Hash: %zu", current.getPrevHash());
        printf("Is Block Valid? : %d", current.isValid());
    }
}
;

