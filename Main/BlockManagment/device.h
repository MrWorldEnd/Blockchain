#include "IPaddress.cpp"

using namespace std;

class Device
{
    private:
    /* data */
        IPaddress address;
        string name;
        bool mydevice;
        int accesslvl;
    public:
    //constructors
        Device();
        Device(IPaddress x);
        Device(IPaddress x, std::string y); 

        IPaddress getIP(){return address;};
        string getname(){return name;};
        bool ismine(){return mydevice;};

        void setIP(IPaddress x){address = x;};
        void setname(string x){name = x;};
        void toggleismine(){mydevice = !mydevice;};

        string getString();

        friend ostream& operator<<(ostream& os,const Device& x){
            string ip;
            IPaddress addr;

            addr = x.address;
            ip = addr.getString();

            os << "Name: " + x.name + "Address: " + ip;
            return os;
        }
};

class IotDevice : public Device
{
    private:
        char state;
    public:
        void turnOn(){state = 1;}
        void turnOff(){state = 0;}

        char getstate() {return state;}

        void toggle(){
            if(state == 1){turnOff();}
            else{turnOff();};}
        
        IotDevice(){
            turnOff();
        }
        IotDevice(string x, IPaddress y){
            setname(x);
            setIP(y);
            turnOff();
        }
};
