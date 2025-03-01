#include "BundleSeries.h"

void BundleSeries::Consume(int& _itterationCntr, float _pos)
{
    Serve(_itterationCntr, _pos);
}

void BundleSeries::Serve(int& _itterration, float pos)
{
    list<I_Client*>* clients = GetClientList();
    float index = 0.0;
    float tmpPos;

    SpeedMultiply(_itterration);
    Span(_itterration);

    pos *= speedMultiplier;
    while(pos >= 1.0)
    {
        pos -= 1.0;
    }

    if(itterration != _itterration)
    {
        for(I_Client* c : (*clients))
        {
            tmpPos = spanContainer.Calc(Shift(pos, _itterration));
            if(tmpPos > 1.0) tmpPos -= 1.0;
            tmpPos = funcContainer.Calc(tmpPos);
            c->Consume(_itterration, tmpPos);
            index += 1.0;
        }
    }
    itterration = _itterration;
}

void BundleSeries::SetMaxSpeedMultiplier(float _maxSpeedMulti)
{
    if(_maxSpeedMulti >= 0.0)
    {
        mapperSpeed.SetMax(_maxSpeedMulti);
    }
}

void BundleSeries::SetMaxShift(float _maxShift)
{
    if(_maxShift >= 0.0)
    {
        mapperShift.SetMax(_maxShift);
    }
}

void BundleSeries::SpeedMultiply(int &_itterration)
{
    mapperSpeed.Request(_itterration);
}

float BundleSeries::Shift(float _pos, int &_itterration)
{
    mapperShift.Request(_itterration);
    _pos += (shiftStepSize*shift);
    while(_pos > 1.0)
    {
        _pos -= 1.0;
    }
    return _pos;
}

void BundleSeries::Span(int &_itterration)
{
    mapperspanNotch.Request(_itterration);
    mapperSpanOffset.Request(_itterration);
    mapperspanMin.Request(_itterration);
    mapperspanMax.Request(_itterration);

    spanMin += spanOffset;
    spanMax += spanOffset;


    //while(spanMin > 1.0){ spanMin -= 1.0;}
    //while(spanMax > 1.0){ spanMax -= 1.0;}

    if(mapperspanNotch.HasServer())
    {
        spanContainer.DefineSpanArea(spanMin, spanMax, spanNotch);
    }
    else spanContainer.DefineSpanArea(spanMin, spanMax);
}

void BundleSeries::AddFunctionSectionByParams(float _topX, float _bottomX, float _topY, float _bottomY)
{
    funcContainer.AddFuncSeg(new FunctionSection_Linear(_bottomX, _topX, _bottomY, _topY));
}
void BundleSeries::SetFunctionSections(vector<funcSection_t> &funcSecs)
{
    funcContainer.ClearSections();
    funcContainer.SetFunctionSections(funcSecs);
}
