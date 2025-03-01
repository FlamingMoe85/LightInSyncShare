#ifndef DEVICE_RGB_I_HPP
#define DEVICE_RGB_I_HPP

#include "../../GlobalDefines_Shared.h"
#include <stdint.h>

typedef struct
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
}rgb_t;

class Device_RGB_I
{
    virtual void SetPos(float& _pos) = 0;
};

#endif // DEVICE_RGB_I_HPP
