#ifndef CHANNEL_16BIT_HPP
#define CHANNEL_16BIT_HPP

#include <vector>
#include "stdint.h"
#include "../Interfaces/I_Channel_16Bit.hpp"

class Channel_16Bit : public I_Channel_16Bit
{
public:
    Channel_16Bit(std::vector<uint8_t*>& _universum) : universum(_universum)
    {
        channel = 0;
    }

    void SetChnlVal(uint16_t _val) override
    {
        *(universum[channel]) = _val >>8;
        *(universum[channel+1]) = _val ;
    }

    void SetChannel(unsigned int _channel){channel = _channel;}

private:
    std::vector<uint8_t*>& universum;
    unsigned int channel;
};
#endif // CHANNEL_8BIT_HPP
