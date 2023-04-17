#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

using namespace std;

vector<regex> dataTypeRegexVec = {
    regex("int"),
    regex("\\bdouble\\b"),
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
    regex("\\bdo\\b")};

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
    if (regex_search(line, regex("\\bint\\b")) || regex_search(line, regex("\\bdouble\\b")) || regex_search(line, regex("\\bchar\\b")) ||
        regex_search(line, regex("\\bfloat\\b")) || regex_search(line, regex("\\bbool\\b")) || regex_search(line, regex("\\bstring\\b")))
        getDataTypeToken(line);

    if (regex_search(line, regex("\\bmain\\b")) || regex_search(line, regex("\\breturn\\b")))
        getKeywordToken(line);

    if (regex_search(line, regex("\\bfor\\b")) || regex_search(line, regex("\\bwhile\\b")) || regex_search(line, regex("\\bdo\\b")))
        getLoopToken(line);

    if (regex_search(line, regex("\\bif\\b")) || regex_search(line, regex("\\belse\\b")) || regex_search(line, regex("\\bswitch\\b")) ||
        regex_search(line, regex("\\bcase\\b")) || regex_search(line, regex("\\bdefault\\b")))
        getConditionalToken(line);

    if (regex_search(line, regex("\\+")) || regex_search(line, regex("\\-")) || regex_search(line, regex("\\*")) ||
        regex_search(line, regex("\\/")) || regex_search(line, regex("\\%")) || regex_search(line, regex("\\=")) ||
        regex_search(line, regex("\\+\\+")) || regex_search(line, regex("\\-\\-")) || regex_search(line, regex("\\!")) ||
        regex_search(line, regex("\\&\\&")) || regex_search(line, regex("\\|\\|")) || regex_search(line, regex("\\<")) ||
        regex_search(line, regex("\\>")) || regex_search(line, regex("\\<\\=")) || regex_search(line, regex("\\>\\=")) ||
        regex_search(line, regex("\\!\\=")) || regex_search(line, regex("\\=\\=")) || regex_search(line, regex("\\+\\=")) ||
        regex_search(line, regex("\\-\\=")) || regex_search(line, regex("\\*\\=")) || regex_search(line, regex("\\/\\=")) ||
        regex_search(line, regex("\\%\\=")))
        getOperatorToken(line);
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