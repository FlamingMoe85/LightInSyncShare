#ifndef HANDTROUGHMAPPER_T_H
#define HANDTROUGHMAPPER_T_H

#include "stdint.h"
#include "../../../share/BrokerClientServer/ClientServerBase.hpp"
#include "../../../share/GlobalDefines_Shared.h"
//#include "../Functions/FunctionContainer.h"
#include "../FunctionOwners.hpp"
#include "../Devices/Channel/Channel_8Bit_T.hpp"
#include <vector>

template <class T> class HandTroughMapper_T : public ClientServerBase, public FunctionOwners
{
public:
    HandTroughMapper_T(Channel_8Bit_T<T>& _dev, float _defaultMax, float _suggested) : dev(_dev)
    {
        {
            max = _defaultMax;
            suggested = _suggested;
            itterration = 0;
        }
    }

    void Consume(int& _itterationCntr, float _pos) override
    {
        T val = (T)((uint8_t)(max*GetFuncCont()->Calc(_pos)));
        dev.SetChnlVal(val);
    }

    void Request(int& _itterationCntr)override
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
    void SetMax(float _max){ if(_max > 0) max = _max;};
    //void SetIndex(int _index){index = _index;}
    //void SetDevice(Channel_8Bit<T>* _dev){dev = _dev;};
    //int GetTypeId() override {return  FUNC_OWNER_IDS::HAND_TRHOUGH;}

private:
    float max;
    float suggested;
    int itterration;
    //int index;
    Channel_8Bit_T<T>& dev;
};

#endif // HANDTROUGHMAPPER_H
