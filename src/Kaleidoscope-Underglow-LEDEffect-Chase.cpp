#include "Kaleidoscope-Underglow-LEDEffect-Chase.h"

namespace kaleidoscope {
void LEDUnderglowChaseEffect::update(void) {
  if (current_chase_counter++ < chase_threshold) {
    return;
  }
  current_chase_counter = 0;
  ::LEDControl.setCrgbAt(pos - (chase_sign * chase_pixels), {0, 0, 0});
  ::LEDControl.setCrgbAt(pos, {0, 0, 0});

  pos += chase_sign;
  if (pos >= LEFT_KEYS + RIGHT_KEYS + LEFT_UNDERGLOW_LEDS || pos <= LEFT_KEYS + RIGHT_KEYS ) {
    chase_sign = -chase_sign;
  }
  ::LEDControl.setCrgbAt(pos, {0, 0, 255});
  ::LEDControl.setCrgbAt(pos - (chase_sign * chase_pixels), {255, 0, 0});
}
}

kaleidoscope::LEDUnderglowChaseEffect LEDUnderglowChaseEffect;
