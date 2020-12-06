#include<iostream>
#include "item.h"
#include "caracter.h"
#include "npc.h"
npc::npc(std::string nume_npc, int level_npc, int hostility)
{
    this->nume_npc=nume_npc;
    this->level_npc=level_npc;
    this->hostility=hostility;
}
std::ostream & operator<<(std::ostream& os, npc& n)
{

    os<<"nume_npc="<<n.nume_npc<<'\n'<<"level npc="<<n.level_npc<<'\n'<<"hostility="<<n.hostility<<std::endl;
    return os;
}
npc::~npc()
{
    std::cout<<"Dropped"<<'\n';
}

