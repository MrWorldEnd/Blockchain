#include "key.h"
#include "device.cpp"

class Request
{
private:
    Key client;
    Device server;
    IotDevice iotdevice;
    bool valid;
public:
    Request()
{
    Device x;
    client = Key();
    server =  Device();
    iotdevice = IotDevice();
    valid = false;
};;
    Request(Key user, Device master, IotDevice device){
    client = user;
    server = master;
    iotdevice = device;
    if (client.getaccesslvl() > iotdevice.getaccesslvl())
    {
        valid = true;
    }else
    {valid = false;}
};

    void setclient(Key x){client = x;}
    void setserver(Device x){server = x;}
    void setiotdevice(IotDevice x){iotdevice = x;}

    Key getclient(){return client;}
    Device getserver(){return server;}
    IotDevice getdevice(){return iotdevice;}


friend ostream& operator<<(ostream& os,const Request& x){
            os << "Client: " << x.client 
                << " Server: " << x.server 
                << " Device: " << x.iotdevice
                << " Valid: " << x.valid
                << "\n";
            return os;
}

~Request();
};