#include <iostream>
#include <fstream>
#include <cstdlib>
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/ostreamwrapper.h>

void getblock(Block x, std::string filename)
{
	FILE* FP = fopen(filename,"r");
	char buffer[65536];
	rapidjson::FileReadStream is(fp,buffer, sizeof(buffer));
	
	rapidjson::Document document;
	document.ParseStream(is);
	
	if (!document.IsObject()) {
		std::cout << "\nInvalid Json format. Expected Object.";
		fclose(fp);
		return -1;
	}
	
	const rapidjson::Value& arrayValue = document["Block"];
	if (nameValue.IsArray()) {
		std::cout << "\nInvalid Json format. Expected array";
		fclose(fp);
		return -1;
	}
	
    	for (rapidjson::SizeType i = 0; i < numbersArray.Size(); i++) {
		const rapidjson::Value& numberValue = numbersArray[i];
		if (numberValue.IsInt()) {
		    int number = numberValue.GetInt();
		    std::cout << "Number at index " << i << ": " << number << std::endl;
        }
    }

    fclose(fp);
    return 0;
