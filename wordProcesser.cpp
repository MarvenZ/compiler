#include "wordProcesser.h"


wordProcesser::wordProcesser(LINEOFCODE word):
    value(word)
{
    if (word[0] == '\"')
    {
        type = tokenType::STRING;
    }

    if (word[0] == ',')
    {
        type = tokenType::COMMA;
    }

    if (isdigit(word[0]) )
    {
        type = tokenType::NUM;
    }

    if (word[0] == '=')
    {
        type = tokenType::ASSI;

        if (word[1] == '=')
            type = tokenType::EQ;
    }

    if (word[0] == '_')
    {
        type = tokenType::ID;
    }

    if (isalpha(word[0]))
    {
        if (letterOper.find(word) != letterOper.end())
            type = letterOper.at(word);
        else
            type = tokenType::ID;
            
    }

    if (word[0] == '<')
    {
        type = tokenType::LET;

        if (word[1] == '=')
            type = tokenType::LEOET;
    }

    if (word[0] == '>')
    {
        type = tokenType::GRT;

        if (word[1] == '=')
            type = tokenType::GROET;
    }

    if (word[0] == '!' && word[1] == '=' )
    {
        type = tokenType::NEQ;
    }
    if (word[0] == '-')
    {
        type = tokenType::SUB;
    }
    if (word[0] == '*')
    {
        type = tokenType::MUL;
    }
    if (word[0] == '/')
    {
        type = tokenType::MUL;
    }
    if (word[0] == ';')
    {
        type = tokenType::SEMI;
    }

    if (word[0] == ':')
    {
        type = tokenType::COL;
    }

    if (word[0] == '(')
    {
        type = tokenType::LCUR;
    }
    if (word[0] == ')')
    {
        type = tokenType::RCUR;
    }
    if (word[0] == '{')
    {
        type = tokenType::LBR;
    }
    if (word[0] == '}')
    {
        type = tokenType::RBR;
    }

}

tokenType wordProcesser::getType()
{
    return type;
}
