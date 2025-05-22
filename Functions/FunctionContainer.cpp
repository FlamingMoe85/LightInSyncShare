#include "FunctionContainer.h"
#include "FunctionSection_Linear.h"

FunctionContainer::FunctionContainer()
{

}

float FunctionContainer::Calc(float arg)
{
    for(I_FunctionSection* seg:funcSegments)
    {
        if((seg->GetBottomX() <= arg) && (seg->GetTopX() >= arg))
        {
            return seg->Calc(arg - seg->GetBottomX());
        }
    }
    return arg;
}

void FunctionContainer::ClearSections()
{
    funcSegments.clear();
}

void FunctionContainer::AddFunctionSectionByParams(float _topX, float _bottomX, float _topY, float _bottomY)
{
    AddFuncSeg(new FunctionSection_Linear(_bottomX, _topX, _bottomY, _topY));
}

void FunctionContainer::SetFunctionSections(vector<funcSection_t> &funcSecs)
{
    ClearSections();
    for(funcSection_t &fs : funcSecs)
    {
        AddFuncSeg(new FunctionSection_Linear(fs));
    }
}
