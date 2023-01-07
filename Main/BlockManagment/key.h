#include "IPaddress.cpp"
#include <string>

using namespace std;

struct Key
{
		int accesslvl;
		char const id;
		char const itemcode;
};

Key masterKey()
{
	Key newkey;
	newkey.accesslvl = 3;
	newkey.id = 3;
	newkey.itemcode = 3;
	return newkey;
};

Key guestKey(Key SuperUser)
{
	Key guestKey;
	guestKey.accesslvl = SuperUser.accesslvl;
	guestKey.id = SuperUser.id;
	guestKey.itemcode = SuperUser.itemcode;
	return guestKey;
};