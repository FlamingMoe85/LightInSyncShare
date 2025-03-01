#include "BrokerBase.hpp"
#include "ClientServerBase.hpp"

/*
 *  This class forms a standard Broker connecting Clients and Servers.
 *  Request(...) only throughputs requests for values from Clients to Servers.
 *  Serve(...) collects all value inputs from connected Servers before notifying
 *  the connected clients.
 */

BrokerBase::BrokerBase()
{
    serverCntr = 0;
    curItterration = 0;
}

void BrokerBase::RegisterServer(ClientServerBase* _server)
{
    serverList.push_back(_server);
    _server->RegisterBrokerServeable(this);
}


void BrokerBase::Request(int& itterration)
{
    if(curItterration != itterration)
    {
        curItterration = itterration;
        serverCntr = 0;
        for(ClientServerBase* server : serverList)
        {
            server->Receive(itterration);
        }
    }
    else
    {
        pos = 0;
    }
}

void BrokerBase::RegisterClient(ClientServerBase* _client)
{
    clientList.push_back(_client);
    _client->RegisterBrokerRequestable(this);
}

void BrokerBase::Serve(int& itterration, float _pos)
{
    serverCntr++;
    pos += _pos;
    if(serverCntr == serverList.size())
    {
        serverCntr = 0;
        if(pos > 1.0) pos = 1.0;

        for(ClientServerBase* client : clientList)
        {
            client->Consume(itterration, _pos);
        }
    }
}
