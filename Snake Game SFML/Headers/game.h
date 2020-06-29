#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "harta.h"
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
