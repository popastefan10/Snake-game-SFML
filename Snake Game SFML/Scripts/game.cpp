#include "../Headers/game.h"

game::game() {

}

game::~game() {

}

void game::runGame() {
  gameWindow.create(sf::VideoMode(600, 600), "Game");
  gameWindow.setFramerateLimit(120);

  Harta harta("harta.in");
  snake Snake(harta);

  while(gameWindow.isOpen()) {
    sf::Event event;

    while(gameWindow.pollEvent(event)) {

      if(event.type == sf::Event::Closed)
        gameWindow.close();

      if(event.type == sf::Event::KeyPressed) {
        int newDirection = 0;

        if(event.key.code == sf::Keyboard::Up)
          newDirection = 0;
        else if(event.key.code == sf::Keyboard::Right)
          newDirection = 1;
        else if(event.key.code == sf::Keyboard::Down)
          newDirection = 2;
        else if(event.key.code == sf::Keyboard::Left)
          newDirection = 3;
        else if(event.key.code == sf::Keyboard::Escape)
          gameWindow.close();

        if(validDirections(Snake.getDirection(), newDirection))
          Snake.setDirection(newDirection);
      }
    }

    Snake.moveBody();

    gameWindow.clear();
    gameWindow.draw(Snake);
    gameWindow.display();
  }
}
