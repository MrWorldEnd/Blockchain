#include <chrono>
#include <ctime>  
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <cstring>

#include "device.cpp"
#include "Blockchain.cpp"
#include "request.h" 


using namespace std;

#define MAX_ADDRESS_LEN 120

void CreateTrusteddeviceDB()
{
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
		/* Create SQL statement */
		sql = "CREATE TABLE TRUSTEDDEVICES(" \
			"ID INT PRIMARY KEY NOT NULL," \
			"MACADRESS INT NOT NULL,"\
			"DEVICENAME TEXT NOT NULL;";
		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if( rc != SQLITE_OK ) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Table created successfully\n");
		}
		sqlite3_close(db);
};

void GenerateKeyDB()
{
	return(0);
		} else {
		fprintf(stdout, "Opened database successfully\n");
		}
		/* Create SQL statement */
		sql = "CREATE TABLE KEYS(" \
			"ID INT PRIMARY KEY NOT NULL," \
			"ACCESSLEVEL INT NOT NULL;";
		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if( rc != SQLITE_OK ) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Table created successfully\n");
		}
		sqlite3_close(db);
};

void GenerateIotDeviceDB()
{
	return(0);
		} else {
		fprintf(stdout, "Opened database successfully\n");
		}
		/* Create SQL statement */
		sql = "CREATE TABLE IOTDEVICES(" \
			"ID INT PRIMARY KEY NOT NULL," \
			"MACADDRESS INT NOTNULL,"\
			"DEVICENAME TEXT NOT NULL;";
		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if( rc != SQLITE_OK ) {
			fprintf(stderr, "SQL error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		} else {
			fprintf(stdout, "Table created successfully\n");
		}
		sqlite3_close(db);
};

void InitializeDB(){
    //Setup trusted device ilst
 	CreateTrusteddeviceDB();
	GenerateKeyDB();
	GenerateIotDeviceDB();
}

class Node : public Device{    
  private:
  
    string nodeName;
    IPaddress myaddress;
    Blockchain blockchain;
    Packet currentblock;
    string devicekey;
    TxDataset buffer;
    
  public:
    Node(){
      nodeName = "XXXX";
      myaddress = IPaddress();
      blockchain = Blockchain();
      devicekey = "";
      InitializeDB();
    }
    Node(string x){
      nodeName = x;
      myaddress = IPaddress();
      blockchain = Blockchain();
      devicekey = "";
    }

    

    bool validateTx(Key user,Device item){
        bool result = false;
        
        if (user.getaccesslvl() > item.getaccesslvl())
            result = true;
        return result;
    }
    
    void accessDevice(Key user, IotDevice item)
    {
    
      Packet newpacket;
      time_t time = chrono::system_clock::now();

	//create payload
      PacketPayload newpayload;
      newpayload.setSubject(user);
      newpayload.setObject(item);

	//create header
      TxHeader newheader;
      newheader.setsenderKey(devicekey);
      newheader.settimestamp();
      newheader.setTxAddr(myaddress.getString());

	//set packet info
      newpacket.setpayload(newpayload);
      newpacket.setpPinfo("");
      newpacket.setpHeader(newheader);
      
      	//update blockchain
      buffer.addTX(newpacket);
      if (buffer.isfull())
      	blockchain.addBlock(buffer);
    }
    
    
};
