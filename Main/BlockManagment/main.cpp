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
      broadcastpackt(tx);
    }
}
int transactionport = 8080;
int dttport = 8081;
int dta = 8082;
        
void listenfortxdata(){
  try {
      // Normally you'd spawn threads for multiple connections.
         Connection conn = PortListener(transactionport).waitForConnection();
         conn.tx("Transaction message receved");
         cout << "Hello message sent" << endl;

         Packet input = conn.rx();

        } catch (runtime_error &e) {
                cerr << e.what() << endl;
                return EXIT_FAILURE;
        }
};

void listenforDTT(){
  try {
    // Normally you'd spawn threads for multiple connections.
    Connection conn = PortListener(8081).waitForConnection();
    conn.tx("DTT message receved");
    cout << "Hello message sent" << endl;

    Packet input = conn.rx();

    } catch (runtime_error &e) {
    cerr << e.what() << endl;
    return EXIT_FAILURE;
  }
}

void listenforDTA(){
  try {
    // Normally you'd spawn threads for multiple connections.
    Connection conn = PortListener(8082).waitForConnection();
    conn.tx("DTA message receved");
    cout << "Hello message sent" << endl;

    Packet input = conn.rx();

    } catch (runtime_error &e) {
    cerr << e.what() << endl;
    return EXIT_FAILURE;
  }
}

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

      input buffer;
      thread1:
        broadcastNodeinfo();
        listenfornodeinfo();
      thread2:
        listenfortxpacket();
        listenforblockchaindata();

};