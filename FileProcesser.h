#pragma once
#include "lineProcesser.h"

class FileProcesser
{
    std::vector <lineProcesser> codeLines;
public:
    FileProcesser(TEXT filePath);
    void printResult();
};

