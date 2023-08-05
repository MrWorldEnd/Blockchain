#include <iostream>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

int main() {
    // Create a JSON document
    rapidjson::Document document;
    document.SetObject();

    // Create key-value pairs
    rapidjson::Value nameValue;
    nameValue.SetString("John Doe");

    rapidjson::Value ageValue;
    ageValue.SetInt(30);

    // Insert key-value pairs into the document
    rapidjson::Document::AllocatorType& allocator = document.GetAllocator();
    document.AddMember("name", nameValue, allocator);
    document.AddMember("age", ageValue, allocator);

    // Convert the document to a string
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    document.Accept(writer);

    // Print the JSON string
    std::cout << buffer.GetString() << std::endl;

    return 0;
}
