#include <iostream>
#include <fstream>

using namespace std;

int readLine(ifstream &file) {
    string line;

    while (getline(file, line)) {
        getToken(line);
    }
}

int getToken(string line) {
    
}

int main() {
    ifstream file;
    file.open("test.cpp");
    readLine(file);

};