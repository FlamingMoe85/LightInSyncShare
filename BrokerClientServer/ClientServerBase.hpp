#ifndef CLIENTSERVERBASE_HPP
#define CLIENTSERVERBASE_HPP


#include "../GlobalDefines_Shared.h"
#include <list>
using namespace std;

#include "Base_Client.h"
#include "Base_Server.h"

class ClientServerBase : public Base_Server, public Base_Client
{
public:
    ClientServerBase();

    void GetRequested(int& _itterationCntr);

private:
};

#endif // CLIENTSERVERBASE_HPP
