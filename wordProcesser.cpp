#include "wordProcesser.h"


wordProcesser::wordProcesser(LINEOFCODE word):
    value(word)
{
    
    if (word[0] == '\"')
    {
        type = tokenType::STRING;
    }

    if (isdigit(word[0]) )
    {
        type = tokenType::NUM;
    }

    if (word[0] == '_')
    {
        type = tokenType::ID;
    }

    if (word[0] == '\"')
    {
        type = tokenType::STRING;
    }
    if (word[0] == '\"')
    {
        type = tokenType::STRING;
    }
    if (word[0] == '\"')
    {
        type = tokenType::STRING;
    }
    if (word[0] == '\"')
    {
        type = tokenType::STRING;
    }
    if (word[0] == '\"')
    {
        type = tokenType::STRING;
    }
    if (word[0] == '\"')
    {
        type = tokenType::STRING;
    }
    if (word[0] == '\"')
    {
        type = tokenType::STRING;
    }
    if (word[0] == '\"')
    {
        type = tokenType::STRING;
    }


}
