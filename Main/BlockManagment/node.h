#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque
#include <netdb.h>
#include <arpa/inet.h>  
#include "device.cpp"
#include "gethost.cpp"
#include "Blockchain.cpp"

using namespace std;

class Node {    
  private:
    string nodeName;
    IPaddress myaddress;
    Blockchain blockchain;
  public:
    Node(){
      nodeName = "XXXX";
      myaddress = IPaddress();
      blockchain = Blockchain();
    }
    Node(string x){
      nodeName = x;
      myaddress = IPaddress();
      blockchain = Blockchain();
    }
    void Initialize(){
    }
};
