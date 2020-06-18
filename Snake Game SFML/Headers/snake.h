#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

#define INITIAL_BODY_LENGTH 4

#include <vector>
#include "snakeBody.h"
#include "Harta.h"
#include <SFML/Graphics.hpp>

class snake : public sf::Drawable {

private:
  std::vector <snakeBody> body;
  int direction;
  snakeBody oldTail;
  Harta harta;

  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
  snake(Harta);
  ~snake();

  int getBodyLength();

  void setDirection(int);
  int getDirection();

  snakeBody getCrtBody(int);
  snakeBody getSnakeHead();

  void deleteTail();
  //void draw();

  bool collision();

  void moveBody();
  void growTail();

  void printCoords();
};

#endif // SNAKE_H_INCLUDED
