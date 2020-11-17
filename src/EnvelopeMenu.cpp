#include "EnvelopeMenu.h"

EnvelopeMenu::EnvelopeMenu(std::vector<Operator>& operators)  :
    m_Operators(operators)
{
    // This space intentionally left blank.
}

void EnvelopeMenu::RenderMenu(SSD1306& display) const
{
    display.clear();

    // Either draw the menu title, or the parameters -- if they have been changed.
    if ( displayMessage ) 
    {
        display.drawString(40, 8, "ENV");
    }
    else 
    {
        const Envelope& envelope =
            m_Operators.at(m_CurrentSelection).GetEnvelope();

        char text[15];

        sprintf(text, "OP - %d", m_CurrentSelection);
        display.drawString(0, 0, text);

        display.setFont(ArialMT_Plain_24);

        sprintf(text, "%d", envelope.GetAttack());
        display.drawString(0, 32, text);

        sprintf(text, "%d", envelope.GetDecay());
        display.drawString(32, 32, text);

        sprintf(text, "%d", envelope.GetSustain());
        display.drawString(64, 32, text);

        sprintf(text, "%d", envelope.GetRelease());
        display.drawString(96, 32, text);
    }

    display.display();
}

void EnvelopeMenu::OnParameterAdjusted(std::uint8_t parameter, std::uint8_t value)
{
    // Cease displaying the menu title.
    displayMessage = false;

    Envelope& envelope = m_Operators.at(m_CurrentSelection).GetEnvelope();

    switch ( parameter) {
        case 0:
        envelope.SetAttack(value);
        break;

        case 1:
        envelope.SetDecay(value);
        break;

        case 2:
        envelope.SetSustain(value);
        break;

        case 3:
        envelope.SetRelease(value);
        break;

        default:
        // TODO: Should log something here, probably.
        break;
    }
}

void EnvelopeMenu::OnScroll(bool isRight)
{
    // Cease displaying the menu title.
    displayMessage = false;

    // Scroll the operators and wrap back to the start.
    m_CurrentSelection = ( m_CurrentSelection + (isRight ? 1 : - 1) ) % m_Operators.size();
}