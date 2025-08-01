#ifndef I_CHANNEL_16BIT_HPP
#define I_CHANNEL_16BIT_HPP

#include "stdint.h"

class I_Channel_16Bit
{
public:
    virtual void SetChnlVal(uint16_t _val) = 0;
};

#endif // I_CHANNEL_8BIT_HPP
