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
//sql
void createTable() {
    sqlite3* db;
    int rc;

    // Open the database connection
    rc = sqlite3_open("example.db", &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return;
    } else { 
        std::cout << "Opened database successfully!" << std::endl;
        return;
    }

    // SQL statement to create a table
    const char* sql = "CREATE TABLE BLOCKCHAIN (" \
                      "ID INT PRIMARY KEY AUTOINCREMENT," \
                      "CURREMTHASH TEXT," \
                      "PREVIOUSHASH INT);" ;

    // Execute the SQL statement
    rc = sqlite3_exec(db, sql, 0, 0, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Table created successfully." << std::endl;
    }

    // Close the database connection
    sqlite3_close(db);
    std:cout << "Database closed\n";
    return;
};

void addblock2db(Block x) {

    // Open the SQLite database
    sqlite3* db;
    int rc = sqlite3_open("example.db", &db);

    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return;
    } else { 
        std::cout << "Opened database successfully!\n" << std::endl;
        return;
    }

// Insert the variable into the table
    
    std::string insertSQL = "INSERT INTO BLOCKCHAIN (id,data,currentHash,previousHash) VALUES ('" +to_string(x.getIndex())  +"','" + x.getData().getstr() +"','"+ x.getHash() +"','"+ x.getPrevHash() +"');";
    rc = sqlite3_exec(db, insertSQL.c_str(), 0, 0, 0);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        return;
    } else {
        std::cout << "Variable inserted successfully!\n" << std::endl;
        return;
    }

    // Close the database
    sqlite3_close(db);
}




Value jBlock (Block x)
{
    cout<< "json sub program";
    Document d;
    d.SetObject();

    Value out(kArrayType);
    Value obj(kObjectType);
    Value val(kObjectType);

    Document::AllocatorType& allocator = d.GetAllocator();
    size_t sz = allocator.Size();

    obj.AddMember("index", x.getData().getsize(), allocator);

    //size_t printing
    val.SetString(x.getHash().c_str(),  allocator);
    obj.AddMember("Hash", val, allocator);

    val.SetString(x.getPrevHash().c_str(), allocator);
    obj.AddMember("PrevHash", val, allocator);

    val.SetString(x.getData().getstr().c_str(), allocator);
    obj.AddMember("TransactionData", val, allocator);
    
    out.PushBack(obj, allocator);

    return out;
};

Document addblocktoDocument(Block x, string filename)
{
    cout<<"Adding block to Json started\n";

    Document jsonfile;
    jsonfile.SetObject();

    Document::AllocatorType& allocator = jsonfile.GetAllocator();

    size_t sz = allocator.Size();
    Value json_objects(kObjectType);
    json_objects = jBlock(x);
    jsonfile.AddMember("Block", json_objects, allocator);

    // Convert JSON document to string
    StringBuffer strbuf;
    PrettyWriter<StringBuffer> writer(strbuf);
    jsonfile.Accept(writer);
    string temp=strbuf.GetString();

    cout<<"Adding block to Json document completed\n";
    return jsonfile;
};

Document loadFile(string filename) 
{
    ifstream ifs {filename};
    
    IStreamWrapper isw { ifs };

    Document doc {};
    doc.ParseStream( isw );

    return doc;
};

void createfile(std::string x)
{
        ofstream MyFile(x);
    if(!is_file_exist(x.c_str()))
    {        
        ofstream MyFile(x);
        MyFile.close();   
        
    }else
    {
      MyFile = loadFile(x);
      return MyFile;
    };
}
