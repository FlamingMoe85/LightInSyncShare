#include "Positioner.h"

Positioner::Positioner()
{
    itterration = 0;
}

void Positioner::Consume(int& _itterationCntr, float _pos)
{
    Serve(_itterationCntr, _pos);
}

void Positioner::Serve(int& _itterration, float pos)
{
    list<I_Client*>* clients = GetClientList();
    if(itterration != _itterration)
    {
        for(I_Client* c : (*clients))
        {
            c->Consume(_itterration, GetFuncCont()->Calc(pos));
        }
    }
    itterration = _itterration;
}
