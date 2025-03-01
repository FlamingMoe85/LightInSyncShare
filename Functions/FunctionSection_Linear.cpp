#include "FunctionSection_Linear.h"

FunctionSection_Linear::FunctionSection_Linear()
{
    topY = 1.0;
    bottomY = 0.0;
}

FunctionSection_Linear::FunctionSection_Linear(float _topX, float _bottomX, float _topY, float _bottomY)
{
    SetFuncArea(this, _topX, _bottomX, _topY, _bottomY);
}

FunctionSection_Linear::FunctionSection_Linear(funcSection_t &fs)
{
    SetFuncArea(this, fs);
}

float FunctionSection_Linear::Calc(float arg)
{
    float dY = (topY - bottomY);
    return bottomY + (dY / GetDx())*arg;
}
