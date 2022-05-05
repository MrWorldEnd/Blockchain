#include <iostream>
#include <ctime>
#include <vector>

#include <iostream>
#include <fstream>

#include "Socket.h"
#include "json.hpp"

#include "Block.h"
#include "Blockchain.h"
#include "TransactionData.h"
#include "Objects.h"
#include "PacketPayload.h"

using namespace std;

PacketPayload genPacketPayload(devides user,devides item){
    PacketPayload x = PacketPayload(user,item);
    return x;
}

bool validateTx(devides user,devides item){
    bool result = false;
    if (user.getaccesslvl() > item.getaccesslvl())
        result = true;
    return result;
}
vector<Packet>buffer;


int main(){}

void SendPacket(Packet x)
{
try {
  Connection conn("127.0.0.1",8080);
  conn.tx("message ");
  string s = conn.rx();
  cout << s << endl;

  Packet inputpacket;

  } catch (exception &e) {
    cerr << e.what() << endl;
    EXIT_FAILURE;
  }
}

x = packet.info(listener());

void packetreader(Packet x)
{
  if (x.getPinfo() == "blockchaindata")
    {
      listenforblockdata(packet);
      validate(buffer);
      ifblock(buffer);
      updatebuffer();
    }
  else if (x.getPinfo() == "tx packet")
    {
      listenfortx();
      validate(tx);
      actuate(tx);
    }
}
        
void listenfortxdata(){
        addtobuffer(tx);
};

void listenforblockdata(buffer.size()){
        addtobuffer(packet);


};}


}}}