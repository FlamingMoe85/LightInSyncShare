#include "WhiteDimm_Mapper.hpp"

WhiteDimm_Mapper::WhiteDimm_Mapper()
{
    whiteDimmDev = 0;
}

void WhiteDimm_Mapper::Consume(int& _itterationCntr, float _pos)
{
    if(whiteDimmDev != 0)whiteDimmDev->SetWhiteDimmChnlVal(GetFuncCont()->Calc(_pos));
}
