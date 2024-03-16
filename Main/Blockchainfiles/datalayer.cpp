#include "fileops.cpp"

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
};

Document addblocktoDocument(Block x, string filename)
{
    cout<<"Adding block to Json started\n";

    Document jsonfile = loadFile(filename);
    jsonfile.SetObject();

    Document::AllocatorType& allocator = jsonfile.GetAllocator();

    size_t sz = allocator.Size();
    Value json_objects(kObjectType);
    json_objects = jBlock(x, allocator);
    jsonfile.AddMember("Block", json_objects, allocator);

    // Convert JSON document to string
    StringBuffer strbuf;
    PrettyWriter<StringBuffer> writer(strbuf);
    jsonfile.Accept(writer);
    string temp=strbuf.GetString();

    cout<<"Adding block to Json document completed\n";
    return jsonfile;
};

Value jBlock (Block x, Document::AllocatorType& y)
{
    cout<< "json sub program";

    Value out(kArrayType);
    Value obj(kObjectType);
    Value val(kObjectType);

    obj.AddMember("index", x.getData().getsize(), y);

    //size_t printing
    val.SetString(x.getHash().c_str(),  y);
    obj.AddMember("Hash", val, y);

    val.SetString(x.getPrevHash().c_str(), y);
    obj.AddMember("PrevHash", val, y);

    val.SetString(x.getData().getstr().c_str(), y);
    obj.AddMember("TransactionData", val, y);
    
    out.PushBack(obj, y);

    return out;
};

//load Init data

Blockchain initdata()
{
        // Open the file for reading 
    FILE* fp = fopen("InitializeData.json", "r"); 
  
    // Use a FileReadStream to 
      // read the data from the file 
    char readBuffer[65536]; 
    rapidjson::FileReadStream is(fp, readBuffer, 
                                 sizeof(readBuffer)); 
  
    // Parse the JSON data  
      // using a Document object 
    rapidjson::Document d; 
    d.ParseStream(is); 
  
    // Close the file 
    fclose(fp); 
  
    // Access the data in the JSON document 
    std::cout << d["Hash"].GetString() << std::endl; 
    std::cout << d["ThisDevice"].GetString() << std::endl;
    std::cout << d["MyDevices"].GetString() << std::endl;
    Blockchain x = Blockchain(d["Hash"].GetString());
    return x;
}

stack<Device> readbuffer()
{
        // Open the file for reading 
    FILE* fp = fopen("buffer.json", "r"); 
  
    // Use a FileReadStream to 
      // read the data from the file 
    char readBuffer[65536]; 
    rapidjson::FileReadStream is(fp, readBuffer, 
                                 sizeof(readBuffer)); 
  
    // Parse the JSON data  
      // using a Document object 
    rapidjson::Document d; 
    d.ParseStream(is); 
  
    // Close the file 
    fclose(fp); 
  
    stack <Device> requestlist;
    Device request; 
    // Access the device
    for (SizeType i = 0; i < d["transactions"].Size(); i++){
        request.setid(d["id"][i].GetInt());
        request.setname(d["name"][i].GetString());
        request.setIP(IPaddress(d["ip"][i].GetString()));
        requestlist.push(request);
    }

    resetfile("buffer.json");

    return requestlist;
}