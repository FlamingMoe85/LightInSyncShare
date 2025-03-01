#ifndef EFFECTCOMPONENT_H
#define EFFECTCOMPONENT_H

#include "../BrokerClientServer/ClientServerBase.hpp"
#include "../Functions/FunctionContainer.h"

class EffectComponent : public ClientServerBase
{
public:
    EffectComponent();

    FunctionContainer& GetFuncContainer(){return functContainer;}
    void Consume(int& _itterationCntr, float _pos);

private:
    FunctionContainer functContainer;
};

#endif // EFFECTCOMPONENT_H
