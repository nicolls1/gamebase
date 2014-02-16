#ifndef MONSTER_H
#define MONSTER_H

#include <SFML/Graphics.hpp>

class Monster {
  public:
    virtual void moveForward() = 0;

    virtual void meleeAttack() = 0;
    virtual void rangeAttack() = 0;
    virtual void magicAttack() = 0;

    // returns true if dead
    virtual bool attacked(int damage) = 0;

    virtual int getLane() = 0;

    virtual void draw(sf::RenderWindow* w) = 0;

};

#endif
