#ifndef RGBW_16B_DIMM_HPP
#define RGBW_16B_DIMM_HPP

#include "../Interfaces/I_RGBW.hpp"
#include "../Interfaces/I_RGBW_Dimm.hpp"
#include "../Interfaces/I_RGB.hpp"
#include "../Interfaces/I_White.hpp"
#include "../Interfaces/I_WhiteDimm.hpp"
#include "../Interfaces/I_DmxChannelRandom.hpp"
#include "../Channel/DmxChannel_8Bit.hpp"

#include "../../Mapper/HandTroughMapper.h"

typedef struct{
    unsigned int adr;
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    unsigned int white;
}RGBW_16B_Dimm_Init_t;


class RGBW_16B_Dimm :
                                public I_RGB,
                                public I_RGBW,
                                public I_White,
                                public I_WhiteDimm,
                                public I_RGBW_Dimm,
                                public I_DmxChannelRandom
{
public:
    RGBW_16B_Dimm(std::vector<uint8_t*>& _universum) :
                                                                    universum(_universum),
                                                                    redMapper(_universum, 255.0, 0.0),
                                                                    greenMapper(_universum, 255.0, 0.0),
                                                                    blueMapper(_universum, 255.0, 0.0),
                                                                    whiteMapper(_universum, 255.0, 0.0)
    {
        dimm = 0;
        dimmWhite = 0;
    };

    unsigned int Count(){return 1;};
    void Init(RGBW_16B_Dimm_Init_t& initStruct)
    {
        redL.SetChnlIndx(initStruct.red + 1 + initStruct.adr); redH.SetChnlIndx(initStruct.red + initStruct.adr);
        greenL.SetChnlIndx(initStruct.green + 1 + initStruct.adr); greenH.SetChnlIndx(initStruct.green + initStruct.adr);
        blueL.SetChnlIndx(initStruct.blue + 1 + initStruct.adr); blueH.SetChnlIndx(initStruct.blue + initStruct.adr);
        whiteL.SetChnlIndx(initStruct.white + 1 + initStruct.adr); whiteH.SetChnlIndx(initStruct.white + initStruct.adr);
    }

    /*
    uint16_t GetRedChnlIndex(){return red.GetChnlIndex();}
    uint16_t GetGreenChnlIndex(){return green.GetChnlIndex();}
    uint16_t GetBlueChnlIndex(){return blue.GetChnlIndex();}
    uint16_t GetWhiteChnlIndex(){return white.GetChnlIndex();}
    */


    void SetRedChnlVal(uint8_t val){
        tmpU16 = val*dimm;
        redL.SetChnlVal(tmpU16, universum);
        redH.SetChnlVal((tmpU16>>8), universum);}
    void SetGreenChnlVal(uint8_t val){tmpU16 = val*dimm; greenL.SetChnlVal(tmpU16, universum); greenH.SetChnlVal((tmpU16>>8), universum);}
    void SetBlueChnlVal(uint8_t val){tmpU16 = val*dimm; blueL.SetChnlVal(tmpU16, universum); blueH.SetChnlVal((tmpU16>>8), universum);};
    void SetWhiteChnlVal(uint8_t val){tmpU16 = val*dimmWhite; whiteL.SetChnlVal(tmpU16, universum); whiteH.SetChnlVal((tmpU16>>8), universum);}
    void SetDimmChnlVal(uint8_t val){dimm = val;}
    void SetWhiteDimmChnlVal(uint8_t val){dimmWhite = val;}

    void SetRandomChnlVal(uint8_t val, uint16_t channel){*(universum[channel]) += val;};

    HandTroughMapper* GetRedMapper(){return &redMapper;};
    HandTroughMapper* GetGreenMapper(){return &greenMapper;};
    HandTroughMapper* GetBlueMapper(){return &blueMapper;};
    HandTroughMapper* GetWhiteMapper(){return &whiteMapper;};

    void SetWhiteServer(I_Server* _s){whiteMapper.SetServer(_s);};

    void Ping(int _itteration){
                               whiteMapper.Request(_itteration);
                               //redMapper.Request(_itteration);
                               //greenMapper.Request(_itteration);
                               //blueMapper.Request(_itteration);
                              }

private:
    DmxChannel_8Bit redL, redH, greenL, greenH, blueL, blueH, whiteL, whiteH;
    HandTroughMapper redMapper, greenMapper, blueMapper, whiteMapper;
    unsigned int dmxAdrress;
    std::vector<uint8_t*>& universum;
    uint8_t dimm, dimmWhite;
    uint16_t tmpU16;
};

#endif // RGBW_16B_DIMM_HPP
