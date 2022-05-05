#include "Socket.h"
#include <iostream>

int main(int argc, char const *argv[]) {
        using namespace std;
        try {
                Connection conn("127.0.0.1",8080);
                conn.tx("message");
                cout << "Hello message sent" << endl;
                string s = conn.rx();
                cout << s << endl;

                
                while (true)
                {
                        broadcastdta();
                        broadcastdtt();
                        listenfortdta();
                        listenfordtt();
                        listenfortx();//return
                }

        } catch (exception &e) {
                cerr << e.what() << endl;
                return EXIT_FAILURE;
        }
    return 0;
}
x = packet.info(listener());

void packetreader()
{
        if (x == "dta packer")
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