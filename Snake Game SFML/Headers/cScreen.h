#ifndef CSCREEN_H_INCLUDED
#define CSCREEN_H_INCLUDED

#include <SFML/Graphics.hpp>

class cScreen {

public:
  virtual int Run(sf::RenderWindow &App) = 0;
};

#endif // CSCREEN_H_INCLUDED
