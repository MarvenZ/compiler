#pragma once
#include "wordProcesser.h"

#include <sstream>

class lineProcesser
{
    int indentNum;
    string formattedCode;
    std::vector <wordProcesser > words;

public:
    lineProcesser( LINEOFCODE code);
    void printList(int numOfLine );
};

