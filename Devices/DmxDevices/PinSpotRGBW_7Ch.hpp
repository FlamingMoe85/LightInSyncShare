#ifndef PINSPOTRGBW_7CH_HPP
#define PINSPOTRGBW_7CH_HPP

#include "../../Mapper/Mapper_Channel.h"
#include "../Channel/Channel_8Bit.hpp"
#include "../../Mapper/Mapper_Channel_16b.h"
#include "../Channel/Channel_16Bit.hpp"
#include "../Interfaces/I_RGB.hpp"


#include "RgbDevice.hpp"

class PinSpotRGBW_7Ch
 {
public:
        PinSpotRGBW_7Ch(std::vector<uint8_t*>& _universum) : universum(_universum),
        redChannel(_universum),
        greenChannel(_universum),
        blueChannel(_universum),
        whiteChannel(_universum),
        redMapper(redChannel, 255, 1),
        greenMapper(greenChannel, 255, 1),
        blueMapper(blueChannel, 255, 1),
        whiteMapper(whiteChannel, 255, 1),
        rgbDevice(redChannel, greenChannel, blueChannel)
{

        redMapper.GetFuncCont()->AddFunctionSectionByParams(1.0, 0.0, 1.0, 0.0);
        greenMapper.GetFuncCont()->AddFunctionSectionByParams(1.0, 0.0, 1.0, 0.0);
        blueMapper.GetFuncCont()->AddFunctionSectionByParams(1.0, 0.0, 1.0, 0.0);
        whiteMapper.GetFuncCont()->AddFunctionSectionByParams(1.0, 0.0, 1.0, 0.0);
}

        void Init (int _adr)
        {
            redChannel.SetChannel(	0	+ _adr);
            greenChannel.SetChannel(	1	+ _adr);
            blueChannel.SetChannel(	2	+ _adr);
            whiteChannel.SetChannel(	3	+ _adr);
        }

void SetRedChnlVal(uint8_t _val){redChannel.SetChnlVal(_val); }
void SetGreenChnlVal(uint8_t _val){greenChannel.SetChnlVal(_val);}
void SetBlueChnlVal(uint8_t _val){blueChannel.SetChnlVal(_val);};
void SetWhiteChnlVal(uint8_t _val){whiteChannel.SetChnlVal(_val);}

Mapper_Base* GetRedMapper(){return &redMapper;}
Mapper_Base* GetGreenMapper(){return &greenMapper;}
Mapper_Base* GetBlueMapper(){return &blueMapper;}
Mapper_Base* GetWhiteMapper(){return &whiteMapper;}

RGB_Device* GetRgbDevice(){return &rgbDevice;}

private:
std::vector<uint8_t*>& universum;
Channel_8Bit redChannel;
Channel_8Bit greenChannel;
Channel_8Bit blueChannel;
Channel_8Bit whiteChannel;

Mapper_Channel redMapper;
Mapper_Channel greenMapper;
Mapper_Channel blueMapper;
Mapper_Channel whiteMapper;

RGB_Device rgbDevice;

};

#endif // PINSPOTRGBW_7CH_HPP
