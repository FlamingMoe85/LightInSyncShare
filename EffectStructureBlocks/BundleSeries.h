#ifndef BUNDLESERIES_H
#define BUNDLESERIES_H

#include "../BrokerClientServer/ClientServerBase.hpp"
#include "../Functions/FunctionContainerSpan.h"
#include "../Mapper/OneChannelMapper.h"



class BundleSeries : public ClientServerBase
{
public:
    BundleSeries() :    mapperSpeed(speedMultiplier, 10.0, 0.1),
                        mapperShift(shift, 1.0, 0.0),
                        mapperspanNotch(spanNotch, 1.0, 0.5),
                        mapperspanMin(spanMin, 1.0, 0.0),
                        mapperspanMax(spanMax, 1.0, 1.0),
                        mapperSpanOffset(spanOffset, 1.0, 0.0)
    {
        speedMultiplier = 1.0;
        shift = 0.0;
    }

    void Consume(int& _itterationCntr, float _pos) override;
    void Serve(int& _itterration, float pos) override;

    void SetMaxSpeedMultiplier(float _maxSpeedMulti);
    void SetMaxShift(float _maxShift);
    void SetShiftStepSize(float _shiftStepSize){shiftStepSize = _shiftStepSize;}
    FunctionContainerSpan& GetSpanCont(){return spanContainer;};



    void SetSerParamShift(I_Server* _s){_s->RegisterClient(&mapperShift);};
    void SetSerParamSpeed(I_Server* _s){_s->RegisterClient(&mapperSpeed);};
    void SetSerParamSpanNotch(I_Server* _s){_s->RegisterClient(&mapperspanNotch);};
    void SetSerParamSpanMin(I_Server* _s){_s->RegisterClient(&mapperspanMin);};
    void SetSerParamSpanMax(I_Server* _s){_s->RegisterClient(&mapperspanMax);};
    void SetSerParamSpanOffset(I_Server* _s){_s->RegisterClient(&mapperSpanOffset);};

    void AddFunctionSectionByParams(float _topX, float _bottomX, float _topY, float _bottomY);
    void SetFunctionSections(vector<funcSection_t> &funcSecs);

private:

    void SpeedMultiply(int& _itterration);
    float Shift(float _pos, int& _itterration);
    void Span(int& _itterration);
    FunctionContainerSpan spanContainer;
    FunctionContainer funcContainer;

    float speedMultiplier, shift, shiftStepSize, spanNotch, spanMin, spanMax, spanOffset;
    OneChannelMapper mapperSpeed, mapperShift, mapperspanNotch, mapperspanMin, mapperspanMax, mapperSpanOffset;

    int itterration;
};

#endif // BUNDLESERIES_H
