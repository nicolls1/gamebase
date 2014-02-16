#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "stats.h"

#define ITEM_MELEE 0
#define ITEM_RANGED 1
#define ITEM_MAGIC 2

#define NO_ARMOR -1
#define ARMOR_SLOT_HEAD 0
#define ARMOR_SLOT_CHEST 1
#define ARMOR_SLOT_LEGS 2
#define ARMOR_SLOT_GLOVES 3
#define ARMOR_SLOT_BOOTS 4
#define ARMOR_SLOT_NECKLACE 5
#define ARMOR_SLOT_RING 6

#define ITEM_SLOTS 3
#define ARMOR_SLOTS 7

class Item {
  public:
    Item();
    Item(std::string name, int itemType, int armorType, Stats stats);

    std::string getName();
    int getType();
    int getArmorType();
    Stats getStats();
    
  private:
    std::string name_;

    int itemType_;
    int armorType_;

    Stats stats_;
};

#endif
