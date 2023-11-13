#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

bool isDelimiter(char ch) {
    return (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
            ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
            ch == '[' || ch == ']' || ch == '{' || ch == '}');
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == '>' || ch == '<' || ch == '=');
}

bool validIdentifier(const char* str) {
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
        str[0] == '3' || str[0] == '4' || str[0] == '5' ||
        str[0] == '6' || str[0] == '7' || str[0] == '8' ||
        str[0] == '9' || isDelimiter(str[0]))
        return false;
    return true;
}

bool isKeyword(const char* str) {
    if (!std::strcmp(str, "if") || !std::strcmp(str, "else") ||
        !std::strcmp(str, "while") || !std::strcmp(str, "do") ||
        !std::strcmp(str, "break") || !std::strcmp(str, "continue") ||
        !std::strcmp(str, "int") || !std::strcmp(str, "double") ||
        !std::strcmp(str, "float") || !std::strcmp(str, "return") ||
        !std::strcmp(str, "char") || !std::strcmp(str, "case") ||
        !std::strcmp(str, "char") || !std::strcmp(str, "sizeof") ||
        !std::strcmp(str, "long") || !std::strcmp(str, "short") ||
        !std::strcmp(str, "typedef") || !std::strcmp(str, "switch") ||
        !std::strcmp(str, "unsigned") || !std::strcmp(str, "void") ||
        !std::strcmp(str, "static") || !std::strcmp(str, "struct") ||
        !std::strcmp(str, "goto")|| !std::strcmp(str, "cin")||
        !std::strcmp(str, "cout")|| !std::strcmp(str, "endl;"))
        return true;
    return false;
}

bool isInteger(const char* str) {
    int len = std::strlen(str);
    if (len == 0)
        return false;
    for (int i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' &&
            str[i] != '3' && str[i] != '4' && str[i] != '5' &&
            str[i] != '6' && str[i] != '7' && str[i] != '8' &&
            str[i] != '9' && (str[i] == '-' && i > 0))
            return true;
    }
    return false;
}

bool isConstant(const char* str) {
    int len = std::strlen(str);
    bool hasDecimal = false;
    if (len == 0)
        return false;
    for (int i = 0; i < len; i++) {
        if (str[i] != 'A' && str[i] != 'B' && str[i] != 'C' &&
            str[i] != 'D' && str[i] != 'E' && str[i] != 'F' &&
            str[i] != 'G' && str[i] != 'H' && str[i] != 'I' &&
            str[i] != 'J' &&str[i] != 'k' && str[i] != 'L' && str[i] != 'M' &&
            str[i] != 'N' && str[i] != 'O' && str[i] != 'P' &&
            str[i] != 'Q' && str[i] != 'R' && str[i] != 'S' &&str[i] != 'T' && str[i] != 'U' && str[i] != 'V' &&
            str[i] != 'W' && str[i] != 'X' && str[i] != 'Y' &&
            str[i] != 'Z' && str[i] != '.' || (str[i] == '-' && i > 0))
            return false;
        if (str[i] == '.')
            hasDecimal = true;
    }
    return hasDecimal;
}

char* subString(const char* str, int left, int right) {
    int i;
    char* subStr = (char*)malloc(static_cast<size_t>(right - left + 2));
    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return subStr;
}

void parse(const char* str) {
    int left = 0, right = 0;
    int len = std::strlen(str);
    while (right <= len && left <= right) {
        if (isDelimiter(str[right]) == false)
            right++;
        if (isDelimiter(str[right]) == true && left == right) {
            if (isOperator(str[right]) == true)
                std::cout << "'" << str[right] << "' IS AN OPERATOR" << std::endl;
            right++;
            left = right;
        } else if (isDelimiter(str[right]) == true && left != right || (right == len && left != right)) {
            char* subStr = subString(str, left, right - 1);
            if (isKeyword(subStr) == true)
                std::cout << "'" << subStr << "' IS A KEYWORD" << std::endl;
            else if (isInteger(subStr) == true)
                std::cout << "'" << subStr << "' IS AN INTEGER" << std::endl;
            else if (isConstant(subStr) == true)
                std::cout << "'" << subStr << "' IS A CONSTANT" << std::endl;
            else if (validIdentifier(subStr) == true && isDelimiter(str[right - 1]) == false)
                std::cout << "'" << subStr << "' IS A VALID IDENTIFIER" << std::endl;
            else if (validIdentifier(subStr) == false && isDelimiter(str[right - 1]) == false)
                std::cout << "'" << subStr << "' IS NOT A VALID IDENTIFIER" << std::endl;
                else
                    std::cout<<"'"<<subStr<<"' IS A CONSTANT"<<std::endl;
            free(subStr);
            left = right;
        }
    }
}

int main() {

    std::ifstream inputFile("program.txt");
    if (!inputFile.is_open()) {
        std::cout << "Unable to open the input file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        parse(line.c_str());
    }

    inputFile.close();
    return 0;
}




