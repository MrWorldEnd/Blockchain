#include "IPlistmanager.h"

class Request
{
private:
    Device client;
    Device server;
    IotDevice iotdevice;
    bool valid;
public:
    Request()
{
    Device x;
    client = Device();
    server =  Device();
    iotdevice = IotDevice();
    valid = false;
};;
    Request(Device user, Device master, IotDevice device){
    client = user;
    server = master;
    iotdevice = device;
    if (client.getaccesslvl() > iotdevice.getaccesslvl())
    {
        valid = true;
    }else
    {valid = false;}
};

    void setclient(Device x){client = x;}
    void setserver(Device x){server = x;}
    void setiotdevice(IotDevice x){iotdevice = x;}

    ~Request();

friend ostream& operator<<(ostream& os,const Request& x){
            os << "Client: " << x.client 
                << " Server: " << x.server 
                << " Device: " << x.iotdevice
                << " Valid: " << x.valid
                << "\n";
            return os;
        }
};