//
// Created by mrworldend on 09/12/2021.
//

//Block Constructor
#include <stdio.h>
#include <string>
#include <ctime>

#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/prettywriter.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sqlite3.h>

#include "block.h"

using namespace rapidjson;
using namespace std;

Block::Block()
{
    index = 0;
    previousHash = '0';
    TxDataset x;
    setData(x);
    currentHash = sha256(x.getstr());
}

Block::Block(int inx, TxDataset d, std::string prevHash)
{
    index = inx;
    pdata = d;
    previousHash = prevHash;
    currentHash = sha256(d.getstr());
}


string Block::getHash(){return currentHash;}
string Block::getPrevHash(){return previousHash;}
bool Block::isValid(){return currentHash == getHash();}
int Block::getIndex() {return index;}


Block creategenesisBlock()
{
    std::time_t current;
    TxDataset d;
    Block genesis(0, d, 0);
    return genesis;
}

Value jBlock (Block x)
{
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
}


int createTable() {
    sqlite3* db;
    int rc;

    // Open the database connection
    rc = sqlite3_open("example.db", &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return rc;
    }

    // SQL statement to create a table
    const char* sql = "CREATE TABLE IF NOT EXISTS Peers ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "devicename TEXT NOT NULL,"
                      "blockchainstate INTEGER NOT NULL,"
                      "ip TEXT NOT NULL"
                      
                      "CREATE TABLE IF NOT EXISTS Blockchain ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "currentHash TEXT NOT NULL,"
                      "previousHash INTEGER NOT NULL,"
                      
                      "CREATE TABLE IF NOT EXISTS devices ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "name TEXT,"
                      "securitylevel INTEGER NOT NULL,"
                      "serverstatus bool"
                      ");";

    // Execute the SQL statement
    rc = sqlite3_exec(db, sql, 0, 0, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Table created successfully." << std::endl;
    }

    // Close the database connection
    sqlite3_close(db);

    return rc;
};

void addblock2db(Block x) {

    // Open the SQLite database
    sqlite3* db;
    int rc = sqlite3_open("example.db", &db);

    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return;
    } else {
        std::cout << "Opened database successfully!" << std::endl;
    }

    // Create a table if it doesn't exist
    
    const char* createTableSQL = "CREATE TABLE IF NOT EXISTS MyVariables (ID INTEGER PRIMARY KEY, Value TEXT);";
    rc = sqlite3_exec(db, createTableSQL, 0, 0, 0);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    } else {
        std::cout << "Table created successfully!" << std::endl;
    }

    // Example variable
    int myVariable = 42;

    // Insert the variable into the table
    
    std::string insertSQL = "INSERT INTO Blockchain (id,data,currentHash,previousHash) VALUES ('" +to_string(x.getIndex())  +"','" + x.getData().getstr() +"','"+ x.getHash() +"','"+ x.getPrevHash() +"');";
    rc = sqlite3_exec(db, insertSQL.c_str(), 0, 0, 0);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Variable inserted successfully!" << std::endl;
    }

    // Close the database
    sqlite3_close(db);
}
