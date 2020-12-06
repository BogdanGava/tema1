#ifndef CARACTER_H_INCLUDED
#define CARACTER_H_INCLUDED
#include<iostream>
#include "item.h"
#include <vector>
class item;
class npc;
class caracter
{
    std::vector<item> inventar;
    std::string nume_caracter;
    float const g=70;
    friend class item;
    friend class npc;
    std::string calculare_movement()
    {
        std::string movement;
        float greutate_totala=0;
        for(unsigned int i=0; i<inventar.size(); ++i)
            greutate_totala=greutate_totala+inventar[i].greutate;
        if(greutate_totala>g)
            movement="impaired";
        else
            movement="normal";
        return movement;
    }
protected:
    int level;
public:
    void adauga(item &item)
    {
        try
        {
            if(item.level_required<=level)
                inventar.push_back(item);
            else if(item.level_required>level)
                throw 404;
        }
        catch(...)
        {
            std::cout<<"Caracterul nu are level suficient de mare"<<" "<<item.level_required<<std::endl;
        }

    }
    void elimina (item &item)
    {
        for (unsigned int i=0; i<inventar.size(); ++i)
            if (inventar[i].nume_item==item.nume_item)
                inventar.erase(inventar.begin()+i-1);
    }
    void level_up (caracter &c)
    {
        ++c.level;
    }
    void afisare()
    {
        std::cout<<level<<" "<<" "<<nume_caracter<<'\n';
    }
    friend std::ostream& operator<<(std::ostream&,caracter&);

    caracter(int level=1, std::string nume_caracter="none" );
    caracter(caracter &);
    caracter &operator =(const caracter &caracter);
    ~caracter();
};

#endif // CARACTER_H_INCLUDED
