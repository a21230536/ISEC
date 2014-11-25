#include <iostream>
#include <string>
#include "Aviso.h"

using namespace std;

int main()
{
    // (b)
    Prego p(0, 0);
    Aviso a("Aviso A", &p);

    // (c)
    Aviso b("Aviso B", &p);
    Aviso c("Aviso C", p);// (e)
    cout << "> local do Aviso A " << a.local() << endl;
    cout << "> local do Aviso B " << b.local() << endl;
    cout << "> local do Aviso C " << c.local() << endl;
    cout << "> p.mudaDeSitio(3,2);" << endl;
    p.mudaDeSitio(3,2);
    cout << "> local do Aviso A " << a.local() << endl;
    cout << "> local do Aviso B " << b.local() << endl;
    cout << "> local do Aviso C " << c.local() << endl;
    
    // (d)

    return 0;
}
