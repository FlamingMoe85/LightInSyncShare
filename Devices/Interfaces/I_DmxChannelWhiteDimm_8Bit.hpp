#ifndef I_DMXCHANNELWHITEDIMM_8BIT_HPP
#define I_DMXCHANNELWHITEDIMM_8BIT_HPP

#include "stdint.h"
#include <vector>

class I_DmxChannelWhiteDimm_8Bit
{
public:
    virtual void SetWhiteDimmChnlVal(uint8_t val) = 0;
    //virtual void SetWhiteChnlIndx(uint16_t index) = 0;
};
#endif // I_DMXCHANNELWHITEDIMM_8BIT_HPP
