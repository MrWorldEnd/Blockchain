#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sqlite3.h>

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

void createdatatables(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char const *sql;
   /* Open database */
   rc = sqlite3_open("test.db", &db);
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stdout, "Opened database successfully\n");
   }

   /* Create Userlist statement */
   sql = "CREATE TABLE UserList(" \
      "UserID INT PRIMARY KEY NOT NULL," \
      "UserName TEXT NOT NULL," \
      "PrimaryDeviceMac TEXT," \
      "Password TEXT NOT NULL)";
   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "UserList created successfully\n");
   };

   sqlite3_close(db);
   /* Create Peer List statement */
   sql = "CREATE TABLE PeerList(" \
      "DeviceID INT PRIMARY KEY NOT NULL," \
      "DeviceName TEXT NOT NULL," \
      "DeviceIP INT NOT NULL)";
   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "PeerListTable created successfully\n");
   };
   sqlite3_close(db);
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

void loadnetworkinfo()
{
	sqlite3* DB;
	int exit = 0;
	exit = sqlite3_open("test.db", &DB);
	string data("CALLBACK FUNCTION");

	string sql("SELECT * FROM PeerList;");
	if (exit) {
		std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
		return (-1);
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
}
bool tablecheck()
{
   bool check = "false";
	sqlite3* DB;
	int exit = 0;
	exit = sqlite3_open("test.db", &DB);
	string data("CALLBACK FUNCTION");

	string sql("select count(type) from sqlite_master where type='table' and name='PeerList';");
	if (exit) {
		std::cerr << "\nError open DB " << sqlite3_errmsg(DB) << std::endl;
		return (-1);
	}
	else
		std::cout << "\nDatabase exists" << std::endl;
	int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL);

	string sql("select count(type) from sqlite_master where type='table' and name='UserList';");
	if (exit) {
		std::cerr << "\nError open DB " << sqlite3_errmsg(DB) << std::endl;
		return (-1);
	}
	else
		std::cout << "\nDatabase exists" << std::endl;
	int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL);

	if (rc != SQLITE_OK)
		cerr << "Error SELECT" << endl;
	else {
		cout << "Operation OK!" << endl;

	}
	sqlite3_close(DB);
   if(rc == 1)
      check = "true";
   return check;
}

//validatea blockchain