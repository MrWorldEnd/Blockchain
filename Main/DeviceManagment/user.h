#include "key.h"
#include <stack>
#include <sqlite3.h>
using namespace std;

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

class user
{
    private:
        string id;
        stack<Key> mykey; 
    public:
        user(){
            id =  "not set";
            Key newkey;
            mykey.push(newkey);
        };

        user(string id, string password);

        void loadkeys()
        {
            sqlite3* DB;
            int exit = 0;
            exit = sqlite3_open("test.db", &DB);
            string data("CALLBACK FUNCTION");

            string sql("SELECT * FROM COMPANY;");
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
};