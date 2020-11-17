#pragma once

#include <Envelope.h>

class Operator
{
public:

    Operator() = default;

    const Envelope& GetEnvelope() const { return m_Envelope; }

    Envelope& GetEnvelope() { return m_Envelope; }
    
    const std::uint8_t GetFrequency() const { return m_Frequency; }

private:

    Envelope m_Envelope;

    std::uint8_t m_Frequency = 0;
};