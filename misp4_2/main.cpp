#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cryptopp/sha.h>

using namespace CryptoPP;
using namespace std;

string calculateHash(const string& input) {
    SHA256 hash;
    byte digest[SHA256::DIGESTSIZE];

    hash.Update(reinterpret_cast<const byte*>(input.data()), input.size());
    hash.Final(digest);

    stringstream ss;
    ss << hex << setfill('0');
    for (const auto &byte : digest) {
        ss << setw(2) << static_cast<int>(byte);
    }

    return ss.str();
}

int main() {
    string filename = "file.txt";
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file " << filename << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        string hash = calculateHash(line);
        cout << "Hash of '" << line << "': " << hash << endl;
    }

    file.close();
    return 0;
}