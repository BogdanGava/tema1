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
        cout<<nume_item<<" "<<greutate<<'\n';
    }
    item(std::string nume_item="none", float greutate=0);
    ~item();
};

item::item(std::string nume_item, float greutate)
{
    this->nume_item=nume_item;
    this->greutate=greutate;
}

item::~item()
{
    cout<<"Dropped"<<'\n';
}

class caracter
{
    vector<item> inventar;
    int level;
    string nume_caracter, movement;
    friend class item;

public:
    void adauga(item &item)
    {
        inventar.push_back(item);
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
        std::cout<<level<<" "<<" "<<nume_caracter<<" "<<movement<<'\n';
    }

    caracter(int level=1, std::string nume_caracter="none", std::string movement="normal" );
    caracter(caracter &);
    caracter &operator =(const caracter &caracter);
    ~caracter();
};

caracter::caracter( int level, std::string nume_caracter, std::string movement)
{
    this->level=level;
    this->nume_caracter=nume_caracter;
    this->movement=movement;
}

caracter::caracter(caracter &caracter)
{
    this->level=caracter.level;
    this->nume_caracter=caracter.nume_caracter;
    this->movement=caracter.movement;
}

caracter & caracter::operator=(const caracter &caracter)
{
    level=caracter.level;
    nume_caracter=caracter.nume_caracter;
    movement=caracter.movement;
    return *this;
}

caracter::~caracter()
{
    cout<<"You will not be remembered"<<'\n';

}

int main()
{
    caracter c1(12, "Gwyn", "impaired");
    c1.afisare();
    caracter c2(50, "Gwyndolyn", "normal");
    c2.afisare();
    item i1("Claymore", 25.6);
    i1.afisare();


    return 0;
}
// scuze pentru romgleza
