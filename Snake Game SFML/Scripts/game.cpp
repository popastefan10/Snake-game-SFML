#include "../Headers/game.h"

game::game() {

}

game::~game() {

}

void game::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.clear();
  target.draw(Harta);
  target.draw(Snake);
}

int game::Run(sf::RenderWindow &App) {
  Harta = harta("harta.in");
  Snake = snake(Harta);

  App.setFramerateLimit(5);

  while(App.isOpen()) {
    sf::Event event;

    while(App.pollEvent(event)) {

      if(event.type == sf::Event::Closed) {
        App.close();
        return -1;
      }

      if(event.type == sf::Event::KeyPressed) {
        int newDirection = -1;

        if(event.key.code == sf::Keyboard::Up)
          newDirection = 0;
        else if(event.key.code == sf::Keyboard::Right)
          newDirection = 1;
        else if(event.key.code == sf::Keyboard::Down)
          newDirection = 2;
        else if(event.key.code == sf::Keyboard::Left)
          newDirection = 3;
        else if(event.key.code == sf::Keyboard::Escape)
          return 1;

        if(Snake.hasMoved() && validDirections(Snake.getDirection(), newDirection))
          Snake.setDirection(newDirection);
      }
    }

    Snake.moveBody();
    if(Snake.collision())
      return 1;

    App.draw(*this);
    App.display();
  }

  App.close();
  return -1;
}
