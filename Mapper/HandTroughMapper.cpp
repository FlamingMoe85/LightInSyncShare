#include "HandTroughMapper.h"

HandTroughMapper::HandTroughMapper(std::vector<uint8_t *> &_universum, float _defaultMax, float _suggested) : universum(_universum)
{
    max = _defaultMax;
    suggested = _suggested;
    itterration = 0;
}

void HandTroughMapper::Consume(int& _itterationCntr, float _pos)
{
    *(universum[index]) = (uint8_t)(max*GetFuncCont()->Calc(_pos));
}

void HandTroughMapper::Request(int& _itterationCntr)
{
    /* This respects the usecase of this object when used for a
     * parameter of a Bundleseries. When no server is set, this forms
     * a serverless loopback, returning the value of member 'max'
    */
    if(server == 0)
    {
        Consume(_itterationCntr, suggested);
        return;
    }

    if(itterration != _itterationCntr)
    {
        server->GetRequested(_itterationCntr);
    }
    itterration = _itterationCntr;
}
