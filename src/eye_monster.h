#ifndef EYE_MONSTER_H
#define EYE_MONSTER_H

#include "monster.h"
#include <SFML/Graphics.hpp>

class EyeMonster : public Monster {
  public:
    EyeMonster();
    EyeMonster(int lane);

    virtual void moveForward();

    virtual void meleeAttack();
    virtual void rangeAttack();
    virtual void magicAttack();
    
    // returns true if dead
    virtual bool attacked(int damage);

    virtual int getLane();

    virtual void draw(sf::RenderWindow* w);

  private:
    int lane_;
    int health_;
};

#endif
