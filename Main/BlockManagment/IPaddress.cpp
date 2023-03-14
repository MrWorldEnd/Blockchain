#include "IPaddress.h"

using namespace std;

IPaddress::IPaddress(){
            this->addrpt[0] = 0;
            this->addrpt[1] = 0;
            this->addrpt[2] = 0;
            this->addrpt[3] = 0;
        }

IPaddress::IPaddress(string x){
    const char separator = '.';
    vector<string> outputArray;
    stringstream streamData(x);
    string val;
    int i = 0;
    while (getline(streamData, val, separator)) {
        outputArray.push_back(val);
        addrpt[i] =  stoi(val);
        i++;
    }

}

IPaddress::IPaddress(int x, int y, int z, int c){
            this->addrpt[0] = x;
            this->addrpt[1] = y;
            this->addrpt[2] = z;
            this->addrpt[3] = c;
        }
