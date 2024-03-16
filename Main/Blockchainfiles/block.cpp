//
// Created by mrworldend on 09/12/2021.
//

//Block Constructor
#include <stdio.h>
#include <string>
#include <ctime>

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/prettywriter.h>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "block.h"

using namespace rapidjson;
using namespace std;

Block::Block()
{
    index = 0;
    previousHash = '0';
    TxDataset x;
    setData(x);
    currentHash = sha256(x.getstr());
}


Block::Block(std::string prevHash)
{
    index = 0;
    previousHash = prevHash;
    TxDataset x;
    setData(x);
    currentHash = sha256(x.getstr());
}

Block::Block(TxDataset d)
{
    index = 0;
    previousHash = '0';
    TxDataset x = d;
    setData(x);
    currentHash = sha256(x.getstr());
}

Block::Block(int inx, TxDataset d, std::string prevHash)
{
    index = inx;
    pdata = d;
    previousHash = prevHash;
    currentHash = sha256(d.getstr());
}


string Block::getHash(){return currentHash;}
string Block::getPrevHash(){return previousHash;}
bool Block::isValid(){return currentHash == getHash();}
int Block::getIndex() {return index;}


Block creategenesisBlock()
{
    std::time_t current;
    TxDataset d;
    Block genesis(0, d, 0);
    return genesis;
}


