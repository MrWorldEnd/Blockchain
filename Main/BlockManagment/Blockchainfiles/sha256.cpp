#include <iostream>
#include <openssl/sha.h>
#include <cstring>

std::string sha256(const std::string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input.c_str(), input.length());
    SHA256_Final(hash, &sha256);

    char buf[SHA256_DIGEST_LENGTH * 2 + 1];
    buf[SHA256_DIGEST_LENGTH * 2] = '\0';

    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&buf[i * 2], "%02x", hash[i]);
    }

    return std::string(buf);
}
