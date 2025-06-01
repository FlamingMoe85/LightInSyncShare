#ifndef BASE_CLIENT_H
#define BASE_CLIENT_H

#include "../GlobalDefines_Shared.h"
#include "I_Client.hpp"
#include "I_Server.hpp"

#include <list>
using std::list;

class Base_Client : public I_Client
{
friend class ClientServerBase;
friend class OneChannelMapper;
friend class HandThrough;
friend class HandTroughMapper;
friend class ColorWheelMapper;

public:
    Base_Client();

    virtual void SetServer(I_Server* _brokerRequestable);
    I_Server* GetServer(){return server;}
    virtual void Request(int& _itterationCntr);
    bool HasServer();

private:
    I_Server* server;
    int itterration;

};

#endif // BASE_CLIENT_H
