#include "ColorWheelMapper.h"

ColorWheelMapper::ColorWheelMapper() : multiplierMapper(multiplier, 255, 1.0)
{
    rgbDev = 0;
}

void ColorWheelMapper::Consume(int& _itterationCntr, float _pos)
{
    if(rgbDev != 0)
    {
        multiplierMapper.Request(_itterationCntr);
        Wheel(GetFuncCont()->Calc(_pos));
    }
}

void ColorWheelMapper::Wheel(float _pos)
{
    //unsigned int tmpPos = (unsigned int)(764.0*_pos);


    if(_pos < (1.0/3.0))
    {
        rgbDev->SetRedChnlVal(multiplier*((1.0/3.0)-_pos)*3);
        rgbDev->SetGreenChnlVal(multiplier*_pos*3);
        rgbDev->SetBlueChnlVal(0);
    }
    else if(_pos < (2.0/3.0))
    {
        _pos -= ((1.0/3.0));
        rgbDev->SetRedChnlVal(0);
        rgbDev->SetGreenChnlVal(multiplier*((1.0/3.0) - _pos)*3);
        rgbDev->SetBlueChnlVal(multiplier*_pos * 3);
    }
    else //if((pos > 511) && (pos <= 767))
    {
        _pos -= ((2.0/3.0));
        rgbDev->SetRedChnlVal(multiplier* _pos * 3.0);
        rgbDev->SetGreenChnlVal(0);
        rgbDev->SetBlueChnlVal(multiplier*((1.0/3.0) - _pos) * 3.0);
    }
}
