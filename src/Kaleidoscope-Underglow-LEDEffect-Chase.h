#pragma once

#include "Kaleidoscope-LEDControl.h"
#include "LEDUtils.h"

namespace kaleidoscope {
class LEDUnderglowChaseEffect : public LEDMode {
 public:
  LEDUnderglowChaseEffect(void) {}

 protected:
  void update(void) final;

 private:
  uint8_t pos = LEFT_KEYS + RIGHT_KEYS;
  int8_t chase_sign = 1; //negative values when it's going backwar
  uint8_t chase_pixels = 5;
  uint8_t current_chase_counter = 0;
  static const uint8_t chase_threshold = 20;
};
}

extern kaleidoscope::LEDUnderglowChaseEffect LEDUnderglowChaseEffect;
