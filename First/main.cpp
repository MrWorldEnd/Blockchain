#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

//transaction data
struct TransactionData
{
  double amount;
  string senderKey;
  string receiver;
  time_t timestamp;
};

class Block
{
private:
  size_t currenthash;
  size_t previousHash;
  size_t generateHash();
public:
  //constructor
  Block (int idx,TransactionData data, size_t prevHash);
  size_t getHash();
  size_t getPrevHash();
  TransactionData data;
  bool isValid();
};
//Block Constructor
Block::Block(int inx, TransactionData d, size_t prevHash)
{
  index = inx;
  data = d;
  previousHash = prevHash;
  currentHash = generateHash();
}

size_t Block::generateHash()
{
  hash<string> hash1;
  hash<size_t> hash2;
  hash<size_t> lastHash;
  string toHash = to_string(data.amount) + data.receiverKey + data.senderKey + to_string(data.timestamp);
  return lastHash(hash1(to_Hash) + hash2(previouseHash));
}

size_t Block::getHash(){return currentHash;}
size_t Block::getPrevHash(){return previousHash;}
bool Block::isHashValid(){return generateHash == currentHash;}

//Blockchain
class Blockchain
{
private:
  Block creategenesisBlock();
public:
  vector<Block> chain;
  Blockchain();
  void addBlock(TransactionData dt);
  bool ischainvalid();

  Block *getlatestBlock();
};

//BLockchain constructor
Blockchain::Blockchain()
{
  Block genesis = createGenesisBlock();
  chain.push_back(genesis);
}

Block Blockchain::createGenesisBlock()
{
  time_t current;
  TransactionData d;
  d.amount = 0;
  d.receiverKey = "None";
  d.senderKey + "None";
  d.timestamp = time(&current);

  hash<int> hash1;
  Block genesis(0, d, hash1(0));
  return genesis;
}

//Bad!! only for demo
Block *Blockchain::addBlock(TransactionData d)
{
  int index = (int)chain.size() - 1;
  Block newBlock(index, d, getlatestBlock()->getHash());
}

bool Blockchain::isvalid()
{
  vector<Block>::iterator it;
  int chainLen = (int)chain.size();

  for (it = chain.begin(); it != chain.end(); ++it)
    {
      Block currentBlock = *it;
      if (!currentBlock.isValid()) return false;

      if (chain > 2)
	{
	  Block previouseBLock = *(it - 1);
	  if (currentBlock.getPreviouseHash() != previouseBlock.getHash())return false;
	}
    }
}

int main()
{
  //startblockchain
  Blockchain Rushcoin;

  //data of first added block
  TransactionData data;
  time_t dataTime;
  data.amount = 1.5;
  data.receiverKey = "King Rush the 4rth";
  data.senderKey = "Some moocher";
  data.timestamp = time(&dataTime)

    Rushcoin.addBlock(data1);

  cout << "Is chain valid?" << endl
       << Rushcoin.isvalid() << endl;
  
}
