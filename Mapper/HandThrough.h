#ifndef HANDTHROUGH_H
#define HANDTHROUGH_H

#include "../../../share/BrokerClientServer/ClientServerBase.hpp"
#include "../Devices/Interfaces/I_DmxChannelRandom.hpp".hpp"

class HandThrough : public ClientServerBase
{
public:
    HandThrough(float _suggested);

    void Consume(int& _itterationCntr, float _pos) override;
    void Request(int& _itterationCntr) override;

    void SetRandomChannel(uint16_t _channel, I_DmxChannelRandom* _randomChannel);

private:
    I_DmxChannelRandom* randomChannel;
    uint16_t channel;
    float suggested;
    int itterration;
};

#endif // HANDTHROUGH_H
