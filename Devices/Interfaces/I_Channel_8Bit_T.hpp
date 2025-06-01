#ifndef I_CHANNEL_8BIT_T_H
#define I_CHANNEL_8BIT_T_H

#include "stdint.h"

template <class T> class I_Channel_8Bit_T
{
public:
    virtual void SetChnlVal(T _val) = 0;
};

#endif // I_CHANNEL_8BIT_T_H
