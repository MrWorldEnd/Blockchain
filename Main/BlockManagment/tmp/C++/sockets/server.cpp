#include "Socket.h"
#include <iostream>

int main(int argc, char const *argv[]) {
        using namespace std;
        try {
                // Normally you'd spawn threads for multiple connections.
                Connection conn = PortListener(8080).waitForConnection();
                cout << conn.rx() << endl;
                conn.tx("Hello from server");
                cout << "Hello message sent" << endl;
        } catch (runtime_error &e) {
                cerr << e.what() << endl;
                return EXIT_FAILURE;
        }
        return 0;
}