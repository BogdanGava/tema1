#include <iostream>
#include <vector>
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
    friend ostream& operator<<(ostream&,item&);
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
    string nume_caracter;
    float const g=70;
    friend class item;
    string calculare_movement()
    {
        string movement;
        float greutate_totala=0;
        for(int i=0; i<inventar.size(); ++i)
            greutate_totala=greutate_totala+inventar[i].greutate;
        if(greutate_totala>g)
            movement="impaired";
        else
            movement="normal";
        return movement;
    }
public:
    void adauga(item &item)
    {
        inventar.push_back(item);
    }
    void elimina (item &item)
    {
        for (int i=0; i<inventar.size(); ++i)
            if (inventar[i].nume_item==item.nume_item)
                inventar.erase(inventar.begin()+i-1);
    }

    void afisare()
    {
        std::cout<<level<<" "<<" "<<nume_caracter<<'\n';
    }
    friend ostream& operator<<(ostream&,caracter&);

    caracter(int level=1, std::string nume_caracter="none" );
    caracter(caracter &);
    caracter &operator =(const caracter &caracter);
    ~caracter();
};
std::ostream & operator<<(ostream& os, item& i)
{

    os<<"nume item="<<i.nume_item<<'\n'<<"greutate="<<i.greutate<<endl;
    return os;
}
caracter::caracter( int level, std::string nume_caracter)
{
    this->level=level;
    this->nume_caracter=nume_caracter;
}

caracter::caracter(caracter &caracter)
{
    this->level=caracter.level;
    this->nume_caracter=caracter.nume_caracter;
}

caracter & caracter::operator=(const caracter &caracter)
{
    level=caracter.level;
    nume_caracter=caracter.nume_caracter;
    return *this;
}
std::ostream & operator<<(ostream& os, caracter& c)
{

    os<<"movement="<<c.calculare_movement()<<'\n'<<"level="<<c.level<<'\n'<<"nume_caracter="<<c.nume_caracter<<endl;
    return os;
}
caracter::~caracter()
{
    cout<<"You will not be remembered"<<'\n';

}

int main()
{
    caracter c1(12, "Gwyn" );
    caracter c2(50, "Gwyndolyn");
    item i1("Claymore", 35.6);
    item i2("Saw",35 );
    i1.afisare();
    i2.afisare();
    c1.adauga(i1);
    c1.adauga(i2);
    c1.elimina(i2);
    c2.adauga(i1);
    c2.adauga(i1);
    cout<<i1;
    cout<<i2;
    cout<<c1;
    cout<<c2;
    return 0;
}
