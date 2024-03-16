#include "nodefunctions.cpp"

class node
{
private:
    Blockchain myblockchain;
    Device thisServer;

public:

    node();
    ~node();

    void consensus()
    {
        myblockchain = consensusmechanism(myblockchain);        
    }

    void processbuffer()
    {
        std::stack<Device> requestlist;
        PacketPayload x;
        Packet z;
        TxDataset y;
        Block s;

        requestlist = readbuffer();

        x.setObjID(thisServer.getid());
        x.setObjlvl(thisServer.getaccesslvl());
        
        while (!requestlist.empty())
        {
            x.setSubjectID(requestlist.top().getid());
            x.setObjlvl(requestlist.top().getaccesslvl());
            if (x.isvalidreq())
            {

            z.setpayload(x);
            y.addTX(z);

            if (y.isfull())
            {
                s.setData(y);
                myblockchain.addBlock(y);
            }

            }

        resetfile("buffer.jsom");        
    }
};

node::node(/* args */)
{
        thisServer.setid(0000);
        thisServer.setname("Oblivion");
        thisServer.setIP(IPaddress());
};

};