#include <iostream>
#include "player.h"

Player::Player(string name)
{
    m_name = name;
    m_score = 0;
}

void Player::add_turn(int roll)
{
    m_score += roll;
    return;
}
