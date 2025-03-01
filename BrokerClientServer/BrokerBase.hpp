#ifndef BROKERBASE_HPP
#define BROKERBASE_HPP



#include <list>
using namespace std;
class ClientServerBase;


class BrokerBase //: public BrokerRequestable, public BrokerServable
{
public:
    BrokerBase();

    void RegisterServer(ClientServerBase* _server);
    void Serve(int& itterration, float _pos);

    void RegisterClient(ClientServerBase* _client);
    void Request(int& itterration);

private:
    list<ClientServerBase*> serverList;
    list<ClientServerBase*> clientList;

    unsigned int serverCntr;
    int curItterration;

    float pos;
};

#endif // BROKERBASE_HPP
