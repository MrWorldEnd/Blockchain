#include "Socket.h"
#include "Packet.h"
#include <iostream>
int main(int argc, char const *argv[]) {
        using namespace std;
        try {
                // Normally you'd spawn threads for multiple connections.
                Connection conn = PortListener(8080).waitForConnection();
                conn.tx("message receved");
                cout << "Hello message sent" << endl;

                
                
                Packet input = conn.rx();

                        packetreader();

                        broadcastdta();
                        broadcastdtt();
                        listenfortdta();
                        listenfordtt();
                        listenfortx();//return
                

        } catch (runtime_error &e) {
                cerr << e.what() << endl;
                return EXIT_FAILURE;
        }
        return 0;
}
void packetreader(Packet x)
{
        if (x.getPinfo() == "dta packer")
                {listenfortdta();}
        else if (x == "dtt packet")
                {listenfordtt();}
        else if ("tx packet")
                {listenfortx();}
}
        
void listenfortdta();
void listenfordtt();
void listenfortx();
void broadcastdta(){}
void broadcastdtt(){}
