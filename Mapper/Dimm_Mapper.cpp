#include "Dimm_Mapper.hpp"

Dimm_Mapper::Dimm_Mapper()
{
    dimmDev = 0;
}

void Dimm_Mapper::Consume(int& _itterationCntr, float _pos)
{
    if(dimmDev != 0)dimmDev->SetDimmChnlVal(GetFuncCont()->Calc(_pos));
}
