#include <chrono>
#include <ctime>  
#include "device.cpp"
#include "Blockchain.cpp"
#include "request.h" 


using namespace std;

#define MAX_ADDRESS_LEN 120

class Node : public Device{    
  private:
    string nodeName;
    IPaddress myaddress;
    Blockchain blockchain;
    Packet currentblock;
    string devicekey;
  public:
    Node(){
      nodeName = "XXXX";
      myaddress = IPaddress();
      blockchain = Blockchain();
      devicekey = "";
    }
    Node(string x){
      nodeName = x;
      myaddress = IPaddress();
      blockchain = Blockchain();
      devicekey = "";
    }
    void Initialize(){
    }

    bool validateTx(Device user,Device item){
        bool result = false;
        
        if (user.getaccesslvl() > item.getaccesslvl())
            result = true;
        return result;
    }
    
    void accessDevice(Device user, IotDevice item)
    {
      Packet newpacket;
      time_t time = chrono::system_clock::now();

      PacketPayload newpayload;
      newpayload.setSubject(user);
      newpayload.setObject(item);

      TxHeader newheader;
      newheader.setsenderKey(devicekey);
      newheader.settimestamp();
      newheader.setTxAddr(myaddress.getString());


      newpacket.setpayload(newpayload);
      newpacket.setpPinfo("");
      newpacket.setpHeader(newheader);
    }
};
