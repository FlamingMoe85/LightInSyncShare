#ifndef DEVICE_RGBW_H
#define DEVICE_RGBW_H

#include "../Interfaces/I_RGBW.hpp"
#include "../Interfaces/I_RGB.hpp"
#include "../Interfaces/I_White.hpp"
#include "../Channel/DmxChannel_8Bit.hpp"

typedef struct{
    unsigned int adr;
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    unsigned int white;
}RGBW_Init_t;

class Device_RGBW : public I_RGB, public I_RGBW, public I_White
{
public:
    Device_RGBW(){ };

    unsigned int Count(){return 1;};

    void Init(RGBW_Init_t& initStruct)
    {
        red.SetChnlIndx(initStruct.red + initStruct.adr);
        green.SetChnlIndx(initStruct.green + initStruct.adr);
        blue.SetChnlIndx(initStruct.blue + initStruct.adr);
        white.SetChnlIndx(initStruct.white + initStruct.adr);
    }
    uint16_t GetRedChnlIndex(){return red.GetChnlIndex();}
    uint16_t GetGreenChnlIndex(){return green.GetChnlIndex();}
    uint16_t GetBlueChnlIndex(){return blue.GetChnlIndex();}
    uint16_t GetWhiteChnlIndex(){return white.GetChnlIndex();}

    void SetRedChnlVal(uint8_t val, unsigned int devSel, std::vector<uint8_t*>& universum){red.SetChnlVal(val, universum);}
    void SetGreenChnlVal(uint8_t val, unsigned int devSel, std::vector<uint8_t*>& universum){green.SetChnlVal(val, universum);}
    void SetBlueChnlVal(uint8_t val, unsigned int devSel, std::vector<uint8_t*>& universum){blue.SetChnlVal(val, universum);}
    void SetWhiteChnlVal(uint8_t val, unsigned int devSel, std::vector<uint8_t*>& universum){white.SetChnlVal(val, universum);}

private:
    DmxChannel_8Bit red, green, blue, white;

    unsigned int dmxAdrress;

};

#endif // DEVICE_RGBW_H
