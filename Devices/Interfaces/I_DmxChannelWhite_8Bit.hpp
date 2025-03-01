#ifndef I_DMXCHANNELWHITE_8BIT_H
#define I_DMXCHANNELWHITE_8BIT_H

#include "stdint.h"
#include <vector>

class I_DmxChannelWhite_8Bit
{
public:
    virtual void SetWhiteChnlVal(uint8_t val) = 0;
    //virtual void SetWhiteChnlIndx(uint16_t index) = 0;
};

#endif // I_DMXCHANNELWHITE_8BIT_H
