#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

using namespace std;

vector<regex> dataTypeRegexVec = {
    regex("int"),
    regex("double"),
    regex("char"),
    regex("float"),
    regex("bool")};

vector<regex> keywordsRegexVec = {
    regex("main"),
    regex("return")};

vector<regex> cyclesRegexVec = {
    regex("for"),
    regex("while"),
    regex("do")};

vector<regex> conditionalsRegexVec = {
    regex("if"),
    regex("else"),
    regex("switch"),
    regex("case"),
    regex("default")};

vector<regex> operatorsRegexVec = {
    regex("\\+"),
    regex("\\-"),
    regex("\\*"),
    regex("\\/"),
    regex("\\%"),
    regex("\\="),
    regex("\\+\\+"),
    regex("\\-\\-"),
    regex("\\!"),
    regex("\\&\\&"),
    regex("\\|\\|"),
    regex("\\<"),
    regex("\\>"),
    regex("\\<\\="),
    regex("\\>\\="),
    regex("\\!\\="),
    regex("\\=\\="),
    regex("\\+\\="),
    regex("\\-\\="),
    regex("\\*\\="),
    regex("\\/\\="),
    regex("\\%\\="),
};

void sendTokenToHTML(string token)
{
    ofstream outputFile;
    outputFile.open("index.html", std::ios::app);

    string tag = "<span class=" + token + ">" + token + "</span>";
    outputFile << tag << endl;
    outputFile.close();
}

void getDataType(string line) {
    for (regex dataTypeRegex : dataTypeRegexVec)
    {
        if (regex_search(line, regex("int"))) sendTokenToHTML("int");
    }
}

void getToken(string line)
{

    for (regex dataTypeRegex : dataTypeRegexVec)
    {
        if (regex_search(line, dataTypeRegex))
            getDataType(line);
    }
}

void readLine(ifstream &file)
{
    string line;

    while (getline(file, line))
    {
        getToken(line);
    }
}

void openFile()
{
    ifstream file;
    file.open("test.cpp");
    readLine(file);
}

void clearFile()
{
    ofstream outputFile;
    outputFile.open("index.html");
    outputFile.clear();
    outputFile.close();
}

int main()
{
    clearFile();
    openFile();

    return 0;
};