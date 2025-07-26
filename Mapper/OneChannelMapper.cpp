#include "OneChannelMapper.h"

OneChannelMapper::OneChannelMapper(float &_outVal, float _defaultMax, float _suggested) : outVal(_outVal)
{
    max = _defaultMax;
    suggested = _suggested;
    itterration = 0;
}

void OneChannelMapper::Consume(int& _itterationCntr, float _pos)
{
    outVal = max*_pos;
}

void OneChannelMapper::Request(int& _itterationCntr)
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
        itterration = _itterationCntr;
        server->GetRequested(_itterationCntr);
    }
}
