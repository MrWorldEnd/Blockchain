#include <iostream>
#include <ctime>
#include <vector>

#include "Block.h"
#include "Blockchain.h"
#include "TransactionData.h"

using namespace std;

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
