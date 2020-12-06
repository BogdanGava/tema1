#include<iostream>
#include "item.h"
#include "caracter.h"
#include<vector>
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
std::ostream & operator<<(std::ostream& os, caracter& c)
{

    os<<"movement="<<c.calculare_movement()<<'\n'<<"level="<<c.level<<'\n'<<"nume_caracter="<<c.nume_caracter<<std::endl;
    return os;
}
caracter::~caracter()
{
    std::cout<<"You will not be remembered"<<'\n';

}
