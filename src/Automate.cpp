//
// Created by marca on 16/02/2018.
//

#include "Automate.h"


Automate::~Automate() {

}

void Automate::decalage(Symbole *s, Etat *etat) {
    symbolesStack.push(s);
    etatsStack.push(etat);
}

void Automate::reduction(int n, Symbole *s) {
    for (int i = 0; i < n; ++i) {
        delete (etatsStack.top());
        etatsStack.pop();
    }

    etatsStack.top()->transition(*this, s);
}

void Automate::cancelConsume() {
    lexer->cancelConsume();
}

Symbole *Automate::popSymbol() {
    Symbole *old = symbolesStack.top();
    symbolesStack.pop();
    return old;
}

void Automate::popAndDestroySymbol() {
    delete (symbolesStack.top());
    symbolesStack.pop();
}

bool Automate::next(Symbole *s) {
    Etat *curr = etatsStack.top();
    return curr->transition(*this, s);
}

Automate::Automate(Lexer *l) : lexer(l) {
    etatsStack.push(new E0);
}

