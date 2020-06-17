#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Harta.h"
#include "snake.h"

class game {

private:
  sf::RenderWindow gameWindow;

public:
  game();
  ~game();

  void runGame();
};

#endif // GAME_H_INCLUDED
