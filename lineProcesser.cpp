#include "lineProcesser.h"

lineProcesser::lineProcesser(LINEOFCODE code)
{
    indentNum = code.find_first_not_of(' ');
    string line = trim(code);
    
    if (!hasString(line))
    {
        formattedCode = eachLetterIndex(code, judge_findOpera, execute_insertBlank);
        formattedCode.pop_back(); // remove the '\n' at the end of the line

        std::stringstream streamCode(formattedCode);
        string word;

        while (streamCode >> word)
            words.push_back(wordProcesser(word));
    }
    else
    {
        std::vector <string > saparatedCode(3);
        string tempCode = eachLetterIndex(code, judge_findString, execute_spiltCodeByString);

        int markPos;
        while (markPos = tempCode.find_first_of('^'))
        {
            saparatedCode.push_back(tempCode.substr(0, markPos));
            saparatedCode.push_back(tempCode.substr(markPos+1, tempCode.find_first_of('^',markPos+1)));
            tempCode = tempCode.substr(tempCode.find_first_of('^', markPos + 1));
        }

        for (auto str : saparatedCode)
        {
            formattedCode += str;

            if (str[0] == '\"')
                continue;

            std::stringstream streamCode(str);
            string word;

            while (streamCode >> word)
                words.push_back(wordProcesser(word));
        }

    }

    

}

void lineProcesser::printList(int numOfLine)
{
    if (indentNum != 0)
        std::cout << numOfLine << " INDENT" << std::endl;

    for (auto word : words)
        std::cout << word.getType() << std::endl;
}
