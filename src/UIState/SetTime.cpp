/**
 * SetTime.cpp
 */

#include "SetTime.h"

#include "Devices/DateTime_TC.h"
#include "Devices/EEPROM_TC.h"
#include "Devices/LiquidCrystal_TC.h"
#include "Devices/Serial_TC.h"

void SetTime::setValue(float value) {
  values[subState++] = value;
  if (subState < NUM_VALUES) {
    clear();
    start();
  } else {
    DateTime_TC dt(values[0], values[1], values[2], values[3], values[4]);
    dt.setAsCurrent();

    char *buffer = DateTime_TC::now().as16CharacterString();
    serial("Set time to %s", buffer);
    LiquidCrystal_TC::instance()->writeLine("New Date/Time:  ", 0);
    LiquidCrystal_TC::instance()->writeLine(buffer, 1);
    returnToMainMenu(3000);  // after 3-second delay
  }
}
