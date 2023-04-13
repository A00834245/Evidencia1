#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

const regex intRegex("int"), doubleRegex ("double"), charRegex("char"),
        floatRegex("float"), boolRegex("bool"), mainRegex("main"), returnRegex("return");

void sendTokenToHTML(string token) {
    ofstream outputFile;
    outputFile.open("index.html", std::ios::app);

    string tag = "<p class=" + token + ">" + token + "</p>";
    outputFile << tag << endl;
    outputFile.close();
}

void getToken(string line) {
    if (regex_search(line, intRegex)) {
        cout << "int found" << endl;
    }

    if (regex_search(line, doubleRegex)) {
        cout << "double found" << endl;
    }

    if (regex_search(line, charRegex)) {
        cout << "char found" << endl;
    }

    if (regex_search(line, floatRegex)) {
        cout << "float found" << endl;
    }

    if (regex_search(line, boolRegex)) {
        cout << "bool found" << endl;
    }

    if (regex_search(line, mainRegex)) {
        cout << "main found" << endl;
    }

    if (regex_search(line, returnRegex)) {
        cout << "return found" << endl;
    }

    sendTokenToHTML(line);
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