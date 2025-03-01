#ifndef I_DMXCHANNELTILT_8BIT_H
#define I_DMXCHANNELTILT_8BIT_H


#include "stdint.h"
#include <vector>

class I_DmxChannelTilt_8Bit
{
public:
    virtual void SetTiltChnlVal(uint8_t val) = 0;
};

#endif // I_DMXCHANNELTILT_8BIT_H
