#ifndef I_SERVER_HPP
#define I_SERVER_HPP

#include "../GlobalDefines_Shared.h"
#include <list>
using std::list;

class I_Client;

class I_Server
{
public:
    virtual void RegisterClient(I_Client* _brokerServeable) = 0;
    virtual void GetRequested(int& _itterationCntr)=0;
    virtual void Serve(int& _itterration, float pos) = 0;
    virtual list<I_Client*>* GetClientList() = 0;
};

#endif // I_SERVER_HPP
