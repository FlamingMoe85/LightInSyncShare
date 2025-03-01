#ifndef HANDTROUGHMAPPER_H
#define HANDTROUGHMAPPER_H

#include "stdint.h"
#include "../../../share/BrokerClientServer/ClientServerBase.hpp"
#include "../../../share/GlobalDefines_Shared.h"
#include <vector>

class HandTroughMapper : public ClientServerBase
{
public:
    HandTroughMapper(std::vector<uint8_t*>& _universum, float _defaultMax, float _suggested);

    void Consume(int& _itterationCntr, float _pos) override;
    void Request(int& _itterationCntr) override;
    void SetMax(float _max){ if(_max > 0) max = _max;};
    void SetIndex(int _index){index = _index;}

private:
    float max;
    float suggested;
    std::vector<uint8_t*>& universum;
    int itterration;
    int index;
};

#endif // HANDTROUGHMAPPER_H
