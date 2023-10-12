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

    Value out(kArrayType);
    Value obj(kObjectType);
    Value val(kObjectType);

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

    Document jsonfile = loadFile(filename);
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

Document createfile(std::string x)
{
        ofstream myFile(x);
    if(!myFile.good())
    {        
        ofstream myFile(x);
        myFile.close();
        return;
        
    }else
    {
      myFile = loadFile(x);
      return;
    };
}

int SearchJson(std::string x)
{
	std::string fullPath = CCFileUtils::sharedFileUtils()->fullPathForFilename("json/deluxe/treasurebag.json");

	    unsigned long bufferSize = 0;

	    const char* mFileData = (const char*)CCFileUtils::sharedFileUtils()->getFileData(fullPath.c_str(), "r", &bufferSize);

	    std::string clearData(mFileData);
	    size_t pos = clearData.rfind("}");
	    clearData = clearData.substr(0, pos+1);
	    document.Parse<0>(clearData.c_str());
	    assert(document.HasMember(x));

	    const Value& a = document[x]; // Using a reference for consecutive access is handy and faster.
	    assert(a.IsArray());
	    
		// Using a reference for consecutive access is handy and faster.
        const Value& a = document[x];
        assert(a.IsArray());
        for (SizeType i = 0; i < a.Size(); i++) // Uses SizeType instead of size_t
                printf("a[%d] = %d\n", i, a[i].GetString());
                block y;
                y.setIndex(a[i]["index"].GetString());

                blockchain.addblock(n)


		        CCLOG("a[%d] = %d\n", i, a[i].GetInt());
        }
    const char* json_data = R"(
        [
            {"name": "Alice", "age": 25},
            {"name": "Bob", "age": 30},
            {"name": "Charlie", "age": 22}
        ]
    )";

    Document document;
    document.Parse(json_data);

    if (!document.IsArray()) {
        cout << "Invalid JSON format. Expected an array." << endl;
        return 1;
    }

    stack<pair<string, int>> dataStack;

    for (SizeType i = 0; i < document.Size(); ++i) {
        const Value& obj = document[i];
        
        if (obj.HasMember("Block") && obj.HasMember("index") && obj.HasMember("previousHash") && obj.HasMember("TxDataset") && obj.HasMember("TxDataset") && obj.HasMember("currentHash") && obj["name"].IsString() && obj["age"].IsInt()) {
            string name = obj["name"].GetString();
            int age = obj["age"].GetInt();
            dataStack.push(make_pair(name, age));
        } else {
            cout << "Invalid object format at index " << i << endl;
        }
    }

    cout << "Data stored in stack:" << endl;
    while (!dataStack.empty()) {
        pair<string, int> data = dataStack.top();
        dataStack.pop();
        cout << "Name: " << data.first << ", Age: " << data.second << endl;
    }

    return 0;
}
{
    const char* json_data = R"(
        {
            "person1": {"name": "Alice", "age": 25},
            "person2": {"name": "Bob", "age": 30},
            "person3": {"name": "Charlie", "age": 22}
        }
    )";

    Document document;
    document.Parse(json_data);

    if (!document.IsObject()) {
        cout << "Invalid JSON format. Expected an object." << endl;
        return 1;
    }

    stack<pair<string, int>> dataStack;

    for (Value::ConstMemberIterator itr = document.MemberBegin(); itr != document.MemberEnd(); ++itr) {
        if (itr->value.IsObject() && itr->value.HasMember("name") && itr->value.HasMember("age") &&
            itr->value["name"].IsString() && itr->value["age"].IsInt()) {
            string name = itr->value["name"].GetString();
            int age = itr->value["age"].GetInt();
            dataStack.push(make_pair(name, age));
        } else {
            cout << "Invalid object format for key: " << itr->name.GetString() << endl;
        }
    }

    cout << "Data stored in stack:" << endl;
    while (!dataStack.empty()) {
        pair<string, int> data = dataStack.top();
        dataStack.pop();
        cout << "Name: " << data.first << ", Age: " << data.second << endl;
    }

    return 0;
}
