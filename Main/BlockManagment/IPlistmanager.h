#include "device.h"
#include <stack>

using namespace std;

class IPlist
{
    private:
        stack<Device>list;
    public:
        IPlist();
        void addtolist(Device x);
        void print(stack<Device> res);
};