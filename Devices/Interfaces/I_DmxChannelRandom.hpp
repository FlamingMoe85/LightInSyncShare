#ifndef I_DMXCHANNELRANDOM_HPP
#define I_DMXCHANNELRANDOM_HPP

#include "stdint.h"

class I_DmxChannelRandom
{
public:
    virtual void SetRandomChnlVal(uint8_t val, uint16_t channel) = 0;
};

#endif // I_DMXCHANNELRANDOM_HPP
