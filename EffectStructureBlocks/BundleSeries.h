#ifndef BUNDLESERIES_H
#define BUNDLESERIES_H

#include "I_AlternateServer.hpp"
#include "../BrokerClientServer/ClientServerBase.hpp"
#include "../Functions/FunctionContainerSpan.h"
#include "../Mapper/OneChannelMapper.h"
#include "../FunctionOwners.hpp"

#define OLD_BS  0
#define NEW_BS  1

class BundleSeries : public Base_Server, public Base_Client, public FunctionOwners
{
public:
    BundleSeries(int _type = OLD_BS) :    mapperSpeed(speedMultiplier, 10.0, 0.1),
                        mapperShift(shift, 1.0, 0.0),
                        mapperspanNotch(spanNotch, 1.0, 0.5),
                        mapperspanMin(spanMin, 1.0, 0.0),
                        mapperspanMax(spanMax, 1.0, 1.0),
                        mapperSpanOffset(spanOffset, 1.0, 0.0)
    {
        speedMultiplier = 1.0;
        shift = 0.0;
        type = _type;
        alternateServer = nullptr;
    }

    void GetRequested(int& _itterationCntr) override;
    void Consume(int& _itterationCntr, float _pos) override;
    void Serve(int& _itterration, float pos) override;

    void SetMaxSpeedMultiplier(float _maxSpeedMulti);
    void SetMaxShift(float _maxShift);
    void SetShiftStepSize(float _shiftStepSize){shiftStepSize = _shiftStepSize;}
    FunctionContainerSpan& GetSpanCont(){return spanContainer;};

    void SetType(int _type){type = _type;}



    void SetSerParamShift(I_Server* _s){_s->RegisterClient(&mapperShift);};
    void SetSerParamSpeed(I_Server* _s){_s->RegisterClient(&mapperSpeed);};
    void SetSerParamSpanNotch(I_Server* _s){_s->RegisterClient(&mapperspanNotch);};
    void SetSerParamSpanMin(I_Server* _s){_s->RegisterClient(&mapperspanMin);};
    void SetSerParamSpanMax(I_Server* _s){_s->RegisterClient(&mapperspanMax);};
    void SetSerParamSpanOffset(I_Server* _s){_s->RegisterClient(&mapperSpanOffset);};
    //int GetTypeId() override {return  FUNC_OWNER_IDS::BUNDLE_SERIES;}

    void SetAlternateServer(I_AlternateServer* _aS){alternateServer = _aS;}

private:

    void SpeedMultiply(int& _itterration);
    float Shift(float _pos, int& _itterration);
    void Span(int& _itterration);
    FunctionContainerSpan spanContainer;

    float speedMultiplier, shift, shiftStepSize, spanNotch, spanMin, spanMax, spanOffset;
    OneChannelMapper mapperSpeed, mapperShift, mapperspanNotch, mapperspanMin, mapperspanMax, mapperSpanOffset;

    int itterration;

    int type;

    I_AlternateServer* alternateServer;
};

#endif // BUNDLESERIES_H
