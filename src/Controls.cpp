
#include "Controls.h"

#include "Pins.h"

#include "driver/adc.h"

Controls::Controls()  :
	m_Encoder(gpio::ROTARY_LEFT, gpio::ROTARY_RIGHT)
{
    pinMode(gpio::PARAMETER_1, INPUT);
    pinMode(gpio::PARAMETER_2, INPUT);
    pinMode(gpio::PARAMETER_3, INPUT);
    pinMode(gpio::PARAMETER_4, INPUT);

    pinMode(gpio::ROTARY_CLICK, INPUT_PULLUP);

    adc1_config_width(ADC_WIDTH_BIT_9);
    adc1_config_channel_atten(adc::PARAMETER_1, ADC_ATTEN_DB_11);
    adc1_config_channel_atten(adc::PARAMETER_2, ADC_ATTEN_DB_11);
    adc1_config_channel_atten(adc::PARAMETER_3, ADC_ATTEN_DB_11);
    adc1_config_channel_atten(adc::PARAMETER_4, ADC_ATTEN_DB_11);
}

void Controls::InitControlValues() 
{
    // Initialize the values so we don't accidentily overwrite the 
    // settings in the first menu.
    m_Parameter1 = analogRead(gpio::PARAMETER_1) / PARAM_DIV;
    m_Parameter2 = analogRead(gpio::PARAMETER_2) / PARAM_DIV;
    m_Parameter3 = analogRead(gpio::PARAMETER_3) / PARAM_DIV;
    m_Parameter4 = analogRead(gpio::PARAMETER_4) / PARAM_DIV;
}

void Controls::PollControls(IMenu& menu)
{
    if (UpdateParameter(m_Parameter1, gpio::PARAMETER_1)) {
        menu.OnParameterAdjusted(0, m_Parameter1);
    }

    if (UpdateParameter(m_Parameter2, gpio::PARAMETER_2)) {
        menu.OnParameterAdjusted(1, m_Parameter2);
    }

    if (UpdateParameter(m_Parameter3, gpio::PARAMETER_3)) {
        menu.OnParameterAdjusted(2, m_Parameter3);
    }

    if (UpdateParameter(m_Parameter4, gpio::PARAMETER_4)) {
        menu.OnParameterAdjusted(3, m_Parameter4);
    }

    int encoderPosition = m_Encoder.read();

    if ( encoderPosition > m_LastEncoderPosition + ENCODER_STEPS) {
        menu.OnScroll(true);
        m_LastEncoderPosition = encoderPosition;
    }
    else if ( encoderPosition < m_LastEncoderPosition - ENCODER_STEPS ) {
        menu.OnScroll(false);
        m_LastEncoderPosition = encoderPosition;
    }

    int encoderClick = digitalRead(gpio::ROTARY_CLICK);

    if ( m_LastEncoderClick == HIGH && encoderClick == LOW )
    {
        // For now, we click! Later we scroll menus.
        Serial.println("Click!");
    }

    m_LastEncoderClick = encoderClick;
}

bool Controls::UpdateParameter(std::uint8_t& destParameter, std::uint8_t gpioPin) 
{
    // Read a new value from the analog pin
    int value = analogRead(gpioPin) / PARAM_DIV;

    // Check the epsilon to try and reduce noise. 
    // Probably need to come up with something better later.
    if ( std::abs(destParameter - static_cast<std::uint8_t>(value)) > PARAMETER_EPSILON) {
        destParameter = value;
        return true;
    }

    return false;
}