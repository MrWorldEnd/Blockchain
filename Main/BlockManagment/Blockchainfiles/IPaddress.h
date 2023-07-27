#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class IPaddress
{
    /* data */
    private:
        int addrpt[4];
    public:
        IPaddress();
        IPaddress(int x, int y, int z, int c);
        IPaddress(string x);
        string getString(){
            string x;
            x = to_string(addrpt[0]) +'.' + to_string(addrpt[1]) + '.' + to_string(addrpt[2]) +'.'+ to_string(addrpt[3]);
            return x;
        }
        friend ostream& operator<<(ostream& os, const IPaddress& x){
            os << to_string(x.addrpt[0]) << '.';
            os << to_string(x.addrpt[1]) + '.';
            os << to_string(x.addrpt[2]) + '.';
            os << to_string(x.addrpt[3]);
            return os;
        }
    ~IPaddress();
};
