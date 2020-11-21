#include "FileProcesser.h"

typedef std::ifstream pymFile;

FileProcesser::FileProcesser(TEXT filePath )
{
    pymFile sourseFile("code.pym",std::ios::in);

    string eachLine;

    if (sourseFile)
    {
        string code;

        while(getline(sourseFile,code))
        {           
            for (auto letter : code+='\n')
            {
                eachLine += letter;
                if (letter == '\n' && !IsContextOfAStirng(eachLine, eachLine.size() - 1))
                {
                    codeLines.push_back(lineProcesser(eachLine));
                    eachLine = "";
                }
            }
            

        }

    }

}

void FileProcesser::printResult()
{
    int numOfLine = 0;

    for (auto line : codeLines)
        line.printList(++numOfLine);
}

/*

eachLine += letter;
                if (letter == '\n' && !IsContextOfAStirng(eachLine, eachLine.size() - 1))
                {
                    codeLines.push_back(lineProcesser(eachLine));
                    eachLine = "";
                }

*/