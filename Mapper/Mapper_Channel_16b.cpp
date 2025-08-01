#include "Mapper_Channel_16b.h"

Mapper_Channel_16b::Mapper_Channel_16b(I_Channel_16Bit& _dev, float _defaultMax, float _suggested) : dev(_dev)
{
    max = _defaultMax;
    suggested = _suggested;
    itterration = 0;
}

void Mapper_Channel_16b::Consume(int& _itterationCntr, float _pos)
{
     dev.SetChnlVal((uint16_t)(max*GetFuncCont()->Calc(_pos)));
}

void Mapper_Channel_16b::Request(int& _itterationCntr)
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
