#include <iostream>
#include <cstring>
#include <ctime>

#include 'Payload.h'
#include 'header.h'
 
using namespace std;
//transaction packet

struct TxPacket {
   private:
      Header header;
      Payload payload;
      time_t timestamp;

   public:
      Header getHeader() const { return header; }
      Payload getPayload() const { return payload; }
      time_t getTimestamp() const { return timestamp; }

      void setHeader(const Header &x) { header = x; }
      void setPayload(const Payload &x) { payload = x; }
      void setTimestamp(const time_t &x) { timestamp = time(NULL); }

      friend std::ostream& operator<<(std::ostream &out, TxPacket d);
};

ostream& operator<<(ostream &out, TxPacket d)
{
    out << d.getHeader 
        << "\n"  << d.getPayload 
        << "\n"  << d.getTimestamp;
        << "\n";
    return out;
}