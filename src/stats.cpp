#include "stats.h"

Stats::Stats() { }

Stats::Stats(int strength, int range, int magic, int defense, int health) : 
    strength_(strength), range_(range), magic_(magic), defense_(defense),
    health_(health) 
{ }

int Stats::getStrength() { return strength_; }
int Stats::getRange()    { return range_; }
int Stats::getMagic()    { return magic_; }
int Stats::getDefense()  { return defense_; }
int Stats::getHealth()   { return health_; }
