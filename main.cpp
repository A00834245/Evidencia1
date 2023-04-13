#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

const regex intRegex("int");

void getToken(string line) {
    if (regex_search(line, intRegex)) {
        cout << "int found" << endl;
    }
}

void readLine(ifstream &file) {
    string line;

    while (getline(file, line)) {
        getToken(line);
    }
}

int main() {
    ifstream file;
    file.open("test.cpp");
    readLine(file);

    return 0;
};