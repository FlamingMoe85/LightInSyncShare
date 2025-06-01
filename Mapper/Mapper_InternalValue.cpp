#include "Mapper_InternalValue.h"

Mapper_InternalValue::Mapper_InternalValue(uint8_t &_externalValue,
                                            float _defaultMax,
                                            float _suggested) :
                                            externalValue(_externalValue)
{
    max = _defaultMax;
    suggested = _suggested;
    itterration = 0;
}

void Mapper_InternalValue::Consume(int& _itterationCntr, float _pos)
{
    externalValue = (uint8_t)(max*GetFuncCont()->Calc(_pos));
}

void Mapper_InternalValue::Request(int& _itterationCntr)
{
    /* This respects the usecase of this object when used for a
     * parameter of a Bundleseries. When no server is set, this forms
     * a serverless loopback, returning the value of member 'max'
    */
    if(GetServer() == 0)
    {
        Consume(_itterationCntr, suggested);
        return;
    }

    if(itterration != _itterationCntr)
    {
        GetServer()->GetRequested(_itterationCntr);
    }
    itterration = _itterationCntr;
}
