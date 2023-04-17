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
    regex("bool"),
    regex("string")};

vector<regex> keywordsRegexVec = {
    regex("main"),
    regex("return")};

vector<regex> loopsRegexVec = {
    regex("for"),
    regex("while"),
    regex("\bdo\b")};

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

void getDataTypeToken(string line)
{
    if (regex_search(line, regex("int")))
        sendTokenToHTML("int");

    if (regex_search(line, regex("double")))
        sendTokenToHTML("double");

    if (regex_search(line, regex("char")))
        sendTokenToHTML("char");

    if (regex_search(line, regex("float")))
        sendTokenToHTML("float");

    if (regex_search(line, regex("bool")))
        sendTokenToHTML("bool");

    if (regex_search(line, regex("string")))
        sendTokenToHTML("string");
}

void getKeywordToken(string line)
{
    if (regex_search(line, regex("main")))
        sendTokenToHTML("main");

    if (regex_search(line, regex("return")))
        sendTokenToHTML("return");
}

void getLoopToken(string line)
{
    if (regex_search(line, regex("for")))
        sendTokenToHTML("for");

    if (regex_search(line, regex("while")))
        sendTokenToHTML("while");

    if (regex_search(line, regex("do")))
        sendTokenToHTML("do");
}

void getConditionalToken(string line)
{
    if (regex_search(line, regex("if")))
        sendTokenToHTML("if");

    if (regex_search(line, regex("else")))
        sendTokenToHTML("else");

    if (regex_search(line, regex("switch")))
        sendTokenToHTML("switch");

    if (regex_search(line, regex("case")))
        sendTokenToHTML("case");

    if (regex_search(line, regex("default")))
        sendTokenToHTML("default");
}

void getOperatorToken(string line)
{
    if (regex_search(line, regex("\\+")))
        sendTokenToHTML("+");

    if (regex_search(line, regex("\\-")))
        sendTokenToHTML("-");

    if (regex_search(line, regex("\\*")))
        sendTokenToHTML("*");

    if (regex_search(line, regex("\\/")))
        sendTokenToHTML("/");

    if (regex_search(line, regex("\\%")))
        sendTokenToHTML("%");

    if (regex_search(line, regex("\\=")))
        sendTokenToHTML("=");

    if (regex_search(line, regex("\\+\\+")))
        sendTokenToHTML("++");

    if (regex_search(line, regex("\\-\\-")))
        sendTokenToHTML("--");

    if (regex_search(line, regex("\\!")))
        sendTokenToHTML("!");

    if (regex_search(line, regex("\\&\\&")))
        sendTokenToHTML("&&");

    if (regex_search(line, regex("\\|\\|")))
        sendTokenToHTML("||");

    if (regex_search(line, regex("\\<")))
        sendTokenToHTML("<");

    if (regex_search(line, regex("\\>")))
        sendTokenToHTML(">");

    if (regex_search(line, regex("\\<\\=")))
        sendTokenToHTML("<=");

    if (regex_search(line, regex("\\>\\=")))
        sendTokenToHTML(">=");

    if (regex_search(line, regex("\\!\\=")))
        sendTokenToHTML("!=");

    if (regex_search(line, regex("\\=\\=")))
        sendTokenToHTML("==");

    if (regex_search(line, regex("\\+\\=")))
        sendTokenToHTML("+=");

    if (regex_search(line, regex("\\-\\=")))
        sendTokenToHTML("-=");

    if (regex_search(line, regex("\\*\\=")))
        sendTokenToHTML("*=");

    if (regex_search(line, regex("\\/\\=")))
        sendTokenToHTML("/=");

    if (regex_search(line, regex("\\%\\=")))
        sendTokenToHTML("%=");
}

void getToken(string line)
{
    if (regex_search(line, regex("int"|"double")))
        getDataTypeToken(line);

    /**for (regex dataTypeRegex : dataTypeRegexVec)
    {
        if (regex_search(line, dataTypeRegex))
            getDataTypeToken(line);
    }

    for (regex keywordRegex : keywordsRegexVec)
    {
        if (regex_search(line, keywordRegex))
            getKeywordToken(line);
    }

    for (regex cycleRegex : loopsRegexVec)
    {
        if (regex_search(line, cycleRegex))
            getLoopToken(line);
    }

    for (regex loopsRegex : conditionalsRegexVec)
    {
        if (regex_search(line, loopsRegex))
            getConditionalToken(line);
    }

    for (regex operatorsRegex : operatorsRegexVec)
    {
        if (regex_search(line, operatorsRegex))
            getOperatorToken(line);
    }
    */
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