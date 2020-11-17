#pragma once

#include "IMenu.h"

#include "Pins.h"

#include "Encoder.h"

/**
 * Manages caching and updating control values from peripherals.
 */
class Controls 
{
public:

    Controls();

    void InitControlValues();

    void PollControls(IMenu& menu);

private:

    // Update a parameter by reading from the gpio pin.
    // Returns true if the value was updated (it met the Epsilon threshold.)
    static bool UpdateParameter(std::uint8_t& destParameter, std::uint8_t gpioPin );

    // The amount by which a parameter must change for it to be considered "Updated"
    static const std::uint8_t PARAMETER_EPSILON = 4;

    // The maximum value to constrain the parameters to. 
    static constexpr int MAX_VALUE = 100;

    // The amount by which the parameters should be divided to fall in the range of 0-MAX_VALUE
    static constexpr int PARAM_DIV = 4096 / MAX_VALUE;

    // The number of encoder steps per click. 
    static constexpr int ENCODER_STEPS = 3;

    Encoder m_Encoder;

    int m_LastEncoderPosition = 0;
    int m_LastEncoderClick = LOW;

    std::uint8_t m_Parameter1 = 0;
    std::uint8_t m_Parameter2 = 0;
    std::uint8_t m_Parameter3 = 0;
    std::uint8_t m_Parameter4 = 0;
};