#include "../Headers/start_menu.h"

using namespace std;

start_menu::start_menu() {
  if(!font.loadFromFile("courier.ttf")) {
    std::cerr << "Error loading font" << endl;
  }

  float firstX = 850;
  float firstY = 440;

  add_button("Start new game", firstX, firstY, 0);
  add_button("Options", firstX, firstY + 1 * 30, screenIndex);
  add_button("Help", firstX, firstY + 2 * 30, screenIndex);
  add_button("Quit", firstX, firstY + 3 * 30, -1);
}

start_menu::~start_menu() {

}

/** ----- accessors (set) and mutators (get) ----- **/

void start_menu::setSelected(int newSel) {
  selected = newSel;
}

int start_menu::getSelected() {
  return selected;
}

void start_menu::setFont(sf::Font newFont) {
  font = newFont;
}

sf::Font start_menu::getFont() {
  return font;
}

int start_menu::getNumberOfButtons() {
  return Buttons.size();
}

void start_menu::add_button(std::string buttonText, float posX, float posY, int screenIndex) {
  button btn(buttonText, posX, posY, screenIndex);
  btn.setFont(font);
  Buttons.push_back(btn);
}

/** ----- Run inherited from cScreen ----- **/

int start_menu::Run(sf::RenderWindow &App) {
  App.setFramerateLimit(1000);

  int prevSelected = 0;
  selected = 0;
  Buttons[0].select();

  for(int i = 1; i < (int)Buttons.size(); i++)
    Buttons[i].unselect();

  sf::Event event;
  while(App.isOpen()) {
    while(App.pollEvent(event)) {

      if(event.type == sf::Event::Closed) {
        App.close();
        return -1;
      }

      if(event.type == sf::Event::KeyPressed) {
        int nBtns = Buttons.size();
        prevSelected = selected;

        if(event.key.code == sf::Keyboard::Up)           /// Up
          selected = (selected - 1 + nBtns) % nBtns;
        else if(event.key.code == sf::Keyboard::Down)    /// Down
          selected = (selected + 1) % nBtns;
        else if(event.key.code == sf::Keyboard::Escape) { /// Esc
          App.close();
          return -1;
        }
        else if(event.key.code == sf::Keyboard::Enter)    /// Enter
          return Buttons[selected].getLinkedScreenIndex();
      }

      if(selected != prevSelected) {
        Buttons[prevSelected].unselect();
        Buttons[selected].select();
      }
    }

    App.clear();
    for(auto &Button : Buttons)
      App.draw(Button);
    App.display();
  }

  return -1;
}
