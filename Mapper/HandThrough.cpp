#include "HandThrough.h"

HandThrough::HandThrough(float _suggested)
{
    randomChannel = 0;
    suggested = _suggested;
}

void HandThrough::SetRandomChannel(uint16_t _channel, I_DmxChannelRandom* _randomChannel)
{
    channel = _channel;
    randomChannel = _randomChannel;
}

void HandThrough::Consume(int& _itterationCntr, float _pos)
{
    if(randomChannel != 0)randomChannel->SetRandomChnlVal((uint8_t)(255*_pos), channel);
}

void HandThrough::Request(int& _itterationCntr)
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
