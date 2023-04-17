#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

const regex intRegex("int");
const regex doubleRegex("double");

void getToken(string line) {
    if (regex_search(line, intRegex)) {
        cout << "int found" << endl;
    }

        if (regex_search(line, doubleRegex)) {
        cout << "double found" << endl;
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