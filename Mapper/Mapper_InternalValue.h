#ifndef MAPPER_INTERNALVALUE_H
#define MAPPER_INTERNALVALUE_H

#include "stdint.h"
#include "../../../share/BrokerClientServer/ClientServerBase.hpp"
#include "../../../share/GlobalDefines_Shared.h"
//#include "../Functions/FunctionContainer.h"
#include "../FunctionOwners.hpp"
#include <vector>

class Mapper_InternalValue : public ClientServerBase, public FunctionOwners
{
public:
    Mapper_InternalValue(uint8_t &_externalValue, float _defaultMax, float _suggested);

    void Consume(int& _itterationCntr, float _pos) override;
    void Request(int& _itterationCntr) override;
    void SetMax(float _max){ if(_max > 0) max = _max;};

private:
    float max;
    float suggested;
    uint8_t& externalValue;
    int itterration;
};

#endif // MAPPER_INTERNALVALUE_H
