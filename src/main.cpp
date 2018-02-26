#include <iostream>
#include "lexer.h"
#include "Automate.h"


int main() {
    string chaine("(5*2+3)*5+2");

    Lexer l(chaine);
    Automate automate(&l);

    Symbole *s = l.Consulter();

    while (!automate.next(s)) {
        s->Affiche();
        cout << endl;
        l.Avancer();
        s = l.Consulter();
    }
    cout << "Value = " << ((Expr *) automate.popSymbol())->getValue() << std::endl;
    return 0;
}

