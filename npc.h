#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED
#include<iostream>
#include<vector>
class npc : public caracter
{
    friend class item;
    std::vector<item>inventar;
    int level_npc, hostility; //0 = friendly; 1 = ostil;
    std::string nume_npc;
public:
    void interactioneaza (caracter &c, item &item)
    {
        try
        {
            if(hostility==1 && c.level>=level_npc)
            {
                level_up(c);
                c.adauga(item);
                elimina(item);
            }
            else if(hostility==1 && c.level<level_npc)
                throw 99;
        }
        catch (...)
        {
            std::cout<<"You Died"<<std::endl;
        }
    }
    void afisare()
    {
        std::cout<<nume_npc<<" "<<level_npc<<" "<<hostility<<'\n';
    }
    npc(std::string nume_npc="none", int level_npc=0, int hostility=0);
    friend std::ostream& operator<<(std::ostream&,npc&);
    ~npc();
};


#endif // NPC_H_INCLUDED
