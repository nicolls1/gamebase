#include "menu.h"
#include <iostream>

#define IMAGE_X 50
#define TEXT_X 110

#define HEALTH_Y 10
#define MELEE_Y 60
#define RANGE_Y 110
#define MAGIC_Y 160
#define ARMOR_Y 210

#define TEXT_SIZE 50
#define DEFAULT_TEXT "00"
#define ICON_SIZE 32

Menu::Menu() {
  if(!font_.loadFromFile("assets/MonospaceTypewriter/MonospaceTypewriter.ttf")) {
    std::cout << "Font Load Failed" << std::endl;
  }

  healthText_.setFont(font_);
  healthText_.setCharacterSize(TEXT_SIZE);
  healthText_.setStyle(sf::Text::Regular);
  healthText_.setString(DEFAULT_TEXT);
  healthText_.setColor(sf::Color::Red);
  healthText_.setPosition(TEXT_X, HEALTH_Y);

  meleeText_.setFont(font_);
  meleeText_.setCharacterSize(TEXT_SIZE);
  meleeText_.setStyle(sf::Text::Regular);
  meleeText_.setString(DEFAULT_TEXT);
  meleeText_.setColor(sf::Color::Red);
  meleeText_.setPosition(TEXT_X, MELEE_Y);

  rangeText_.setFont(font_);
  rangeText_.setCharacterSize(TEXT_SIZE);
  rangeText_.setStyle(sf::Text::Regular);
  rangeText_.setString(DEFAULT_TEXT);
  rangeText_.setColor(sf::Color::Red);
  rangeText_.setPosition(TEXT_X, RANGE_Y);

  magicText_.setFont(font_);
  magicText_.setCharacterSize(TEXT_SIZE);
  magicText_.setStyle(sf::Text::Regular);
  magicText_.setString(DEFAULT_TEXT);
  magicText_.setColor(sf::Color::Red);
  magicText_.setPosition(TEXT_X, MAGIC_Y);

  armorText_.setFont(font_);
  armorText_.setCharacterSize(TEXT_SIZE);
  armorText_.setStyle(sf::Text::Regular);
  armorText_.setString(DEFAULT_TEXT);
  armorText_.setColor(sf::Color::Red);
  armorText_.setPosition(TEXT_X, ARMOR_Y);

  if(!healthIcon_.loadFromFile("assets/Heart.png")) 
    std::cout << "Error loading icon" << std::endl;

  if(!armorIcon_.loadFromFile("assets/Shield.png")) 
    std::cout << "Error loading icon" << std::endl;

}

void Menu::draw(sf::RenderWindow* w) {
  sf::Sprite health(healthIcon_);
  health.setPosition(IMAGE_X + ICON_SIZE/2, HEALTH_Y + ICON_SIZE/2);
  w->draw(health);

  sf::Sprite armor(armorIcon_);
  armor.setPosition(IMAGE_X + ICON_SIZE/2, ARMOR_Y + ICON_SIZE/2);
  w->draw(armor);

  w->draw(healthText_);
  w->draw(meleeText_);
  w->draw(rangeText_);
  w->draw(magicText_);
  w->draw(armorText_);
}
