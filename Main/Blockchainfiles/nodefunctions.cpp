#include "initialization.cpp"

Blockchain consensusmechanism(Blockchain x)
{
    if(!x.isvalid())
    {
        Blockchain y;
        return y;
    }else
    {        
        x = Blockchain();
        x = initdata();
        return x;}
}

Blockchain addBlocktochain(Block x)
{
    Blockchain blockchain;
    Block y;
    y = blockchain.getlatestBlock();
    x.setPrevHash(y.getHash());
    x.setIndex(y.getIndex() + 1);
    blockchain.addBlock(x);
    addblock2db(x);
    addblocktoDocument(x,"filename");
    blockchain = consensusmechanism(blockchain);
    return blockchain;
}

