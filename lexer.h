#pragma once

#include <string>
#include "symbole.h"

using namespace std;

class Lexer {

public:
    Lexer(string s) : flux(s), tete(0), tampon(nullptr), nonTerminal(nullptr) {}

    ~Lexer() {}

    Symbole *Consulter();
    void Avancer();

    void cancelConsume();
protected:
    string flux;
    int tete;
    Symbole *tampon;
    Symbole* nonTerminal;
    bool isConsumed;
};
