#ifndef FUNCTIONCONTAINERSPAN_H
#define FUNCTIONCONTAINERSPAN_H

#include "FunctionContainer.h"
#include "FunctionSection_Linear.h"

class FunctionContainerSpan : public FunctionContainer
{
public:
    FunctionContainerSpan();

    void DefineSpanArea(float minX, float maxX, float xNotch);
    void DefineSpanArea(float minX, float maxX);
    void SetNotch(float _notch);
    void SetMin(float _min);
    void SetMax(float _max);

private:

    FunctionSection_Linear lowerSec, upperSec;
};

#endif // FUNCTIONCONTAINERSPAN_H
