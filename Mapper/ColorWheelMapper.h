#ifndef COLORWHEELMAPPER_H
#define COLORWHEELMAPPER_H

#include "Mapper_Base.hpp"
#include "../Devices/Interfaces/I_RGB.hpp"
#include "../Functions/FunctionContainer.h"

class ColorWheelMapper : public Mapper_Base
{
public:
    ColorWheelMapper();

    void Consume(int& _itterationCntr, float _pos) override;

    void SetRgbDevice(I_RGB* _rgbDev){rgbDev = _rgbDev;};
    //int GetTypeId() override {return  FUNC_OWNER_IDS::COLOR_WHEEL;}

private:
    I_RGB* rgbDev;

    void Wheel(float _pos);
};

#endif // COLORWHEELMAPPER_H
