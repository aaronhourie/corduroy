#include "Controls.h"
#include "EnvelopeMenu.h"
#include "IMenu.h"
#include "Operator.h"
#include "Pins.h"
#include "Synth.h"

#include "SSD1306.h"

#include <Arduino.h>
#include <memory>

// TODO: Move these global variables out into an app class.
Synth synth;
SSD1306 display { 0x3c, gpio::I2C_SCL, gpio::I2C_SDA };
Controls controls;

std::vector<std::unique_ptr<IMenu>> m_Menus {};

std::uint8_t m_CurrentMenu = 0;

bool couldInit = false;

void setup() {
  
  Serial.begin(115200);
  Serial.println("\nBooting...");

  m_Menus.push_back(std::unique_ptr<EnvelopeMenu>(new EnvelopeMenu(synth.GetOperators())));

  couldInit = display.init();
  if ( couldInit ) {
    display.setFont( ArialMT_Plain_24 );
    display.setTextAlignment( TEXT_ALIGN_LEFT );
    display.flipScreenVertically();
    display.clear();

    display.display();
  }
  else {
    Serial.println("Failed to initialize display!");
  }

  controls.InitControlValues();
}

void loop() {

  if ( couldInit ) {
    controls.PollControls(*m_Menus.at(m_CurrentMenu));
    m_Menus.at(m_CurrentMenu)->RenderMenu(display);
  }
  else {
    // Don't bog down the CPU if we fail to load. 
    delay(1);
  }
}