#include "nodefunctions.cpp"

class node
{
private:
    Blockchain myblockchain;

public:
    node(/* args */);
    ~node();

    void consensus()
    {
        myblockchain = consensusmechanism(myblockchain);
        DTTpacket consensusdata;
        consensusdata.setDtt(myblockchain.getstate());
        //share myblockchain.getstate
    }
};

node::node(/* args */)
{
}

node::~node()
{
}
