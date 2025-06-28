#ifndef WWA_STRIP_H
#define WWA_STRIP_H

#include "../../Mapper/Mapper_Channel.h"
#include "../Channel/Channel_8Bit.hpp"

typedef struct{
    unsigned int adr;
    unsigned int cold;
    unsigned int warm;
    unsigned int amber;
}WWA_Strip_t;

class WWA_Strip
{
public:
    WWA_Strip(std::vector<uint8_t*>& _universum) :  universum(_universum),
                                                    coldChannel(_universum),
                                                    warmChannel(_universum),
                                                    amberChannel(_universum),
                                                    coldMapper(coldChannel, 255, 1),
                                                    warmMapper(warmChannel, 255, 1),
                                                    amberMapper(amberChannel, 255, 1)
    {
        coldMapper.GetFuncCont()->AddFunctionSectionByParams(1.0, 0.0, 1.0, 0.0);
        warmMapper.GetFuncCont()->AddFunctionSectionByParams(1.0, 0.0, 1.0, 0.0);
        amberMapper.GetFuncCont()->AddFunctionSectionByParams(1.0, 0.0, 1.0, 0.0);
    }

    void Init(WWA_Strip_t& _init)
    {
        coldChannel.SetChannel(_init.adr + _init.cold);
        warmChannel.SetChannel(_init.adr + _init.warm);
        amberChannel.SetChannel(_init.adr + _init.amber);
    }

    Mapper_Base* GetColdMapper(){return &coldMapper;}
    Mapper_Base* GetWarmMapper(){return &warmMapper;}
    Mapper_Base* GetAmberMapper(){return &amberMapper;}

private:
            std::vector<uint8_t*>& universum;
            Channel_8Bit coldChannel;
            Channel_8Bit warmChannel;
            Channel_8Bit amberChannel;

            Mapper_Channel coldMapper;
            Mapper_Channel warmMapper;
            Mapper_Channel amberMapper;
};

#endif // WWA_STRIP_H
