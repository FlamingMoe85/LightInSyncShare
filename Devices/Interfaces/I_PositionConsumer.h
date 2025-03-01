#ifndef I_POSITIONCONSUMER_H
#define I_POSITIONCONSUMER_H


#include <vector>
#include <stdint.h>

class I_PositionConsumer
{
public:
    virtual void SetPosition(float pos, std::vector<uint8_t*>& universum) = 0;
    //virtual void SetDimm(float _dimm) = 0;
};

#endif // I_POSITIONCONSUMER_H
