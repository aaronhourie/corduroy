#pragma once

#include "IMenu.h"

#include "Operator.h"

#include <vector>

/**
 * Menu for displaying and editing operator envelopes.
 */
class EnvelopeMenu : public IMenu
{
public:

    EnvelopeMenu(std::vector<Operator>& m_Operators);

    virtual ~EnvelopeMenu() = default;

    virtual void RenderMenu(SSD1306& display) const override;

    virtual void OnParameterAdjusted(std::uint8_t parameter, std::uint8_t value) override;

    virtual void OnScroll(bool isRight) override;

private:

    // True if the menu title should be displayed.
    bool displayMessage = true;

    // Keep track of the currently selected operator.
    std::uint8_t m_CurrentSelection { 0 };

    // Ref to the operators to edit.
    std::vector<Operator>& m_Operators;

};