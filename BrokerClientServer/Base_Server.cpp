#include "Base_Server.h"

Base_Server::Base_Server()
{
    itterration = 0;
}

void Base_Server::RegisterClient(I_Client* c)
{
    /*
    if(c != (I_Client*)this)
    {
        */
        clients.push_back(c);
        c->SetServer(this);

}

void Base_Server::Serve(int& _itterration, float pos)
{
    if(itterration != _itterration)
    {
        //Calculate(pos);
        for(I_Client* c : clients)
        {
            c->Consume(_itterration, pos);
        }
    }
    itterration = _itterration;
}

void Base_Server::Calculate(rangePosition_t& _pos)
{

}

list<I_Client *> *Base_Server::GetClientList()
{
    return &clients;
}
