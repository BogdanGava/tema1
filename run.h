#ifndef RUN_H_INCLUDED
#define RUN_H_INCLUDED
#include <iostream>
class run
{
    private:
    run() = default;
    static run* r;
public:
    void runn ()
    {
    caracter c1;
    caracter c2;
    npc n1;
    item i1;
    item i2;
    }
    run(const run&) = delete;
    run& operator=(const run&) = delete;
    static run* get_r() {
        if(r == nullptr) { r = new run; }
        return r;
    }
};

run* run::r = nullptr;

#endif // RUN_H_INCLUDED
