#include "FunctionContainerSpan.h"
#include "FunctionSection_Linear.h"

FunctionContainerSpan::FunctionContainerSpan()
{
    this->AddFuncSeg(&lowerSec);
    this->AddFuncSeg(&upperSec);
}

void FunctionContainerSpan::DefineSpanArea(float minX, float maxX, float xNotch)
{
    /* SetFuncArea(FunctionSection_Linear* sec, float _bottomX, float _topX, float _bottomY, float _topY)
     *
    */
    FunctionSection_Linear::SetFuncArea(&lowerSec, 0.0, xNotch, minX, maxX);
    FunctionSection_Linear::SetFuncArea(&upperSec, xNotch, 1.0, maxX, minX);
}

void FunctionContainerSpan::DefineSpanArea(float minX, float maxX)
{
    /* SetFuncArea(FunctionSection_Linear* sec, float _bottomX, float _topX, float _bottomY, float _topY)
     *
    */
    if((minX == 0.0) && (maxX = 1.0)) DefineSpanArea(minX, maxX, 1.0);
    else DefineSpanArea(minX, maxX, 0.5);
}


void FunctionContainerSpan::SetNotch(float _notch)
{
    lowerSec.SetBottomX(_notch);
    upperSec.SetTopX(_notch);
}

void FunctionContainerSpan::SetMin(float _min)
{
    lowerSec.SetBottomY(_min);
    upperSec.SetTopY(_min);
}

void FunctionContainerSpan::SetMax(float _max)
{
    lowerSec.SetTopY(_max);
    upperSec.SetBottomY(_max);
}

