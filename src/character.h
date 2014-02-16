#ifndef CHARACTER_H
#define CHARACTER_H

#include "item.h"
#include "stats.h"
#include <SFML/Graphics.hpp>
#include <json/json.h>
#include <string>
#include <vector>

class Character {
  public:
    Character(std::string name);
    Character(Json::Value json);
    
    void moveLeft();
    void moveRight();

    void meleeAttack();
    void rangeAttack();
    void magicAttack();

    bool attacked();

    void draw(sf::RenderWindow* w);

  private:
    std::vector<sf::Texture> idleImages_;
    std::vector<std::vector<sf::Texture> > runningImages_;
    std::vector<std::vector<sf::Texture> > meleeImages_;
    std::string name_;

    int runningFrame_;
    int meleeFrame_;

    bool meleeAttack_;

    int position_;
    int health_;
    
    Stats baseStats_;

    std::vector<Item> items_;
    std::vector<Item> armor_;
};

#endif
