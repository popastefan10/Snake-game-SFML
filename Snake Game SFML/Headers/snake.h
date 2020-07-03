#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#define INITIAL_BODY_LENGTH 4

#include <vector>
#include "snakeBody.h"
#include "harta.h"
#include <SFML/Graphics.hpp>

class snake : public sf::Drawable {

private:
  std::vector <snakeBody> body;
  int direction;
  bool moved; /// this variable purpose is to prevent 180 degrees direction changes
  /// for example if the snake is going right and you press very fast up and left
  /// it shouldn't be able to turn left without going first one tile up

  snakeBody oldTail;
  harta Harta;

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
  snake(harta);
  ~snake();

  int getBodyLength();

  void setDirection(int);
  int getDirection();

  snakeBody getCrtBody(int);
  snakeBody getSnakeHead();

  void deleteTail();
  //void draw();

  bool collision();

  bool hasMoved();

  void moveBody();
  void growTail();

  void printCoords();
};

#endif // SNAKE_H_INCLUDED
