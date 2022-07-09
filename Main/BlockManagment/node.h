#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque
#include "device.cpp"
#include "gethost.cpp"

using namespace std;

class Node {    
  private:
    string nodeName;
    IPaddress myaddress;
    std::stack <Device> alldevices;
    std::stack <IPaddress> allIPAddrs;
    std::stack <IPaddress> trustedIPAddrs;
  public:
    void adddevice(Device x){alldevices.push(x);}
    void addallip(IPaddress x){allIPAddrs.push(x);}
    void addtrustedip(IPaddress x){trustedIPAddrs.push(x);}

    Node(){
      nodeName = "XXXX";
      
    }
};
