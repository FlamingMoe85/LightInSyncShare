#ifndef ONECHANNELMAPPER_H
#define ONECHANNELMAPPER_H

#include "../../../share/BrokerClientServer/ClientServerBase.hpp"
#include "../../../share/GlobalDefines_Shared.h"

class OneChannelMapper : public ClientServerBase
{
public:
    OneChannelMapper(float &_outVal, float _defaultMax, float _suggested);

    void Consume(int& _itterationCntr, float _pos) override;
    void Request(int& _itterationCntr) override;
    void SetMax(float _max){ if(_max > 0) max = _max;};

private:
    float max;
    float suggested;
    float &outVal;
    int itterration;
};

#endif // ONECHANNELMAPPER_H
