#include <string>
#include "IPaddress.h"

using namespace std;

IPaddress::IPaddress(){
            this->addrpt[0] = 0;
            this->addrpt[1] = 0;
            this->addrpt[2] = 0;
            this->addrpt[3] = 0;
        }

IPaddress::IPaddress(int x, int y, int z, int c){
            this->addrpt[0] = x;
            this->addrpt[1] = y;
            this->addrpt[2] = z;
            this->addrpt[3] = c;
        }

string IPaddress::getString(){
            string x;
            x = to_string(addrpt[0]) +'.' + to_string(addrpt[1]) + '.' + to_string(addrpt[2]) +'.'+ to_string(addrpt[3]);
            return x;
        }