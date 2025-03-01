#ifndef FUNCTIONSECTION_BASE_H
#define FUNCTIONSECTION_BASE_H

//#include "../GlobalDefines_Shared.h"
#include "I_FunctionSection.hpp"

#include <vector>



class Dot
{
public:
    Dot()
    {
        minX = minY = 0;
        maxX = maxY = 0;
    }

    Dot(float _minX, float _maxX, float _minY, float _maxY)
    {
        minX = _minX;
        maxX = _maxX;
        minY = _minY;
        maxY = _maxY;
    }

    float minX;
    float maxX;
    float minY;
    float maxY;
};

class ProportionIncrementalDot
{
public:

    ProportionIncrementalDot(float _xProp, float _absY)
    {
        xProp = _xProp;
        absY = _absY;
    }

    float xProp;
    float absY;
};


class FunctionSection_Base : public I_FunctionSection
{
public:
    FunctionSection_Base();

    int SetTopX(float _topX) override;
    int SetBottomX(float _bottomX) override;
    float GetTopX() override;
    float GetBottomX() override;

    float GetDx();

private:
    float topX, bottomX;

};


static void GenerateSequentialXvalues(std::vector<ProportionIncrementalDot*> &inVec, std::vector<Dot*> &outDotVec, float _yStart)
{
    float xSum = 0, xSumRunning = 0, yold = _yStart;
    unsigned int i = 0;

    for(ProportionIncrementalDot* pd : inVec)
    {
        xSum += pd->xProp;
    }

    for(ProportionIncrementalDot* pd : inVec)
    {
        if(i == (inVec.size()-1))
        {
            outDotVec.push_back(new Dot(xSumRunning, 1.0, yold, pd->absY));
        }
        else
        {
            outDotVec.push_back(new Dot(xSumRunning, xSumRunning+pd->xProp/xSum, yold, pd->absY));
        }
        xSumRunning += (pd->xProp/xSum);
        yold = pd->absY;
        i++;
    }
}

#endif // FUNCTIONSECTION_BASE_H
