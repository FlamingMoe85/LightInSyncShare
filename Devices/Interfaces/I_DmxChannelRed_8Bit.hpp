#ifndef I_DMXCHANNELRED_8BIT_H
#define I_DMXCHANNELRED_8BIT_H

#include "stdint.h"
#include <vector>

class I_DmxChannelRed_8Bit
{
public:
    virtual void SetRedChnlVal(uint8_t val) = 0;
    //virtual void SetRedChnlIndx(uint16_t index) = 0;
};

#endif // I_DMXCHANNELRED_8BIT_H
