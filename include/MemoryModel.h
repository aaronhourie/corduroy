#pragma once

#include <cstdint>
#include <vector>

class MemoryModel
{
public:

    MemoryModel();

private:

    std::vector<std::uint8_t> m_MemoryBank;

};