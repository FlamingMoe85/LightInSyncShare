#ifndef I_CHANNEL_8BIT_HPP
#define I_CHANNEL_8BIT_HPP

#include "stdint.h"

class I_Channel_8Bit
{
public:
    virtual void SetChnlVal(uint8_t _val) = 0;
};

#endif // I_CHANNEL_8BIT_HPP
