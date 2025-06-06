#ifndef I_CLIENT_HPP
#define I_CLIENT_HPP

#include <string>
using namespace std;

#include "../GlobalDefines_Shared.h"
class I_Server;

class I_Client
{
public:
    virtual void SetServer(I_Server* _brokerRequestable)=0;
    virtual void Request(int& _itterationCntr)=0;
    virtual void Consume(int& _itterationCntr, float _pos)=0;
    virtual bool HasServer() = 0;
};

#endif // I_CLIENT_HPP
