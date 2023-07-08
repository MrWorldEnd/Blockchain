#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <cstring>

#include "Socket.h" 

#include "Blockchain.h"
#include "IPlistmanager.h"
#include "PacketPayload.h"

using namespace std;

int createTableS() {
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
                      "index TEXT NOT NULL,"
                      "data TEXT NOT NULL,"
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
}

void initialiseDB() {
    // Call the createTable function
    int result = createTable();

    if (result != SQLITE_OK) {
        std::cerr << "Error creating table." << std::endl;
        return result;
    }
}
