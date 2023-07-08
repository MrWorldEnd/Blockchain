#include <iostream>
#include <sqlite3.h>

int addblock2db(Block x) {
    // Open the SQLite database
    sqlite3* db;
    int rc = sqlite3_open("example.db", &db);

    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    } else {
        std::cout << "Opened database successfully!" << std::endl;
    }

    // Create a table if it doesn't exist
    const char* createTableSQL = "CREATE TABLE IF NOT EXISTS MyVariables (ID INTEGER PRIMARY KEY, Value TEXT);";
    rc = sqlite3_exec(db, createTableSQL, 0, 0, 0);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    } else {
        std::cout << "Table created successfully!" << std::endl;
    }

    // Example variable
    int myVariable = 42;

    // Insert the variable into the table
    std::string insertSQL = "INSERT INTO Blockchain (id,data,currentHash,previousHash) VALUES ('" + x.index +"','"+ x.data +"','"+ x.currentHash +"','"+ x.previousHash +"');";
    rc = sqlite3_exec(db, insertSQL.c_str(), 0, 0, 0);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Variable inserted successfully!" << std::endl;
    }

    // Close the database
    sqlite3_close(db);

    return 0;
}
