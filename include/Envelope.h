#pragma once

#include <cstdint>

class Envelope 
{
public:

    Envelope() = default;
    ~Envelope() = default;

    void SetAttack(std::uint8_t attack ) { m_Attack = attack; }
    void SetDecay(std::uint8_t decay ) { m_Decay = decay; }
    void SetSustain(std::uint8_t sustain ) { m_Sustain = sustain; }
    void SetRelease(std::uint8_t release ) { m_Release = release; }

    std::uint8_t GetAttack() const { return m_Attack; }
    std::uint8_t GetDecay() const { return m_Decay; }
    std::uint8_t GetSustain() const { return m_Sustain; }
    std::uint8_t GetRelease() const { return m_Release; }

private:

    // Parameter TL - Highest amplitude of the wave. 
    std::uint8_t m_TotalLevel = 0x0;

    // Parameter AR - Attack rate
    std::uint8_t m_Attack = 0x0;

    // Parameter D1R - Decay 1 rate.
    std::uint8_t m_Decay = 0x0;

    // This is a bit of a simplification of the YM2612's real capabilities to make the UI a bit
    // easier. In this case, we always set D2R to 0 so that the sustain is always indefinite.
    // Then, this parameter will instead control T1L to determine the level of sustain.
    std::uint8_t m_Sustain = 0x0; 

    // Paramter RR
    std::uint8_t m_Release = 0x0;
};