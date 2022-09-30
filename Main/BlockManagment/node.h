#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque
#include <netdb.h>
#include <arpa/inet.h>  
#include "device.cpp"
#include "gethost.cpp"
#include "Blockchain.cpp"


#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

using namespace std;

#define MAX_ADDRESS_LEN 120

class Node : public Device{    
  private:
    string nodeName;
    IPaddress myaddress;
    Blockchain blockchain;
    TxDataset currentblock;
  public:
    Node(){
      nodeName = "XXXX";
      myaddress = IPaddress();
      blockchain = Blockchain();
    }
    Node(string x){
      nodeName = x;
      myaddress = IPaddress();
      blockchain = Blockchain();
    }
    void Initialize(){
    }

    bool validateTx(Device user,Device item){
        bool result = false;
        
        if (user.getaccesslvl() > item.getaccesslvl())
            result = true;
        return result;
    }
    
    void accessDevice(Device user,IotDevice item)
    {
      Packet newpacket( user, item);
      currentblock.addTX(newpacket);
    }

    void broadcastblock()
    {
      //broadcast object to peers on network
      if(currentblock.isfull())
      {
        //add network functionality for [broadcast(currentblock);]
        blockchain.addBlock(currentblock);
      }
    }
};
