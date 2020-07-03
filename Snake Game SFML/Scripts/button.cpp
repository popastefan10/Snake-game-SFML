#include "../Headers/button.h"

/// this will create a button with the "btnText" text at (X, Y) coordinates
/// that leads to the screen indexed with scrIdx index when pressed
button::button(std::string btnText, float X, float Y, int scrIdx) {
  buttonText = btnText;
  posX = X;
  posY = Y;
  linkedScreenIndex = scrIdx;

  selected = false;
}

button::~button() {

}

/** ----- accessors (set) and mutators (get) ----- **/

void button::setFont(sf::Font newFont) {
  font = newFont;
}

sf::Font button::getFont() {
  return font;
}

void button::setButtonText(std::string newBtnTxt) {
  buttonText = newBtnTxt;
}

std::string button::getButtonText() {
  return buttonText;
}

void button::setX(float newX) {
  posX = newX;
}

float button::getX() {
  return posX;
}

void button::setY(float newY) {
  posY = newY;
}

float button::getY() {
  return posY;
}

void button::setLinkedScreenIndex(int newIdx) {
  linkedScreenIndex = newIdx;
}

int button::getLinkedScreenIndex() {
  return linkedScreenIndex;
}

void button::select() {
  selected = true;
}

void button::unselect() {
  selected = false;
}

bool button::getSelected() {
  return selected;
}

/** ----- draw inherited from sf::Drawable ----- **/

void button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  sf::Text text;

  text.setFont(font);
  text.setString(buttonText);
  text.setPosition(posX, posY);
  text.setStyle(sf::Text::Bold);
  text.setCharacterSize(24);

  if(selected)
    text.setFillColor(sf::Color::Red);
  else
    text.setFillColor(sf::Color::White);

  target.draw(text);
}
