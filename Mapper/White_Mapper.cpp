#include "White_Mapper.hpp"

White_Mapper::White_Mapper()
{
    whiteDev = 0;
}

void White_Mapper::Consume(int& _itterationCntr, float _pos)
{
    if(whiteDev != 0)whiteDev->SetWhiteChnlVal(GetFuncCont()->Calc(_pos));
}
