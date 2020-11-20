#pragma once
#include "tools.h"
#include "lineProcesser.h"

class FileProcesser
{
    FileProcesser(TEXT filePath);
    std::vector <lineProcesser> codeLines;
};

