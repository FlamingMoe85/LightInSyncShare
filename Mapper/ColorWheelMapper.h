#ifndef COLORWHEELMAPPER_H
#define COLORWHEELMAPPER_H

#include "Mapper_Base.hpp"
#include "OneChannelMapper.h"
#include "../Devices/Interfaces/I_RGB.hpp"
#include "../Functions/FunctionContainer.h"

class ColorWheelMapper : public Mapper_Base
{
public:
    ColorWheelMapper();

    void Consume(int& _itterationCntr, float _pos) override;

    void SetRgbDevice(I_RGB* _rgbDev){rgbDev = _rgbDev;};
    OneChannelMapper* GetDimm(){return &multiplierMapper;}
    //int GetTypeId() override {return  FUNC_OWNER_IDS::COLOR_WHEEL;}

private:
    I_RGB* rgbDev;
    float multiplier;
    OneChannelMapper multiplierMapper;
    void Wheel(float _pos);
};

#endif // COLORWHEELMAPPER_H
