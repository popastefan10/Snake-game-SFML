#include "../Headers/game.h"

game::game() {

}

game::~game() {

}

void game::runGame() {
  gameWindow.create(sf::VideoMode(1920, 1080), "Game", sf::Style::Fullscreen);
  gameWindow.setFramerateLimit(5);

  harta Harta("harta.in");
  snake Snake(Harta);

  while(gameWindow.isOpen()) {
    sf::Event event;

    while(gameWindow.pollEvent(event)) {

      if(event.type == sf::Event::Closed)
        gameWindow.close();

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
          gameWindow.close();

        if(Snake.hasMoved() && validDirections(Snake.getDirection(), newDirection))
          Snake.setDirection(newDirection);
      }
    }

    Snake.moveBody();
    if(Snake.collision())
      gameWindow.close();

    gameWindow.clear();
    gameWindow.draw(Harta);
    gameWindow.draw(Snake);
    gameWindow.display();
  }
}
