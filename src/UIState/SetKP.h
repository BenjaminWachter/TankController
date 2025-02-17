/**
 * SetKP.h
 *
 * Set the KP for the PID
 */
#pragma once
#include "NumberCollectorState.h"

class SetKP : public NumCollectorState {
public:
  SetKP(TankControllerLib* tc) : NumCollectorState(tc) {
  }
  const char* name() {
    return "SetKP";
  }
  float getCurrentValue() {
    return 0.0;
  }
  uint16_t getCurrentValuePrecision() {
    return 1;
  }
  const char* prompt() {
    return "Set KP          ";
  };
  void setValue(float value);
};
