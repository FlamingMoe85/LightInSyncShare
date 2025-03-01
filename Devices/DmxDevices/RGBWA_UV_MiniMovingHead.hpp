#ifndef RGBWA_UV_MINIMOVINGHEAD_HPP
#define RGBWA_UV_MINIMOVINGHEAD_HPP

#include "../Interfaces/I_RGBW.hpp"
#include "../Interfaces/I_RGBW_Dimm.hpp"
#include "../Interfaces/I_RGB.hpp"
#include "../Interfaces/I_White.hpp"
#include "../Interfaces/I_DmxChannelPan_8Bit.hpp"
#include "../Interfaces/I_DmxChannelTilt_8Bit.hpp"
#include "../Interfaces/I_DmxChannelRandom.hpp"
#include "../Channel/DmxChannel_8Bit.hpp"

#include "../../Mapper/HandTroughMapper.h"

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
}RGBWA_UV_MiniMovingHead_Init_t;

class RGBWA_UV_MiniMovingHead :
                                public I_RGB,
                                public I_RGBW,
                                public I_White,
                                public I_RGBW_Dimm,
                                public I_DmxChannelPan_8Bit,
                                public I_DmxChannelTilt_8Bit,
                                public I_DmxChannelRandom
{
public:
    RGBWA_UV_MiniMovingHead(std::vector<uint8_t*>& _universum) :
                                                                    universum(_universum),
                                                                    redMapper(_universum, 255.0, 0.0),
                                                                    greenMapper(_universum, 255.0, 0.0),
                                                                    blueMapper(_universum, 255.0, 0.0),
                                                                    panMapper(_universum, 255.0, 0.0),
                                                                    tiltMapper(_universum, 255.0, 0.0),
                                                                    dimmMapper(_universum, 255.0, 1.0)
    { };

    unsigned int Count(){return 1;};
    void Init(RGBWA_UV_MiniMovingHead_Init_t& initStruct)
    {
        red.SetChnlIndx(initStruct.red + initStruct.adr); redMapper.SetIndex(initStruct.red + initStruct.adr);
        green.SetChnlIndx(initStruct.green + initStruct.adr); greenMapper.SetIndex(initStruct.green + initStruct.adr);
        blue.SetChnlIndx(initStruct.blue + initStruct.adr); blueMapper.SetIndex(initStruct.blue + initStruct.adr);
        white.SetChnlIndx(initStruct.white + initStruct.adr);
        dimm.SetChnlIndx(initStruct.dimm + initStruct.adr);dimmMapper.SetIndex(initStruct.dimm + initStruct.adr);
        amber.SetChnlIndx(initStruct.amber + initStruct.adr);
        white.SetChnlIndx(initStruct.white + initStruct.adr);
        uv.SetChnlIndx(initStruct.uv + initStruct.adr);
        x.SetChnlIndx(initStruct.x + initStruct.adr); panMapper.SetIndex(initStruct.x + initStruct.adr);
        y.SetChnlIndx(initStruct.y + initStruct.adr); tiltMapper.SetIndex(initStruct.y + initStruct.adr);
        xy.SetChnlIndx(initStruct.xy + initStruct.adr);
    }

    uint16_t GetRedChnlIndex(){return red.GetChnlIndex();}
    uint16_t GetGreenChnlIndex(){return green.GetChnlIndex();}
    uint16_t GetBlueChnlIndex(){return blue.GetChnlIndex();}
    uint16_t GetWhiteChnlIndex(){return white.GetChnlIndex();}
    uint16_t GetDimmChnlIndex(){return dimm.GetChnlIndex();}
    uint16_t GetAmberChnlIndex(){return amber.GetChnlIndex();}
    uint16_t GetUvChnlIndex(){return uv.GetChnlIndex();}
    uint16_t GetXChnlIndex(){return x.GetChnlIndex();}
    uint16_t GetYChnlIndex(){return y.GetChnlIndex();}
    uint16_t GetXYChnlIndex(){return xy.GetChnlIndex();}


    void SetRedChnlVal(uint8_t val){red.SetChnlVal(val, universum);}
    void SetGreenChnlVal(uint8_t val){green.SetChnlVal(val, universum);}
    void SetBlueChnlVal(uint8_t val){blue.SetChnlVal(val, universum);}
    void SetWhiteChnlVal(uint8_t val){white.SetChnlVal(val, universum);}
    void SetDimmChnlVal(uint8_t val){dimm.SetChnlVal(val, universum);}
    void SetTiltChnlVal(uint8_t val){x.SetChnlVal(val, universum);}
    void SetPanChnlVal(uint8_t val){y.SetChnlVal(val, universum);}

    void SetRandomChnlVal(uint8_t val, uint16_t channel){*(universum[channel]) += val;};

    HandTroughMapper* GetRedMapper(){return &redMapper;};
    HandTroughMapper* GetGreenMapper(){return &greenMapper;};
    HandTroughMapper* GetBlueMapper(){return &blueMapper;};
    HandTroughMapper* GetPanMapper(){return &panMapper;};
    HandTroughMapper* GetTiltMapper(){return &tiltMapper;};
    HandTroughMapper* GetDimmMapper(){return &dimmMapper;};

    void SetDimmServer(I_Server* _s){dimmMapper.SetServer(_s);};

    void Ping(int _itteration){dimmMapper.Request(_itteration);
                               //redMapper.Request(_itteration);
                               //greenMapper.Request(_itteration);
                               //blueMapper.Request(_itteration);
                               panMapper.Request(_itteration);
                               tiltMapper.Request(_itteration);
                              }

private:
    DmxChannel_8Bit red, green, blue, white, amber, uv, dimm, x, y, xy;
    HandTroughMapper redMapper, greenMapper, blueMapper, panMapper, tiltMapper, dimmMapper;
    unsigned int dmxAdrress;
    std::vector<uint8_t*>& universum;
};
#endif // RGBWA_UV_MINIMOVINGHEAD_HPP
