#ifndef CHANNEL_8BIT_HPP
#define CHANNEL_8BIT_HPP

#include <vector>
#include "stdint.h"
#include "../Interfaces/I_Channel_8Bit.hpp"

class Channel_8Bit : public I_Channel_8Bit
{
public:
    Channel_8Bit(std::vector<uint8_t*>& _universum) : universum(_universum)
    {
        channel = 0;
    }

    void SetChnlVal(uint8_t _val) override
    {
        *(universum[channel]) = (uint8_t)_val;
    }

    void SetChannel(unsigned int _channel){channel = _channel;}

private:
    std::vector<uint8_t*>& universum;
    unsigned int channel;
};
#endif // CHANNEL_8BIT_HPP
