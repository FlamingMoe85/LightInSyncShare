#ifndef RGBDEVICE_HPP
#define RGBDEVICE_HPP
#include "../../Mapper/Mapper_Channel.h"
#include "../Channel/Channel_8Bit.hpp"
#include "../Interfaces/I_RGB.hpp"

class RGB_Device : public I_RGB
{
public:
    RGB_Device(Channel_8Bit &_red, Channel_8Bit &_green, Channel_8Bit &_blue) : red(_red), green(_green), blue(_blue)
    {

    }

    void SetRedChnlVal(uint8_t _val){red.SetChnlVal(_val); }
    void SetGreenChnlVal(uint8_t _val){green.SetChnlVal(_val);}
    void SetBlueChnlVal(uint8_t _val){blue.SetChnlVal(_val);};

private:
    Channel_8Bit &red, &green, &blue;
};
#endif // RGBDEVICE_HPP
