#include <iostream>
#include "player.h"

Player::Player()
{
    score = 0;
}

bool Player::add_turn(int roll)
{
    score = score + roll;
    if(score>=100)
        return true;
    return false;
}
