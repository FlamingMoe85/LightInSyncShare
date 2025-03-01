#ifndef BASE_SERVER_H
#define BASE_SERVER_H

#include "../GlobalDefines_Shared.h"
#include "I_Client.hpp"
#include "I_Server.hpp"

#include <list>
using std::list;

class Base_Server : public I_Server
{
friend class ClientServerBase;

public:
    Base_Server();

    void RegisterClient(I_Client* _brokerServeable);
    void Serve(int& _itterration, float pos);
    list<I_Client*>* GetClientList();

private:
    list<I_Client*> clients;
    int itterration;

    virtual void Calculate(rangePosition_t& _pos);
};

#endif // BASE_SERVER_H
