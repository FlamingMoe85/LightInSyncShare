#ifndef I_DMXCHANNELPAN_8BIT_H
#define I_DMXCHANNELPAN_8BIT_H

#include "stdint.h"
#include <vector>

class I_DmxChannelPan_8Bit
{
public:
    virtual void SetPanChnlVal(uint8_t val) = 0;
};

#endif // I_DMXCHANNELPAN_8BIT_H
