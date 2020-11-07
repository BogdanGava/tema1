#include <iostream>
#include <vector>
// dark souls = joc rpg in care greutatea inventarului determina orice forma de miscare
using namespace std;
class item
{
    string nume_item;
    float greutate;
    friend class caracter;
public:
    void afisare()
    {
        std::cout<<nume_item<<" "<<greutate<<'\n';
    }

};

class caracter
{
    vector<item> inventar;
    int level;
    float greutate; // dupa ce trece de 70, va scadea viteza pentru orice fel de movement
    string nume_caracter, movement;
    friend class item;
public:
        void adaugare(item item1)
    {
        inventar.push_back(item1);
    }

    void calculare_movement()
    {
        int greutate_totala=0;
        for(int i=0; i<inventar.size(); ++i)
            greutate_totala=greutate_totala+inventar[i].greutate;
        if(greutate_totala>70)
            movement="impaired";
        else
            movement="normal";
    }

    void afisare()
    {
        std::cout<<level<<" "<<greutate<<" "<<nume_caracter<<" "<<movement<<'\n';
    }
    caracter(int level=1, float greutate=0, std::string nume_caracter="none", std::string movement="normal" );
    caracter(caracter &);
    ~caracter();
};
caracter::caracter( int level, float greutate, std::string nume_caracter, std::string movement)
    {
        this->level=level;
        this->greutate=greutate;
        this->nume_caracter=nume_caracter;
        this->movement=movement;
    }
caracter::caracter(caracter &ch)
    {
        this->level=ch.level;
        this->greutate=ch.greutate;
        this->nume_caracter=ch.nume_caracter;
        this->movement=ch.movement;
    }
caracter::~caracter()
{
    cout<<"You will not be remembered"<<'\n';

}
int main()
{
    caracter c1(12, 15.5, "Gwyn", "normal");
    c1.afisare();
    caracter c2(50, 90, "Gwyndolyn", "impaired");
    c2.afisare();


    return 0;
}
