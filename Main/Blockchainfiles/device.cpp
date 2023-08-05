#include <string>
#include "device.h"

using namespace std;

Device::Device(){
            address = IPaddress(0,0,0,0);
            name = "Unknown";
            mydevice = false;
        }

Device::Device(IPaddress x){
            address = x;
            mydevice = false;
        }

Device::Device(IPaddress x, std::string y){
            address = x;
            name = y;
            mydevice = false;
        }

string Device::getString(){
    string res;
    res = "Name: " + name + " Address: " + address.getString();
    return res;
}