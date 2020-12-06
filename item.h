#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED
#include<iostream>
#include<vector>
class caracter;
class item
{
    std::string nume_item;
    float greutate;
    int level_required;
    friend class caracter;


public:
    void afisare()
    {
        std::cout<<nume_item<<" "<<greutate<<" "<<level_required<<'\n';
    }
    item(std::string nume_item="none", float greutate=0, int level_required=0);
    friend std::ostream& operator<<(std::ostream&,item&);
    ~item();
};

#endif // ITEM_H_INCLUDED

