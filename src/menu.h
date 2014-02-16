#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <string>

class Menu {
  public:
    Menu();

    void draw(sf::RenderWindow* w);

    void setHealth(std::string health);
    void setMelee(std::string melee);
    void setRange(std::string range);
    void setMagic(std::string magic);
    void setArmor(std::string armor);

    sf::Text& getHealth() { return healthText_; }
    
  private:
    sf::Font font_;

    sf::Text healthText_;
    sf::Text meleeText_;
    sf::Text rangeText_;
    sf::Text magicText_;
    sf::Text armorText_;

    sf::Texture healthIcon_;
    sf::Texture meleeIcon_;
    sf::Texture rangeIcon_;
    sf::Texture magicIcon_;
    sf::Texture armorIcon_;
};

#endif
