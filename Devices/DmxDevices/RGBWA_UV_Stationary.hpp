#ifndef RGBWA_UV_STATIONARY_H
#define RGBWA_UV_STATIONARY_H

#include "../Interfaces/I_RGBW.hpp"
#include "../Interfaces/I_RGBW_Dimm.hpp"
#include "../Interfaces/I_RGB.hpp"
#include "../Interfaces/I_White.hpp"
#include "../Channel/DmxChannel_8Bit.hpp"

typedef struct{
    unsigned int adr;
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    unsigned int white;
    unsigned int amber;
    unsigned int uv;
    unsigned int dimm;
}RGBWA_UV_Init_t;

class RGBWA_UV_Stationary : public I_RGB, public I_RGBW, public I_White, public I_RGBW_Dimm
{
public:
    RGBWA_UV_Stationary(){ };

    unsigned int Count(){return 1;};
    void Init(RGBWA_UV_Init_t& initStruct)
    {
        red.SetChnlIndx(initStruct.red + initStruct.adr);
        green.SetChnlIndx(initStruct.green + initStruct.adr);
        blue.SetChnlIndx(initStruct.blue + initStruct.adr);
        white.SetChnlIndx(initStruct.white + initStruct.adr);
        dimm.SetChnlIndx(initStruct.dimm + initStruct.adr);
        amber.SetChnlIndx(initStruct.amber + initStruct.adr);
        white.SetChnlIndx(initStruct.white + initStruct.adr);
        uv.SetChnlIndx(initStruct.uv + initStruct.adr);
    }

    uint16_t GetRedChnlIndex(){return red.GetChnlIndex();}
    uint16_t GetGreenChnlIndex(){return green.GetChnlIndex();}
    uint16_t GetBlueChnlIndex(){return blue.GetChnlIndex();}
    uint16_t GetWhiteChnlIndex(){return white.GetChnlIndex();}
    uint16_t GetDimmChnlIndex(){return dimm.GetChnlIndex();}
    uint16_t GetAmberChnlIndex(){return amber.GetChnlIndex();}
    uint16_t GetUvChnlIndex(){return uv.GetChnlIndex();}


    void SetRedChnlVal(uint8_t val, unsigned int devSel, std::vector<uint8_t*>& universum){red.SetChnlVal(val, universum);}
    void SetGreenChnlVal(uint8_t val, unsigned int devSel, std::vector<uint8_t*>& universum){green.SetChnlVal(val, universum);}
    void SetBlueChnlVal(uint8_t val, unsigned int devSel, std::vector<uint8_t*>& universum){blue.SetChnlVal(val, universum);}
    void SetWhiteChnlVal(uint8_t val, unsigned int devSel, std::vector<uint8_t*>& universum){white.SetChnlVal(val, universum);}
    void SetDimmChnlVal(uint8_t val, unsigned int devSel, std::vector<uint8_t*>& universum){dimm.SetChnlVal(val, universum);}

private:
    DmxChannel_8Bit red, green, blue, white, amber, uv, dimm;

    unsigned int dmxAdrress;
};
#endif // RGBWA_UV_STATIONARY_H
