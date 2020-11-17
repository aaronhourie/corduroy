#pragma once

#include "Algorithm.h"
#include "Operator.h"
#include "Controls.h"

#include <cstdint>
#include <vector>

class Synth 
{
public:

    Synth();

    std::vector<Operator>& GetOperators() { return m_Operators; }
    std::vector<Algorithm>& GetAlgorithms() { return m_Algorithms; }

    std::uint8_t GetSelectedAlgorithm() const { return m_SelectedAlgorithm; }

private:

    static const int NUM_OPERATORS = 4;
    static const int NUM_ALGORITHMS= 4; // TODO: Should have algorithm provider.

    std::vector<Operator> m_Operators;

    std::vector<Algorithm> m_Algorithms;

    std::uint8_t m_SelectedAlgorithm = 0;

    // TODO: Model the LFO
};