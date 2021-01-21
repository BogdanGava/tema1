#include <iostream>
#include <vector>
#include "caracter.h"
#include "item.h"
#include "npc.h"
#include "run.h"
using namespace std;

int main()
{
    caracter c1(19, "Gwyn" );
    caracter c2(50, "Gwyndolyn");
    item i1("Claymore", 35.6, 8);
    item i2("Saw",35, 12 );
    npc n1("Ex", 18, 1);
    n1.adauga(i1);
    n1.adauga(i2);
    n1.interactioneaza(c1, i1);
    auto x = run::get_r();
    x->runn ();
    cout<<c1;
////    i1.afisare();
////    i2.afisare();
////    c1.adauga(i1);
////    c1.adauga(i2);
////    c1.elimina(i2);
////    c2.adauga(i1);
////    c2.adauga(i1);
////    cout<<i1;
////    cout<<i2;
////    cout<<n1;
//    cout<<c1;
////    cout<<c2;
//    /* caracterul 1 are level 19 si nu are niciun item in inventar.
//     Acesta va interactiona cu npc 1 ce are 2 iteme, din moment ce npc-ul este ostil, iar caracterul are level mai mare va
//     face level up si va obtine cele 2 iteme, ce ii vor face movement-ul impaired. */
    return 0;
}
