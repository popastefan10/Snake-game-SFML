#include "../Headers/menu.h"

menu::menu() {

}

menu::~menu() {

}

/** ----- accessors (set) and mutators (get) ----- **/

void menu::setSelected(int newSel) {
  selected = newSel;
}

int menu::getSelected() {
  return selected;
}

void menu::setFont(sf::Font newFont) {
  font = newFont;
}

sf::Font menu::getFont() {
  return font;
}

int menu::getNumberOfButtons() {
  return Buttons.size();
}

void menu::add_button(std::string buttonText, float posX, float posY, int screenIndex) {
  button btn(buttonText, posX, posY, screenIndex);
  btn.setFont(font);
  Buttons.push_back(btn);
}

void menu::add_button(button &btn) {
  Buttons.push_back(btn);
}

void menu::add_button(button *pbtn) {
  Buttons.push_back(*pbtn);
}

void menu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.clear();
  for(button Button: Buttons)
    target.draw(Button);
}
