#include <iostream>
#include <cstring>

using namespace std;

class Transaction {
    private:
        string Header;
        string Payload;
    public:
        void forward();
        void validate();
        void record();
}