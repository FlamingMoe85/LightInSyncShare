#include "Mapper_Channel.h"

Mapper_Channel::Mapper_Channel(I_Channel_8Bit& _dev, float _defaultMax, float _suggested) : dev(_dev)
{
    max = _defaultMax;
    suggested = _suggested;
    itterration = 0;
}

void Mapper_Channel::Consume(int& _itterationCntr, float _pos)
{
     dev.SetChnlVal((uint8_t)(max*GetFuncCont()->Calc(_pos)));
}

void Mapper_Channel::Request(int& _itterationCntr)
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
