#include "../Headers/game.h"

game::game() {

}

game::~game() {

}

void game::runGame() {
  gameWindow.create(sf::VideoMode(600, 600), "Game");

  Harta harta("harta.in");
  snake Snake(harta);

  while(gameWindow.isOpen()) {
    sf::Event event;

    while(gameWindow.pollEvent(event)) {
      if(event.type == sf::Event::Closed)
        gameWindow.close();
    }

    gameWindow.draw(Snake);
    gameWindow.display();
  }
}
