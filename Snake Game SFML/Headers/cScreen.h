#ifndef CSCREEN_H_INCLUDED
#define CSCREEN_H_INCLUDED

#include <SFML/Graphics.hpp>

class cScreen {

protected:
  int screenIndex;

public:
  static int activeScreens; /// this variable tells me how many screens are currently active
  /// new screens will be indexed relative to this variable, therefore it might be possible
  /// that the same screen will have 2 different indexes during runtime

  cScreen();
  ~cScreen();

  void setScreenIndex(int);
  int getScreenIndex();

  virtual int Run(sf::RenderWindow &App) = 0;
};

#endif // CSCREEN_H_INCLUDED
