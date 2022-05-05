#include "Socket.h"
#include "Packet.h"
#include <iostream>

int main(int argc, char const *argv[]) {
        using namespace std;
        try {
                Connection conn("127.0.0.1",8080);
                conn.tx("messasge");
                cout << "Hello message sent" << endl;
                string s = conn.rx();
                cout << s << endl;

        } catch (exception &e) {
                cerr << e.what() << endl;
                return EXIT_FAILURE;
        }
    return 0;
}