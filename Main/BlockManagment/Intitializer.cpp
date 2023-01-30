#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <cstring>
#include "device.cpp"
#include "key.h"


static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

static int callback(void* data, int argc, char** argv, char** azColName)
{
	int i;
	fprintf(stderr, "%s: ", (const char*)data);

	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}

	printf("\n");
	return 0;
}

int main ()
{
    //Initialize

};

void initializepeertable(){
   //conect to peer list from sql database


   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char const *sql;
   
   /* Open database */
   rc = sqlite3_open("peerlist.db", &db);
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return;
   } else {
      fprintf(stdout, "Opened database successfully\n");
   }

   /* Create SQL statement */
   sql = "CREATE TABLE PeerList(" \
      "ID INT PRIMARY KEY NOT NULL," \
      "NAME TEXT NOT NULL," \
      "ADDRESS CHAR(50)";

   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Table created successfully\n");
   }
   sqlite3_close(db);
    
   //load peer list

   //load check for current block chain state

   //continuouse loop for blockchain update
};

void loadPeerlist(){
	sqlite3* DB;
	int exit = 0;
	exit = sqlite3_open("test.db", &DB);
	string data("CALLBACK FUNCTION");

	string sql("SELECT * FROM PeerList;");
	if (exit) {
		std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
		return;
	}
	else
		std::cout << "Opened Database Successfully!" << std::endl;

	int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL);

	if (rc != SQLITE_OK)
		cerr << "Error SELECT" << endl;
	else {
		cout << "Operation OK!" << endl;
	}

	sqlite3_close(DB);
};

void loadDevicelist(){
	sqlite3* DB;
	int exit = 0;
	exit = sqlite3_open("test.db", &DB);
	string data("CALLBACK FUNCTION");

	string sql("SELECT * FROM DeviceList;");
	if (exit) {
		std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
		return;
	}
	else
		std::cout << "Opened Database Successfully!" << std::endl;

	int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL);

	if (rc != SQLITE_OK)
		cerr << "Error SELECT" << endl;
	else {
		cout << "Operation OK!" << endl;
	}

	sqlite3_close(DB);
};

void loadKeylist(){
	sqlite3* DB;
	int exit = 0;
	exit = sqlite3_open("test.db", &DB);
	string data("CALLBACK FUNCTION");

	string sql("SELECT * FROM KeyList;");
	if (exit) {
		std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
		return;
	}
	else
		std::cout << "Opened Database Successfully!" << std::endl;

	int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL);

	if (rc != SQLITE_OK)
		cerr << "Error SELECT" << endl;
	else {
		cout << "Operation OK!" << endl;
	}

	sqlite3_close(DB);
};