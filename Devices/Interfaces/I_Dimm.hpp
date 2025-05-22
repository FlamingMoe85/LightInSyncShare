#ifndef I_DIMM_HPP
#define I_DIMM_HPP

#include "I_HowMany.hpp"
#include "I_DmxChannelDimm_8Bit.hpp"

class I_Dimm :  public I_HowMany, public I_DmxChannelDimm_8Bit
{

};

#endif // I_DIMM_HPP
