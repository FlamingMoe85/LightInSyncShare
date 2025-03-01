#ifndef I_RGB_H
#define I_RGB_H

#include "I_HowMany.hpp"
#include "I_DmxChannelRed_8Bit.hpp"
#include "I_DmxChannelGreen_8Bit.hpp"
#include "I_DmxChannelBlue_8Bit.hpp"

class I_RGB : public I_HowMany, public I_DmxChannelRed_8Bit, public I_DmxChannelGreen_8Bit, public I_DmxChannelBlue_8Bit
{

};

#endif // I_RGB_H
