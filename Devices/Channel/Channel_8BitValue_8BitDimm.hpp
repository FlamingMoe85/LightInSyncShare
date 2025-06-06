#ifndef CHANNEL_8BITVALUE_8BITDIMM_HPP
#define CHANNEL_8BITVALUE_8BITDIMM_HPP

#include <vector>
#include "stdint.h"
#include "../Interfaces/I_Channel_8Bit.hpp"

class Channel_8BitValue_8BitDimm : public I_Channel_8Bit
{
public:
    Channel_8BitValue_8BitDimm(std::vector<uint8_t*>& _universum, uint8_t &_dimm)
        : universum(_universum),
          dimm(_dimm)
    {
        channel = 0;
    }

    void SetChnlVal(uint8_t _val) override
    {
        uint16_t val = (uint16_t)_val * (uint16_t)dimm;
        *(universum[channel]) = val>>8;
        *(universum[channel+1]) = val;
    }

    void SetChannel(unsigned int _channel){channel = _channel;}

private:
    std::vector<uint8_t*>& universum;
    unsigned int channel;
    uint8_t &dimm;

};
#endif // CHANNEL_8BITVALUE_8BITDIMM_HPP
