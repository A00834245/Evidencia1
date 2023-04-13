#include <iostream>
#include <fstream>

using namespace std;

ifstream openFile(string fileName) {
    ifstream file;
    file.open(fileName);
    return file;
}

int readLine(ifstream &file) {
    string line;

    while (getline(file, line)) {
        getToken(line);
    }
}

int getToken(string line) {
    
}

int main() {
    openFile("test.txt");
    readLine(file);

};