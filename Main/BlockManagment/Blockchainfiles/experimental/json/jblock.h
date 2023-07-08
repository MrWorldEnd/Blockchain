#include <iostream>
#include <fstream>
#include <cstdlib>
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/prettywriter.h>
#include "Blockchain.cpp"

using namespace rapidjson;
using namespace std;

Value jBlock (Block x)
{
    Value out(kArrayType);
    Value obj(kObjectType);
    Value val(kObjectType);

    Document::AllocatorType& allocator = d.GetAllocator();
    size_t sz = allocator.Size();

    obj.AddMember("index", dt.getindex(), allocator);

    //size_t printing
    val.SetString(dt.getHash().c_str(), static_cast<SizeType>(description.length()), allocator);
    obj.AddMember("Hash", val, allocator);

    val.SetString(dt.getPrevHash().c_str(), static_cast<SizeType>(description.length()), allocator);
    obj.AddMember("PrevHash", val, allocator);

    val.SetString(dt.getData().packetStr().c_str(), static_cast<SizeType>(description.length()), allocator);
    obj.AddMember("TransactionData", val, allocator);
    
    val.SetString(dt.getData().getheader().getsenderKey().c_str(), static_cast<SizeType>(description.length()), allocator);
    obj.AddMember("SenderKey", val, allocator);
    
    val.SetString(dt.getData().getheader().getreceiverKey().c_str(), static_cast<SizeType>(description.length()), allocator);
    obj.AddMember("ReceiveKey", val, allocator);
    
    val.SetString(dt.getData().getheader().gettimestamp().c_str(), static_cast<SizeType>(description.length()), allocator);
    obj.AddMember("Timestamp", val, allocator);
    
    out.PushBack(obj, allocator);

    return out;
};

void addblocktofile(Block x, string filename)
{
    Document d;
    d.SetObject();

    Document::AllocatorType& allocator = d.GetAllocator();

    size_t sz = allocator.Size();

    //something
    Value blocktoadd;
    blocktoadd = jBlock(x);

    d.AddMember("Block", blocktoadd, allocator);

    // Convert JSON document to string
    StringBuffer strbuf;
    PrettyWriter<StringBuffer> writer(strbuf);
    d.Accept(writer);

    string temp=strbuf.GetString();

    // Create and open a text file
    ofstream myFile(filename);

    myFile << temp;

    myFile.close();
};
