#ifndef MOVINGHEAD_RGBWA_UV_HPP
#define MOVINGHEAD_RGBWA_UV_HPP

#include "../Interfaces/I_RGB.hpp"
#include "../../Mapper/Mapper_Channel.h"

#include "../Channel/Channel_8Bit.hpp"

#include "RgbDevice.hpp"

typedef struct{
    unsigned int adr;
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    unsigned int white;
    unsigned int amber;
    unsigned int uv;
    unsigned int dimm;
    unsigned int x;
    unsigned int y;
    unsigned int xy;
}MovingHead_RGBWA_UV_t;

class MovingHead_RGBWA_UV :
        public I_RGB
{
public:
MovingHead_RGBWA_UV(std::vector<uint8_t*>& _universum) : universum(_universum),
                                            redChannel(_universum),
                                            greenChannel(_universum),
                                            blueChannel(_universum),
                                            whiteChannel(_universum),
                                            dimmChannel(_universum),
                                            uvChannel(_universum),
                                            panChannel(_universum),
                                            tiltChannel(_universum),
                                            redMapper(redChannel, 255, 1),
                                            greenMapper(greenChannel, 255, 1),
                                            blueMapper(blueChannel, 255, 1),
                                            whiteMapper(whiteChannel, 255, 1),
                                            uvMapper(uvChannel, 255, 1),
                                            dimmMapper(dimmChannel, 255, 1),
                                            panMapper(panChannel, 255, 1),
                                            tiltMapper(tiltChannel, 255, 1),
											rgbDevice(redChannel, greenChannel, blueChannel)
{

    redMapper.GetFuncCont()->AddFunctionSectionByParams(1.0, 0.0, 1.0, 0.0);
    greenMapper.GetFuncCont()->AddFunctionSectionByParams(1.0, 0.0, 1.0, 0.0);
    blueMapper.GetFuncCont()->AddFunctionSectionByParams(1.0, 0.0, 1.0, 0.0);
    whiteMapper.GetFuncCont()->AddFunctionSectionByParams(1.0, 0.0, 1.0, 0.0);
    dimmMapper.GetFuncCont()->AddFunctionSectionByParams(1.0, 0.0, 1.0, 0.0);
    uvMapper.GetFuncCont()->AddFunctionSectionByParams(1.0, 0.0, 1.0, 0.0);
    panMapper.GetFuncCont()->AddFunctionSectionByParams(1.0, 0.0, 1.0, 0.0);
    tiltMapper.GetFuncCont()->AddFunctionSectionByParams(1.0, 0.0, 1.0, 0.0);
}

void Init(MovingHead_RGBWA_UV_t& _init)
{
    redChannel.SetChannel(_init.adr + _init.red);
    greenChannel.SetChannel(_init.adr + _init.green);
    blueChannel.SetChannel(_init.adr + _init.blue);
    whiteChannel.SetChannel(_init.adr + _init.white);
    uvChannel.SetChannel(_init.adr + _init.uv);
    dimmChannel.SetChannel(_init.adr + _init.dimm);
    panChannel.SetChannel(_init.adr + _init.x);
    tiltChannel.SetChannel(_init.adr + _init.y);
}

void SetRedChnlVal(uint8_t _val){redChannel.SetChnlVal(_val); }
void SetGreenChnlVal(uint8_t _val){greenChannel.SetChnlVal(_val);}
void SetBlueChnlVal(uint8_t _val){blueChannel.SetChnlVal(_val);};
void SetWhiteChnlVal(uint8_t _val){whiteChannel.SetChnlVal(_val);}
void SetUv(uint8_t _val){uvChannel.SetChnlVal(_val);}
void SetDimm(uint8_t _val){dimmChannel.SetChnlVal(_val);}
void SetPanChnlVal(uint8_t _val){panChannel.SetChnlVal(_val);}
void SetTiltChnlVal(uint8_t _val){tiltChannel.SetChnlVal(_val);}

Mapper_Base* GetRedMapper(){return &redMapper;}
Mapper_Base* GetGreenMapper(){return &greenMapper;}
Mapper_Base* GetBlueMapper(){return &blueMapper;}
Mapper_Base* GetWhiteMapper(){return &whiteMapper;}
Mapper_Base* GetDimmMapper(){return &dimmMapper;}
Mapper_Base* GetUvMapper(){return &uvMapper;}
Mapper_Base* GetPanMapper(){return &panMapper;}
Mapper_Base* GetTiltMapper(){return &tiltMapper;}

RGB_Device* GetRgbDevice(){return &rgbDevice;}

private:
std::vector<uint8_t*>& universum;
Channel_8Bit redChannel;
Channel_8Bit greenChannel;
Channel_8Bit blueChannel;
Channel_8Bit whiteChannel;
Channel_8Bit uvChannel;
Channel_8Bit dimmChannel;
Channel_8Bit panChannel;
Channel_8Bit tiltChannel;

Mapper_Channel redMapper;
Mapper_Channel greenMapper;
Mapper_Channel blueMapper;
Mapper_Channel whiteMapper;
Mapper_Channel uvMapper;
Mapper_Channel dimmMapper;
Mapper_Channel panMapper;
Mapper_Channel tiltMapper;

RGB_Device rgbDevice;
};
#endif // MOVINGHEAD_RGBWA_UV_HPP
