/*
Evidencia 1. Resaltador de Lexico

Elaborado por: 
Maruca Cantu Valdes | A00834245
Mariel Perez Ferrusquia | A00832811
Roberto Andonie Hernandez | A01411863
*/

#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

<<<<<<< HEAD
<<<<<<< HEAD
const regex intRegex("int");
const regex doubleRegex("double");

void getToken(string line) {
    if (regex_search(line, intRegex)) {
        cout << "int found" << endl;
    }

        if (regex_search(line, doubleRegex)) {
        cout << "double found" << endl;
    }
=======
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
=======
void printLine()
>>>>>>> 5aadb51487060e2533a5e4475d6f4db53cc88d15
{
    ofstream outputFile;
    outputFile.open("index.html", std::ios::app);
    outputFile << "<br>" << endl;
    outputFile.close();
>>>>>>> eb82ed70aff03d85682ce573ad38c440c819ad61
}

ofstream openFile(string fileName)
{
    ofstream outputFile;
    outputFile.open(fileName, std::ios::app);
    return outputFile;
}

void checkForOther(string fileName, string originalLine, int &index)
{
    ofstream outputFile = openFile(fileName);
    int whiteSpaceIndex = originalLine.substr(index, originalLine.length() - index).find(" ");
    if (whiteSpaceIndex != -1)
    {
        outputFile << "<span>" << originalLine.substr(index, whiteSpaceIndex) << "</span>";
        index += whiteSpaceIndex;
    }
    else
    {
        outputFile << "<span>" << originalLine[index++] << "</span>";
    }
}

string getSpecialChar(string token)
{
    if (token == "<")
    {
        return "&lt;";
    }
    else if (token == ">")
    {
        return "&gt;";
    }
    else if (token == "&")
    {
        return "&amp;";
    }
    else if (token == "\"")
    {
        return token = "&quot;";
    }
    else if (token == "'")
    {
        return "&apos;";
    }
    return token;
}

bool checkForSpecialChar(string &token)
{
    if (token == "<" || token == ">" || token == "&" || token == "\"" || token == "'")
    {
        token = getSpecialChar(token);
        return true;
    }
    return false;
}

void checkForToken(string fileName, string originalLine, int &index, vector<pair<string, string>> tokens, bool &somethingFound)
{
    ofstream outputFile = openFile(fileName);
    for (auto token : tokens)
    {
        if (originalLine.substr(index, token.first.length()) == token.first)
        {
            bool isSpecial = checkForSpecialChar(token.first);
            outputFile << "<span class='" << token.second + "'>" << token.first << "</span>";
            index = isSpecial ? index + 1 : index + token.first.length();
            somethingFound = true;
            break;
        }
    }
}

void checkForSpace(string fileName, string originalLine, int &index)
{
    ofstream outputFile = openFile(fileName);
    if (originalLine[index] == ' ')
    {
        outputFile << "<span>&nbsp</span>";
        index++;
    }
}

void sendTokensToHTML(vector<pair<string, string>> tokens, string originalLine)
{
    string fileName = "index.html";
    ofstream outputFile = openFile(fileName);

    int index = 0;

    while (index < originalLine.length())
    {

        bool somethingFound = false;
        checkForSpace(fileName, originalLine, index);

        checkForToken(fileName, originalLine, index, tokens, somethingFound);

        if (!somethingFound)
        {
            checkForOther(fileName, originalLine, index);
        }
    }
    outputFile.close();
}

void removeTokenFromLine(string &line, string token)
{
    string firstPart = "", secondPart = "";

    firstPart = line.find(token) != 0 ? line.substr(0, line.find(token) - 1) : "";
    secondPart = line.substr(line.find(token) + token.length(), line.length() - 1);

    line = firstPart + secondPart;
}

string getSeparatorToken(string line, vector<pair<string, string>> &tokens)
{
    string token;
    if (regex_search(line, regex("\\(")))
    {
        token = "(";
    }

    if (regex_search(line, regex("\\)")))
    {
        token = ")";
    }

    if (regex_search(line, regex("\\[")))
    {
        token = "[";
    }

    if (regex_search(line, regex("\\]")))
    {
        token = "]";
    }

    if (regex_search(line, regex("\\{")))
    {
        token = "{";
    }

    if (regex_search(line, regex("\\}")))
    {
        token = "}";
    }

    if (regex_search(line, regex("\\;")))
    {
        token = ";";
    }

    if (regex_search(line, regex("\\,")))
    {
        token = ",";
    }
    tokens.push_back(make_pair(token, "separator"));
    return token;
}

bool hasSeparatorToken(string line)
{
    return (regex_search(line, regex("\\(")) || regex_search(line, regex("\\)")) || regex_search(line, regex("\\{")) ||
            regex_search(line, regex("\\}")) || regex_search(line, regex("\\[")) || regex_search(line, regex("\\]")) ||
            regex_search(line, regex("\\;")) || regex_search(line, regex("\\,")) || regex_search(line, regex("\\.")));
}

// TODO: Add more tokens
string getOperatorToken(string line, vector<pair<string, string>> &tokens)
{
    string token;
    if (regex_search(line, regex("\\+")))
    {
        token = "+";
    }

    if (regex_search(line, regex("\\-")))
    {
        token = "-";
    }

    if (regex_search(line, regex("\\*")))
    {
        token = "*";
    }

    if (regex_search(line, regex("\\/")))
    {
        token = "/";
    }

    if (regex_search(line, regex("\\%")))
    {
        token = "%";
    }

    if (regex_search(line, regex("\\=")))
    {
        token = "=";
    }

    if (regex_search(line, regex("\\<")))
    {
        token = "<";
    }

    if (regex_search(line, regex("\\>")))
    {
        token = ">";
    }

    if (regex_search(line, regex("\\!")))
    {
        token = "!";
    }

    if (regex_search(line, regex("\\&")))
    {
        token = "&";
    }

    if (regex_search(line, regex("\\|")))
    {
        token = "|";
    }

    if (regex_search(line, regex("\\^")))
    {
        token = "^";
    }

    if (regex_search(line, regex("\\~")))
    {
        token = "~";
    }

    if (regex_search(line, regex("\\?")))
    {
        token = "?";
    }

    if (regex_search(line, regex("\\:")))
    {
        token = ":";
    }

    if (regex_search(line, regex("\\.")))
    {
        token = ".";
    }
    tokens.push_back(make_pair(token, "operator"));
    return token;
}

bool hasOperatorToken(string line)
{
    return (regex_search(line, regex("\\+")) || regex_search(line, regex("\\-")) || regex_search(line, regex("\\*")) ||
            regex_search(line, regex("\\/")) || regex_search(line, regex("\\%")) || regex_search(line, regex("\\=")) ||
            regex_search(line, regex("\\+\\+")) || regex_search(line, regex("\\-\\-")) || regex_search(line, regex("\\!")) ||
            regex_search(line, regex("\\&\\&")) || regex_search(line, regex("\\|\\|")) || regex_search(line, regex("\\<")) ||
            regex_search(line, regex("\\>")) || regex_search(line, regex("\\<\\=")) || regex_search(line, regex("\\>\\=")) ||
            regex_search(line, regex("\\!\\=")) || regex_search(line, regex("\\=\\=")) || regex_search(line, regex("\\+\\=")) ||
            regex_search(line, regex("\\-\\=")) || regex_search(line, regex("\\*\\=")) || regex_search(line, regex("\\/\\=")) ||
            regex_search(line, regex("\\%\\=")));
}

string getConditionalToken(string line, vector<pair<string, string>> &tokens)
{
    string token;
    if (regex_search(line, regex("\\bif\\b")))
    {
        token = "if";
    }

    if (regex_search(line, regex("\\belse\\b")))
    {
        token = "else";
    }

    if (regex_search(line, regex("\\bswitch\\b")))
    {
        token = "switch";
    }

    if (regex_search(line, regex("\\bcase\\b")))
    {
        token = "case";
    }

    if (regex_search(line, regex("\\bdefault\\b")))
    {
        token = "default";
    }
    if (regex_search(line, regex("\\bbreak\\b")))
    {
        token = "break";
    }

    tokens.push_back(make_pair(token, "conditional"));
    return token;
}

bool hasConditionalToken(string line)
{
    return (regex_search(line, regex("\\bif\\b")) || regex_search(line, regex("\\belse\\b")) ||
            regex_search(line, regex("\\bswitch\\b")) || regex_search(line, regex("\\bcase\\b")) ||
            regex_search(line, regex("\\bdefault\\b")) || regex_search(line, regex("\\bbreak\\b")));
}

string getLoopToken(string line, vector<pair<string, string>> &tokens)
{
    string token;
    if (regex_search(line, regex("\\bfor\\b")))
    {
        token = "for";
    }
    if (regex_search(line, regex("\\bwhile\\b")))
    {
        token = "while";
    }
    if (regex_search(line, regex("\\bfor\\b")))
    {
        token = "for";
    }
    tokens.push_back(make_pair(token, "loop"));
    return token;
}

bool hasLoopToken(string line)
{
    return (regex_search(line, regex("\\bfor\\b")) || regex_search(line, regex("\\bwhile\\b")) ||
            regex_search(line, regex("\\bdo\\b")));
}

string getKeywordToken(string line, vector<pair<string, string>> &tokens)
{
    string token;
    if (regex_search(line, regex("\\bmain\\b")))
    {
        token = "main";
    }
    if (regex_search(line, regex("\\breturn\\b")))
    {
        token = "return";
    }
    if (regex_search(line, regex("\\b\\#include\\b")))
    {
        token = "#include";
    }
    if (regex_search(line, regex("\\busing\\b")))
    {
        token = "using";
    }
    if (regex_search(line, regex("\\bnamespace\\b")))
    {
        token = "namespace";
    }
    tokens.push_back(make_pair(token, "keyword"));
    return token;
}

bool hasKeyWord(string line)
{
    return (regex_search(line, regex("\\bmain\\b")) || regex_search(line, regex("\\breturn\\b")) ||
            regex_search(line, regex("\\b\\#include\\b")) || regex_search(line, regex("\\busing\\b")) ||
            regex_search(line, regex("\\bnamespace\\b")));
}

string getDataTypeToken(string line, vector<pair<string, string>> &tokens)
{
    string token;
    if (regex_search(line, regex("\\bint\\b")))
    {
        token = "int";
    }

    if (regex_search(line, regex("\\bdouble\\b")))
    {
        token = "double";
    }

    if (regex_search(line, regex("\\bchar\\b")))
    {
        token = "char";
    }

    if (regex_search(line, regex("\\bfloat\\b")))
    {
        token = "float";
    }

    if (regex_search(line, regex("\\bbool\\b")))
    {
        token = "bool";
    }

    if (regex_search(line, regex("\\bstring\\b")))
    {
        token = "string";
    }
    tokens.push_back(make_pair(token, "datatype"));
    return token;
}

bool hasDataType(string line)
{
    return (regex_search(line, regex("\\bint\\b")) || regex_search(line, regex("\\bdouble\\b")) ||
            regex_search(line, regex("\\bchar\\b")) || regex_search(line, regex("\\bfloat\\b")) ||
            regex_search(line, regex("\\bbool\\b")) || regex_search(line, regex("\\bstring\\b")));
}

vector<pair<string, string>> getTokenVector(string &line)
{
    vector<pair<string, string>> tokens;

    while (hasDataType(line))
    {
        removeTokenFromLine(line, getDataTypeToken(line, tokens));
    }

    while (hasKeyWord(line))
    {
        removeTokenFromLine(line, getKeywordToken(line, tokens));
    }

    while (hasLoopToken(line))
    {
        removeTokenFromLine(line, getLoopToken(line, tokens));
    }

    while (hasConditionalToken(line))
    {
        removeTokenFromLine(line, getConditionalToken(line, tokens));
    }

    while (hasOperatorToken(line))
    {
        removeTokenFromLine(line, getOperatorToken(line, tokens));
    }
    while (hasSeparatorToken(line))
    {
        removeTokenFromLine(line, getSeparatorToken(line, tokens));
    }
    return tokens;
}

void putIndent(string line)
{
    ofstream outputFile;
    outputFile.open("index.html", ios::app);

    outputFile << "<span>";
    for (auto it = line.begin(); *it == ' ' && it != line.end(); it++)
        outputFile << "&nbsp";

    outputFile << "</span>";
    outputFile.close();
}

void readLines(ifstream &file)
{
    string line;

    while (getline(file, line))
    {
        string lineCopy = string(line.begin(), line.end());
        vector<pair<string, string>> tokens = getTokenVector(line);
        sendTokensToHTML(tokens, lineCopy);
        printLine();
    }
}

void writeFooter()
{
    ofstream outputFile;
    outputFile.open("index.html", ios::app);

    outputFile << "</body>" << endl;
    outputFile << "</html>" << endl;
    outputFile.close();
}

void writeHeader()
{
    ofstream outputFile;
    outputFile.open("index.html");

    outputFile << "<!DOCTYPE html>" << endl;
    outputFile << "<html>" << endl;
    outputFile << "<head>" << endl;
    outputFile << "<title>Lexical Analyzer</title>" << endl;
    outputFile << "<link rel=\"stylesheet\" href=\"styles.css\">" << endl;
    outputFile << "</head>" << endl;
    outputFile << "<body>" << endl;
    outputFile.close();
}

ifstream openFile()
{
    ifstream file;
    file.open("test.cpp");
    return file;
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
    ifstream file = openFile();
    writeHeader();
    readLines(file);
    writeFooter();

    return 0;
};