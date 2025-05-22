#ifndef RGBW_DIMM_H
#define RGBW_DIMM_H

#ifndef RGBW_DIMM_HPP
#define RGBW_DIMM_HPP

#include "../Interfaces/I_RGBW.hpp"
#include "../Interfaces/I_RGBW_Dimm.hpp"
#include "../Interfaces/I_RGB.hpp"
#include "../Interfaces/I_White.hpp"
#include "../Interfaces/I_DmxChannelRandom.hpp"
#include "../Channel/DmxChannel_8Bit.hpp"

#include "../../Mapper/HandTroughMapper.h"

typedef struct{
    unsigned int adr;
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    unsigned int white;
    unsigned int dimm;
}RGBW_Dimm_Init_t;

class RGBW_Dimm :
                                public I_RGB,
                                public I_RGBW,
                                public I_White,
                                public I_RGBW_Dimm,
                                public I_DmxChannelRandom
{
public:
    RGBW_Dimm(std::vector<uint8_t*>& _universum) :
                                                                    universum(_universum),
                                                                    redMapper(_universum, 255.0, 0.0),
                                                                    greenMapper(_universum, 255.0, 0.0),
                                                                    blueMapper(_universum, 255.0, 0.0),
                                                                    dimmMapper(_universum, 255.0, 1.0),
                                                                    whiteMapper(_universum, 255.0, 0.0)
    { };

    unsigned int Count(){return 1;};
    void Init(RGBW_Dimm_Init_t& initStruct)
    {
        red.SetChnlIndx(initStruct.red + initStruct.adr); redMapper.SetIndex(initStruct.red + initStruct.adr);
        green.SetChnlIndx(initStruct.green + initStruct.adr); greenMapper.SetIndex(initStruct.green + initStruct.adr);
        blue.SetChnlIndx(initStruct.blue + initStruct.adr); blueMapper.SetIndex(initStruct.blue + initStruct.adr);
        white.SetChnlIndx(initStruct.white + initStruct.adr);
        dimm.SetChnlIndx(initStruct.dimm + initStruct.adr);dimmMapper.SetIndex(initStruct.dimm + initStruct.adr);
        white.SetChnlIndx(initStruct.white + initStruct.adr);whiteMapper.SetIndex(initStruct.white + initStruct.adr);
    }

    uint16_t GetRedChnlIndex(){return red.GetChnlIndex();}
    uint16_t GetGreenChnlIndex(){return green.GetChnlIndex();}
    uint16_t GetBlueChnlIndex(){return blue.GetChnlIndex();}
    uint16_t GetWhiteChnlIndex(){return white.GetChnlIndex();}
    uint16_t GetDimmChnlIndex(){return dimm.GetChnlIndex();}


    void SetRedChnlVal(uint8_t val){red.SetChnlVal(val, universum);}
    void SetGreenChnlVal(uint8_t val){green.SetChnlVal(val, universum);}
    void SetBlueChnlVal(uint8_t val){blue.SetChnlVal(val, universum);}
    void SetWhiteChnlVal(uint8_t val){white.SetChnlVal(val, universum);}
    void SetDimmChnlVal(uint8_t val){dimm.SetChnlVal(val, universum);}

    void SetRandomChnlVal(uint8_t val, uint16_t channel){*(universum[channel]) += val;};

    HandTroughMapper* GetRedMapper(){return &redMapper;};
    HandTroughMapper* GetGreenMapper(){return &greenMapper;};
    HandTroughMapper* GetBlueMapper(){return &blueMapper;};
    HandTroughMapper* GetDimmMapper(){return &dimmMapper;};
    HandTroughMapper* GetWhiteMapper(){return &whiteMapper;};

    void SetDimmServer(I_Server* _s){dimmMapper.SetServer(_s);};
    void SetWhiteServer(I_Server* _s){whiteMapper.SetServer(_s);};

    void Ping(int _itteration){
                               dimmMapper.Request(_itteration);
                               whiteMapper.Request(_itteration);
                               //redMapper.Request(_itteration);
                               //greenMapper.Request(_itteration);
                               //blueMapper.Request(_itteration);
                              }

private:
    DmxChannel_8Bit red, green, blue, white, dimm;
    HandTroughMapper redMapper, greenMapper, blueMapper, dimmMapper, whiteMapper;
    unsigned int dmxAdrress;
    std::vector<uint8_t*>& universum;
};
#endif // RGBWA_UV_MINIMOVINGHEAD_HPP


#endif // RGBW_DIMM_H
