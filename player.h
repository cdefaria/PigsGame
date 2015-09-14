/*

*/

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
    public:
        Player();
        bool add_turn(int roll);
    private:
        unsigned int score;
};

#endif
