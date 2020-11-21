#pragma once
#include "tools.h"
#include "lineProcesser.h"

class FileProcesser
{
    std::vector <lineProcesser> codeLines;
public:
    FileProcesser(TEXT filePath);
    void printResult();
};

