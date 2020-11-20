#include "tools.h"

bool IsContextOfAStirng(LINEOFCODE line, int nLetterPos)
{
    bool isSingleQuotationOdd = false;
    bool isDoubleQuotationOdd = false;
    int pos = 0;

    for (auto letter : line)
    {
        if (pos == nLetterPos)
            break;

        if (letter == '\'')
            isSingleQuotationOdd = !isSingleQuotationOdd;

        if (letter == '\"')
            isDoubleQuotationOdd = !isDoubleQuotationOdd;

        pos++;
    }

    return isSingleQuotationOdd || isDoubleQuotationOdd;
}

string trim(LINEOFCODE sourse)
{
    string line = sourse;
    line.erase(0, line.find_first_not_of(' '));
    line.erase(line.find_last_not_of(' ') + 1, line.size() - line.find_last_not_of(' '));

    return line;
}

bool hasString(LINEOFCODE line)
{
    for (auto letter : line)
        if (letter == '\'' || letter == '\"')
            return true;

    return false;
}

int findTheFirstNotInString(LINEOFCODE line, int beginPos, string target)
{
    int pos = line.find_first_of(target,beginPos);
    
    while (IsContextOfAStirng(line, pos))
        pos = line.find_first_of(target, pos+target.size());
       
    return pos;
}

bool nextIs(LINEOFCODE code, int currentPos, char c)
{
    return code[++currentPos] == c;
}

bool nextIs(LINEOFCODE code, int currentPos, TEXT c)
{
    return code.compare(++currentPos, currentPos + c.length(), c) == 0;
}


std::ostream& operator << (std::ostream& os, tokenType c)
{
    switch (c) {
    case NUM: os << "NUM";    break;
    case ID: os << "ID";    break;
    case WHILE: os << "WHILE";    break;
    case IF: os << "IF";    break;
    case ADD: os << "ADD";    break;
    case SUB: os << "SUB";    break;
    case MUL: os << "MUL";    break;
    case DIV: os << "DIV";    break;
    case SEMI: os << "SEMI";    break;
    case LPR: os << "LPR";    break;
    case RPR: os << "RPR";    break;
    case LBR: os << "LBR";    break;
    case RBR: os << "RBR";    break;
    case LCUR: os << "LCUR";    break;
    case RCUR: os << "RCUR";    break;
    case EOFILE: os << "EOFILE";    break;
    case NEWLINE: os << "NEWLINE";    break;
    default: os.setstate(std::ios_base::failbit);
    }

    return os;
}

bool judge_returnTrue()
{
    return true;
}

int judge_findOpera(string inputLine, int pos) // return the length of the opera
{
    return 1 && (singleOper.find(inputLine[pos], pos) != singleOper.npos)
        + 1 && (multiOper.find(inputLine[pos] + inputLine[pos + 1], pos) != multiOper.npos);
}

int judge_findString(string inputLine, int pos)
{
    if (inputLine[pos] == '\"')
        return findTheFirstNotInString(inputLine, pos, "\"")-pos;
}

bool execute_spiltCodeByString(string inputLine, int & pos, int length)
{
    inputLine.insert(pos + ++length, "^");
    inputLine.insert(pos , "^");

    pos += length;
    return true;
}

bool execute_insertBlank(string inputLine, int & pos, int length)
{
    inputLine.insert(pos + ++length, " "); // if insert at pos at first,it will change the position of the operater
    inputLine.insert(pos, " ");

    pos += length;// 'point' at the blank following the operater after insert blank
    return true;
}

string eachLetterIndex(LINEOFCODE code, int (*judgeFunc)(string inputLine, int judgePos), bool (*executeFunc)(string target, int & TargetPos, int exeLength), int currentPos)
{
    int i = currentPos;
    string tempCode = code.substr(currentPos);

    for (i; i < tempCode.size(); i++)
        if (int length = judgeFunc(tempCode, i))
            executeFunc(tempCode, i, length);
        
    return tempCode;
}