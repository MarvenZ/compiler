#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

typedef const std::string& LINEOFCODE, TEXT;
typedef std::string string;
typedef enum tp
{
    LEOET,
    GROET,
    ASSI,
    NUM,
    ID,
    STRING,
    WHILE,
    IF,
    ELIF,
    RETURN,
    DEF,
    ADD,
    SUB,
    MUL,
    DIV,
    SEMI,
    LPR,
    RPR,
    LBR,
    RBR,
    LCUR,
    RCUR,
    EOFILE,
    NEWLINE,
    AND,
    OR,
    NOT,
    COL,
    LET,
    GRT,
    NEQ,
    EQ,
    COMMA
}tokenType;


const TEXT singleOper = "+-*/%><()[]:,;=!"; // '!' is not an operator
const TEXT multiOper = "==>=<=!=";
const std::map <string, tokenType> letterOper = 
{ 
    {"and",tokenType::AND},
    {"or",tokenType::OR },
    {"not",tokenType::NOT},
    {"while",tokenType::WHILE},
    {"if",tokenType::IF},
    {"elif", tokenType::ELIF},
    {"return", tokenType::RETURN},
    {"def", tokenType::DEF}
}; //those operaters can't be indented arbitrarily



bool nextIs(LINEOFCODE code, int currentPos, char c);

bool nextIs(LINEOFCODE code, int currentPos, TEXT c);

std::ostream& operator << (std::ostream& os, tokenType c);

//check wether the letter is the context of a string or not
bool IsContextOfAStirng(LINEOFCODE line, int nLetterPos);
// input(  the string, the position of that letter )
//output : if in, then true, if out, then false


// erase the empty letter at the bgin of and at the end of this line
string trim(LINEOFCODE line);
// input ( the string tobe executed)
// output the result string


// check wether a line of code contents a string
bool hasString(LINEOFCODE line);
// input (a line of code)
//output does it has string or not


//insidely indent a line of code
string codeFormatting(LINEOFCODE line);
//input a line of code
//output the indented line of code

bool judge_returnTrue();

int judge_findOpera(string inputLine, int pos); // return the length of the opera

bool execute_insertBlank(string & inputLine, int & pos, int length);

bool execute_spiltCodeByString(string & inputLine, int & pos, int length);

int judge_findString(string inputLine, int pos);

string eachLetterIndex(LINEOFCODE code, int (*judgeFunc)(string inputLine, int judgePos), bool (*executeFunc)(string & target, int & TargetPos, int exeLength), int currentPos = 0);