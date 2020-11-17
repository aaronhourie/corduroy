#pragma once

#include <cstdint>

#include "SSD1306.h"

class IMenu 
{
public:

    virtual ~IMenu() = default;

    virtual void RenderMenu(SSD1306& display) const = 0;

    virtual void OnParameterAdjusted(std::uint8_t parameter, std::uint8_t value) = 0;

    virtual void OnScroll(bool isRight) = 0;
};