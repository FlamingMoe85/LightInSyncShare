#ifndef MAPPER_CHANNEL_H
#define MAPPER_CHANNEL_H


#include "stdint.h"
#include "../../../share/BrokerClientServer/ClientServerBase.hpp"
#include "../../../share/GlobalDefines_Shared.h"
//#include "../Functions/FunctionContainer.h"
#include "../FunctionOwners.hpp"
#include "../Devices/Interfaces/I_Channel_8Bit.hpp"
#include <vector>

class Mapper_Channel : public ClientServerBase, public FunctionOwners
{
public:
    Mapper_Channel(I_Channel_8Bit& _dev, float _defaultMax, float _suggested);

    void Consume(int& _itterationCntr, float _pos) override;
    void Request(int& _itterationCntr) override;
    void SetMax(float _max){ if(_max > 0) max = _max;};

private:
    float max;
    float suggested;
    I_Channel_8Bit& dev;
    int itterration;
};

#endif // MAPPER_CHANNEL_H
