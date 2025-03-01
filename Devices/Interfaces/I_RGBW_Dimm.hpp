#ifndef I_RGBW_DIMM_HPP
#define I_RGBW_DIMM_HPP

#include "I_HowMany.hpp"
#include "I_DmxChannelRed_8Bit.hpp"
#include "I_DmxChannelGreen_8Bit.hpp"
#include "I_DmxChannelBlue_8Bit.hpp"
#include "I_DmxChannelWhite_8Bit.hpp"
#include "I_DmxChannelDimm_8Bit.hpp"

class I_RGBW_Dimm : public I_HowMany,
                    public I_DmxChannelRed_8Bit,
                    public I_DmxChannelGreen_8Bit,
                    public I_DmxChannelBlue_8Bit,
                    public I_DmxChannelWhite_8Bit,
                    public I_DmxChannelDimm_8Bit
{

};
#endif // I_RGBW_DIMM_HPP
