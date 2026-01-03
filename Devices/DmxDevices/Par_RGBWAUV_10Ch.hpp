#ifndef PAR_RGBWAUV_10CH_HPP
#define PAR_RGBWAUV_10CH_HPP

#include "../../Mapper/Mapper_Channel.h"
#include "../Channel/Channel_8Bit.hpp"
#include "../Interfaces/I_RGB.hpp"
#include "RgbDevice.hpp"


class Par_RGBWAUV_10Ch
{
public:
Par_RGBWAUV_10Ch(std::vector<uint8_t*>& _universum) :
    channel_Dimmer(_universum), channel_RedDimm(_universum), channel_GreenDimm(_universum), channel_BlueDimm(_universum),
    channel_WhiteDimm(_universum), channel_Amber(_universum), channel_UV(_universum),

    mapper_Dimmer(channel_Dimmer, 255, 1),
    mapper_RedDimm(channel_RedDimm, 255, 1), mapper_GreenDimm(channel_GreenDimm, 255, 1), mapper_BlueDimm(channel_BlueDimm, 255, 1),
    mapper_WhiteDimm(channel_WhiteDimm, 255, 1), mapper_Amber(channel_Amber, 255, 1), mapper_UV(channel_UV, 255, 1),

    rgbDevice(channel_RedDimm, channel_GreenDimm, channel_BlueDimm)

{

    mapper_Dimmer.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_RedDimm.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_GreenDimm.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_BlueDimm.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_WhiteDimm.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_Amber.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);
    mapper_UV.GetFuncCont()->AddFunctionSectionByParams(1.0,0.0,1.0,0.0);

}
;

    RGB_Device* GetRgbDevice()
    {
        return &rgbDevice;
    }

    void Init (int _adr)
    {
        channel_Dimmer.SetChannel(	0	+ _adr);
        channel_RedDimm.SetChannel(	1	+ _adr);
        channel_GreenDimm.SetChannel(2	+ _adr);
        channel_BlueDimm.SetChannel(3	+ _adr);
        channel_WhiteDimm.SetChannel(4	+ _adr);
        channel_Amber.SetChannel(5	+ _adr);
        channel_UV.SetChannel(6	+ _adr);
    }


    Mapper_Base* GetMapperDimmer(){ return &mapper_Dimmer;}
    Mapper_Base* GetMapperRedDimm(){ return &mapper_RedDimm;}
    Mapper_Base* GetMapperGreenDimm(){ return &mapper_GreenDimm;}
    Mapper_Base* GetMapperBlueDimm(){ return &mapper_BlueDimm;}
    Mapper_Base* GetMapperWhiteDimm(){ return &mapper_WhiteDimm;}
    Mapper_Base* GetMapperAmber(){ return &mapper_Amber;}
    Mapper_Base* GetMapperUV(){ return &mapper_UV;}

private:


Channel_8Bit    channel_Dimmer, channel_RedDimm, channel_GreenDimm, channel_BlueDimm, channel_WhiteDimm, channel_Amber, channel_UV;
Mapper_Channel  mapper_Dimmer,mapper_RedDimm, mapper_GreenDimm, mapper_BlueDimm, mapper_WhiteDimm, mapper_Amber, mapper_UV;
RGB_Device rgbDevice;
};


#endif // MOVINGHEAD_RGBW_7X40_BEEEYE_51CH_HPP
