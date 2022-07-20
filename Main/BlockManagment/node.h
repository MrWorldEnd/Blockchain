#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque
#include <netdb.h>
#include <arpa/inet.h>  
#include "device.cpp"
#include "gethost.cpp"
#include "Blockchain.cpp"


#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

using namespace std;

#define MAX_ADDRESS_LEN 120

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

    bool validateTx(Device user,Device item){
        bool result = false;
        
        if (user.getaccesslvl() > item.getaccesslvl())
            result = true;
        return result;
    }
    void sniffnetwork(){
      FILE *pin = popen("nmap -p 123 10.0.1.0/24","r");
      char *line[MAX_ADDRESS_LEN];
      string filedata;
      if ( pin ) {
        while (!feof(pin)) {
          getline((pin), line);
        }
      pclose(pin);
    };
      sstringstream input(fileno(pin));
      for (string line; getline(input, line, '\n');){
        
      }
    }

void runterminalcmd(){
  typedef boost::iostreams::stream<boost::iostreams::file_descriptor_sink>
        boost_stream; 

FILE *myfile; 
// make sure to popen and it succeeds
boost_stream stream(fileno(myfile));
stream.set_auto_close(false); // https://svn.boost.org/trac/boost/ticket/3517
std::string mystring;
while(getline(stream,mystring));
}

std::string exec(const char* cmd) {
    char buffer[128];
    std::string result = "";
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer, 128, pipe.get()) != NULL)
            result += buffer;
    }
    return result;
}

};
