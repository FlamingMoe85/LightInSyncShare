#ifndef DEVICE_RGB_HPP
#define DEVICE_RGB_HPP


#include "../Interfaces/I_RGB.hpp"
#include "../Channel/DmxChannel_8Bit.hpp"

typedef struct{
    unsigned int adr;
    unsigned int red;
    unsigned int green;
    unsigned int blue;
}RGB_Init_t;

class Device_RGB : public I_RGB
{
public:
    Device_RGB(){ };

    unsigned int Count(){return 1;};

    void Init(RGB_Init_t& initStruct)
    {
        red.SetChnlIndx(initStruct.red + initStruct.adr);
        green.SetChnlIndx(initStruct.green + initStruct.adr);
        blue.SetChnlIndx(initStruct.blue + initStruct.adr);
    }
    uint16_t GetRedChnlIndex(){return red.GetChnlIndex();}
    uint16_t GetGreenChnlIndex(){return green.GetChnlIndex();}
    uint16_t GetBlueChnlIndex(){return blue.GetChnlIndex();}

    void SetRedChnlVal(uint8_t val, unsigned int devSel, std::vector<uint8_t*>& universum){red.SetChnlVal(val, universum);}
    void SetGreenChnlVal(uint8_t val, unsigned int devSel, std::vector<uint8_t*>& universum){green.SetChnlVal(val, universum);}
    void SetBlueChnlVal(uint8_t val, unsigned int devSel, std::vector<uint8_t*>& universum){blue.SetChnlVal(val, universum);}

private:
    DmxChannel_8Bit red, green, blue;

    unsigned int dmxAdrress;

};


#endif // DEVICE_RGB_HPP
