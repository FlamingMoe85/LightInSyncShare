#ifndef EFFECTCOMPONENTBUNDLE_H
#define EFFECTCOMPONENTBUNDLE_H

#include "../BrokerClientServer/ClientServerBase.hpp"

class ComponentBundle : public ClientServerBase
{
public:
    ComponentBundle();

    void Consume(int& _itterationCntr, float _pos) override;

};

#endif // EFFECTCOMPONENTBUNDLE_H
