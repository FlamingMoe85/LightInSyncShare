#include "Base_Client.h"
#include "I_Server.hpp"

Base_Client::Base_Client()
{
    itterration = 0;
    server = 0;
}

void Base_Client::SetServer(I_Server *s)
{
    /*
    if(s != (I_Server*)this)
    {}
    */
        server = s;
        //s->RegisterClient(this);

}

bool Base_Client::HasServer()
{
    if(server != 0)return true;
    return false;
}

void Base_Client::Request(int& _itterationCntr)
{
    if((itterration != _itterationCntr) && (server != 0))
    {
        server->GetRequested(_itterationCntr);
    }
    itterration = _itterationCntr;
}

