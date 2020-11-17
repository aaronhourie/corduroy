#pragma once

#include "driver/adc.h"

#include <cstdint>

namespace gpio 
{
    const int PARAMETER_1 = 34;
    const int PARAMETER_2 = 36;
    const int PARAMETER_3 = 35;
    const int PARAMETER_4 = 39;

    const int ROTARY_LEFT = 5;
    const int ROTARY_RIGHT = 17;
    const int ROTARY_CLICK = 18;

    const int I2C_SDA = 22;
    const int I2C_SCL = 21;
}

namespace adc 
{
    const adc1_channel_t PARAMETER_1 = ADC1_CHANNEL_0;
    const adc1_channel_t PARAMETER_2= ADC1_CHANNEL_3;
    const adc1_channel_t PARAMETER_3 = ADC1_CHANNEL_6;
    const adc1_channel_t PARAMETER_4 = ADC1_CHANNEL_7;
}