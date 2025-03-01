#include "ColorWheelMapper.h"

ColorWheelMapper::ColorWheelMapper()
{
    rgbDev = 0;
}

void ColorWheelMapper::Consume(int& _itterationCntr, float _pos)
{
    if(rgbDev != 0)Wheel(_pos);
}

void ColorWheelMapper::Wheel(float _pos)
{
    unsigned int tmpPos = (unsigned int)(764.0*_pos);



        if((tmpPos >= 0) && (tmpPos < 256))
        {
            rgbDev->SetRedChnlVal(255 - tmpPos);
            rgbDev->SetGreenChnlVal(tmpPos);
            rgbDev->SetBlueChnlVal(0);
        }
        else if((tmpPos > 255) && (tmpPos < 512))
        {
            rgbDev->SetRedChnlVal(0);
            rgbDev->SetGreenChnlVal(511 - tmpPos);
            rgbDev->SetBlueChnlVal(tmpPos - 256);
        }
        else //if((pos > 511) && (pos <= 767))
        {
            rgbDev->SetRedChnlVal(tmpPos-511);
            rgbDev->SetGreenChnlVal(0);
            rgbDev->SetBlueChnlVal(764 - tmpPos);
        }
}
