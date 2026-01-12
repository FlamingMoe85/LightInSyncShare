#ifndef DEVICE_HPP
#define DEVICE_HPP

#include "../Channel/Channel_8BitValue_8BitDimm.hpp"

#include "../Interfaces/I_RGBW.hpp"
#include "../Interfaces/I_RGBW_Dimm.hpp"
#include "../Interfaces/I_RGB.hpp"
#include "../Interfaces/I_White.hpp"

#include "../../Mapper/Mapper_Channel.h"
#include "../../Mapper/Mapper_InternalValue.h"

#include "RgbDevice.hpp"

/*
 * Es gibt Mapper, die Interfacebezogen sind (z.B. I_RGB für ColorWheel), oder Templatebezogen.
 * Bei InterfaceMappern müsste man für jeden Kanaltyp einen eigenen Mapper anlegen.
 * Mit Templatemappern kann keine individuelle Implementierung erziehlt werden - z.B. wenn
 * Geräte verschiedene Umsetzungen vom Dimmkanal haben.
 *
 * Es könnte IMMER über GetMapper[Zweck](){return ...;} gehen und je nachdem ob ein Mapper
 * einen physischen Kanal abbildet, ein Schattenwert,
 *
 */


typedef struct{
    unsigned int adr;
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    unsigned int white;
}Device_t;

class Device :
        public I_RGB
{
public:
    Device(std::vector<uint8_t*>& _universum) : universum(_universum),
                                                redChannel(_universum,dimmRGB),
                                                greenChannel(_universum,dimmRGB),
                                                blueChannel(_universum,dimmRGB),
                                                whiteChannel(_universum,dimmWhite),
                                                redMapper(redChannel, 255, 1),
                                                greenMapper(greenChannel, 255, 1),
                                                blueMapper(blueChannel, 255, 1),
                                                whiteMapper(whiteChannel, 255, 1),
                                                dimmRgbMapper(dimmRGB, 255, 1),
                                                dimmWhiteMapper(dimmWhite, 255, 1),
												rgbDevice(redChannel, greenChannel, blueChannel)
    {
        dimmRGB = 255;
        dimmWhite = 255;

        redMapper.GetFuncCont()->AddFunctionSectionByParams(1.0, 0.0, 1.0, 0.0);
        greenMapper.GetFuncCont()->AddFunctionSectionByParams(1.0, 0.0, 1.0, 0.0);
        blueMapper.GetFuncCont()->AddFunctionSectionByParams(1.0, 0.0, 1.0, 0.0);
        whiteMapper.GetFuncCont()->AddFunctionSectionByParams(1.0, 0.0, 1.0, 0.0);
        dimmRgbMapper.GetFuncCont()->AddFunctionSectionByParams(1.0, 0.0, 1.0, 0.0);
        dimmWhiteMapper.GetFuncCont()->AddFunctionSectionByParams(1.0, 0.0, 1.0, 0.0);
    }

    void Init(Device_t& _init)
    {
        redChannel.SetChannel(_init.adr + _init.red);
        greenChannel.SetChannel(_init.adr + _init.green);
        blueChannel.SetChannel(_init.adr + _init.blue);
        whiteChannel.SetChannel(_init.adr + _init.white);
    }

    void SetRedChnlVal(uint8_t _val){redChannel.SetChnlVal(_val); }
    void SetGreenChnlVal(uint8_t _val){greenChannel.SetChnlVal(_val);}
    void SetBlueChnlVal(uint8_t _val){blueChannel.SetChnlVal(_val);};
    void SetWhiteChnlVal(uint8_t _val){whiteChannel.SetChnlVal(_val);}
    void SetDimmRGB(uint8_t _val){dimmRGB = _val;}
    void SetDimmWhite(uint8_t _val){dimmWhite = _val;}

    Mapper_Base* GetRedMapper(){return &redMapper;}
    Mapper_Base* GetGreenMapper(){return &greenMapper;}
    Mapper_Base* GetBlueMapper(){return &blueMapper;}
    Mapper_Base* GetWhiteMapper(){return &whiteMapper;}
    Mapper_Base* GetRgbDimmMapper(){return &dimmRgbMapper;}
    Mapper_Base* GetWhiteDimmMapper(){return &dimmWhiteMapper;}
	
	RGB_Device* GetRgbDevice(){return &rgbDevice;}


private:
    std::vector<uint8_t*>& universum;
    uint8_t dimmRGB, dimmWhite;
    Channel_8BitValue_8BitDimm redChannel;
    Channel_8BitValue_8BitDimm greenChannel;
    Channel_8BitValue_8BitDimm blueChannel;
    Channel_8BitValue_8BitDimm whiteChannel;

    Mapper_Channel redMapper;
    Mapper_Channel greenMapper;
    Mapper_Channel blueMapper;
    Mapper_Channel whiteMapper;
    Mapper_InternalValue dimmRgbMapper;
    Mapper_InternalValue dimmWhiteMapper;
	
	RGB_Device rgbDevice;
};

#endif // DEVICE_HPP
