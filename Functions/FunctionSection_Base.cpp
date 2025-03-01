#include "FunctionSection_Base.h"

FunctionSection_Base::FunctionSection_Base()
{
    bottomX = 0.0;
    topX = 1.0;
}

int FunctionSection_Base::SetTopX(float _topX)
{
    if(_topX < bottomX) return -1;
    topX = _topX;
    return 1;
}

int FunctionSection_Base::SetBottomX(float _bottomX)
{
    if(_bottomX > topX)return -1;
    bottomX = _bottomX;
    return 1;
}

float FunctionSection_Base::GetTopX()
{
    return topX;
}

float FunctionSection_Base::GetBottomX()
{
    return bottomX;
}


float FunctionSection_Base::GetDx()
{
    return (topX - bottomX);
}

