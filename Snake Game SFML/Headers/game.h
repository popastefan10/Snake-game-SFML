#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "harta.h"
#include "snake.h"
#include "cScreen.h"

class game : public cScreen {

private:
  harta Harta;
  snake Snake;

  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
  game();
  ~game();

  int Run(sf::RenderWindow &App);
};

#endif // GAME_H_INCLUDED
