#ifndef DMXCHANNEL_8BIT
#define DMXCHANNEL_8BIT

#include "stdint.h"
#include <vector>

//template <class T>
class DmxChannel_8Bit //: public T
{
 public:
    void SetChnlVal(uint8_t _val, std::vector<uint8_t*>& universum)
    {
        *(universum[index]) += _val;
    }

    void SetChnlIndx(uint16_t _index)
    {
        index = _index;
    }

    uint16_t GetChnlIndex(){return index;}

 private:
    uint16_t index;
};
/*
//template <class T>
void DmxChannel_8Bit::SetChnlVal(uint8_t _val, std::vector<uint8_t*>& universum)
{
    universum[index] = _val;
}

//template <class T>
void DmxChannel_8Bit::SetChnlIndx(uint16_t _index)
{
    index = _index;
}
*/
#endif
