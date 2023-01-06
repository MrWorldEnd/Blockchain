#include <string>
#include "device.h"

using namespace std;

Device::Device(){
            address = IPaddress(0,0,0,0);
            name = "Unknown";
            mydevice = false;
            accesslvl = 0;
            lockCode = "Lock code unset";
        }

Device::Device(IPaddress x){
            address = x;
            mydevice = false;
            accesslvl = 0;
            lockCode = "Lock code unset";
        }

Device::Device(IPaddress x, std::string y){
            address = x;
            name = y;
            mydevice = false;
            lockCode = "Lock code unset";
        }

string Device::getString(){
    string res;
    res = "Name: " + name + " Address: " + address.getString();
    return res;
}