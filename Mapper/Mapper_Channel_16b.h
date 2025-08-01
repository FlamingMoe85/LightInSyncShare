#ifndef MAPPER_CHANNEL_16B_H
#define MAPPER_CHANNEL_16B_H


#include "stdint.h"
#include "Mapper_Base.hpp"
//#include "../Functions/FunctionContainer.h"
#include "../Devices/Interfaces/I_Channel_16Bit.hpp"
#include <vector>

class Mapper_Channel_16b : public Mapper_Base
{
public:
    Mapper_Channel_16b(I_Channel_16Bit& _dev, float _defaultMax, float _suggested);

    void Consume(int& _itterationCntr, float _pos) override;
    void Request(int& _itterationCntr) override;
    void SetMax(float _max){ if(_max > 0) max = _max;};

private:
    float max;
    float suggested;
    I_Channel_16Bit& dev;
    int itterration;
};

#endif // MAPPER_CHANNEL_H
