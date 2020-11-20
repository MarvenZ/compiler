#include "FileProcesser.h"

typedef std::ifstream pymFile;

FileProcesser::FileProcesser(TEXT filePath = "code.pym")
{
    pymFile sourseFile("code.pym",std::ios::in);

    string eachLine;

    if (sourseFile)
    {
        char letter;

        while(sourseFile >> letter)
        {           
            eachLine += letter;
            if (letter == '\n' && !IsContextOfAStirng(eachLine, eachLine.size()))
            {
                codeLines.push_back(lineProcesser(eachLine));
                eachLine = "";
            }

        }

    }

}
