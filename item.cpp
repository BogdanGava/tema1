#include<iostream>
#include "item.h"
#include "caracter.h"
#include<vector>
item::item(std::string nume_item, float greutate, int level_required)
{
    this->nume_item=nume_item;
    this->greutate=greutate;
    this->level_required=level_required;
}
std::ostream & operator<<(std::ostream& os, item& i)
{

    os<<"nume item="<<i.nume_item<<'\n'<<"greutate="<<i.greutate<<" "<<i.level_required<<std::endl;
    return os;
}
item::~item()
{
    std::cout<<"Dropped"<<'\n';
}

