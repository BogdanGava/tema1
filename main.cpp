#include <iostream>
#include <vector>
#include "caracter.h"
#include "item.h"
#include "npc.h"
using namespace std;
int main()
{
    caracter c1(19, "Gwyn" );
    caracter c2(50, "Gwyndolyn");
    item i1("Claymore", 35.6, 8);
    item i2("Saw",35, 12 );
    npc n1("Ex", 18, 1);
    npc n2("Ex2", 20,0);
    n1.interactioneaza(c1, i1);
    n2.interactioneaza(c1, i1);
//    i1.afisare();
//    i2.afisare();
//    c1.adauga(i1);
//    c1.adauga(i2);
//    c1.elimina(i2);
//    c2.adauga(i1);
//    c2.adauga(i1);
//    cout<<i1;
//    cout<<i2;
    cout<<n1;
    cout<<c1;
//    cout<<c2;
    return 0;
}
