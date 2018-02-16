//
// Created by marca on 16/02/2018.
//

#ifndef LEXER_AUTOMATE_H
#define LEXER_AUTOMATE_H

#include <stack>
#include "symbole.h"
#include "Etat.h"
#include "lexer.h"

using std::stack;

class Etat;

class Automate {

private:
    stack<Symbole *> symbolesStack;
    stack<Etat *> etatsStack;
    Lexer *lexer;

public:
    Automate(Lexer *l);

    virtual ~Automate();

    void decalage(Symbole *s, Etat *etat);
    void reduction(int n, Symbole *s);


    void cancelConsume();
    Symbole * popSymbol();

    void popAndDestroySymbol();

    bool next(Symbole *s);
};


#endif //LEXER_AUTOMATE_H
