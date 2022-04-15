#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

//transaction data
struct TransactionData
{
  double amount;
  string senderKey;
  string receiverKey;
  time_t timestamp;
};

class Block
{
private:
  int index;
  size_t currentHash;
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
  return lastHash(hash1(toHash) + hash2(previousHash));
}

size_t Block::getHash(){return currentHash;}
size_t Block::getPrevHash(){return previousHash;}
bool Block::isValid(){return generateHash() == currentHash;}

//Blockchain
class Blockchain
{
private:
  Block creategenesisBlock();
public:
  vector<Block> chain;
  Blockchain();
  void addBlock(TransactionData dt);
  bool isvalid();
  Block *getlatestBlock();
  void getsize();
};

//BLockchain constructor
Blockchain::Blockchain()
{
  Block genesis = creategenesisBlock();
  chain.push_back(genesis);
}

Block Blockchain::creategenesisBlock()
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

void Blockchain::getsize(){cout << chain.size();}

//Bad!! only for demo
void Blockchain::addBlock(TransactionData d)
{
  int index = (int)chain.size() - 1;
  size_t previousHash = (int)chain.size() > 0? getlatestBlock()->getHash() : 0;
  Block newBlock(index, d, previousHash);
  chain.push_back(newBlock);
}

Block *Blockchain::getlatestBlock(){return &chain.back();}

bool Blockchain::isvalid()
{
  vector<Block>::iterator it;
  int chainLen = (int)chain.size();
  bool check;

  for (it = chain.begin(); it != chain.end(); ++it)
    {
      Block currentBlock = *it;
      if (!currentBlock.isValid()) return false;

      if (chain.size() >= 2)
	{
	  Block previouseBlock = *(it - 1);
	  if (currentBlock.getPrevHash() != previouseBlock.getHash())return false;
	}
    }
  return true;
};

void chainsizeis (Blockchain x){x.getsize();}

int main()
{
  //startblockchain
  Blockchain Rushcoin;

  //data of first added block
  TransactionData data1, data2, data3;
  time_t dataTime1;
  data1.amount = 1.5;
  data1.receiverKey = "King Rush the 4rth";
  data1.senderKey = "Some moocher";
  data1.timestamp = time(&dataTime1);


    time_t dataTime2;

    data2.amount = 1.5;
    data2.receiverKey = "King Rush the 4rth";
    data2.senderKey = "Some moocher";
    data2.timestamp = time(&dataTime2);

    time_t dataTime3;

    data3.amount = 1.5;
    data3.receiverKey = "King Rush the 4rth";
    data3.senderKey = "Some moocher";
    data3.timestamp = time(&dataTime3);


    Rushcoin.addBlock(data1);
    Rushcoin.addBlock(data2);
    Rushcoin.addBlock(data3);

  cout << "Is chain valid test?" << endl;

  if (Rushcoin.isvalid())
  {
      cout << "\n chain is valid \n";
  }
  else
      cout <<"\n chain is invalid \n";

  cout << "The size is: ";
  chainsizeis(Rushcoin);
  cout << "Done";
}
