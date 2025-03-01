#ifndef I_DMXCHANNELGREEN_8BIT_H
#define I_DMXCHANNELGREEN_8BIT_H

#include "stdint.h"
#include <vector>

class I_DmxChannelGreen_8Bit
{
public:
    virtual void SetGreenChnlVal(uint8_t val) = 0;
    //virtual void SetGreenChnlIndx(uint16_t index) = 0;
};

#endif // I_DMXCHANNELGREEN_8BIT_H
