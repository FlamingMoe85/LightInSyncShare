#ifndef I_DMXCHANNELDIMM_8BIT_H
#define I_DMXCHANNELDIMM_8BIT_H


#include "stdint.h"
#include <vector>

class I_DmxChannelDimm_8Bit
{
public:
    virtual void SetDimmChnlVal(uint8_t val) = 0;
    //virtual void SetWhiteChnlIndx(uint16_t index) = 0;
};

#endif // I_DMXCHANNELDIMM_8BIT_H
