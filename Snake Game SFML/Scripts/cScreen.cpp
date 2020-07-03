#include "../Headers/cScreen.h"

/// when the first screen will be active its index  will be 0,
/// thus matching its index within "Screens" vector
int cScreen::activeScreens = -1;

cScreen::cScreen() {
  screenIndex = ++activeScreens;
}

cScreen::~cScreen() {
  activeScreens--;
}


/** ----- accessors (set) and mutators (get) ----- **/

void cScreen::setScreenIndex(int newIdx) {
  screenIndex = newIdx;
}

int cScreen::getScreenIndex() {
  return screenIndex;
}
