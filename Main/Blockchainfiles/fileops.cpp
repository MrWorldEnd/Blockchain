#include "blockchain.cpp"

#include <sqlite3.h>
#include <fstream>

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/ostreamwrapper.h>

using namespace rapidjson;
using namespace std;

Document loadFile(string filename) 
{
    ifstream ifs {filename};
    
    IStreamWrapper isw { ifs };

    Document doc {};
    doc.ParseStream( isw );

    return doc;
};

Document createfile(std::string x)
{
        ofstream myFile(x);
    if(!myFile.good())
    {        
        ofstream myFile(x);
        myFile.close();
        Document newdoc;
        return newdoc;
        
    }else
    {
      return loadFile(x);
    };
}

void resetfile(std::string x)
{
    ofstream buffer(x);


    buffer.clear();
    buffer.close();
}
    
