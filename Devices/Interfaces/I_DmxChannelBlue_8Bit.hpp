#ifndef I_DMXCHANNELBLUE_8BIT_H
#define I_DMXCHANNELBLUE_8BIT_H

#include "stdint.h"
#include <vector>

class I_DmxChannelBlue_8Bit
{
public:
    virtual void SetBlueChnlVal(uint8_t val) = 0;
    //virtual void SetBlueChnlIndx(uint16_t index) = 0;
};

#endif // I_DMXCHANNELBLUE_8BIT_H
