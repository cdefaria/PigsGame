/*

*/

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

using namespace std;

class Player
{
    public:
        Player(string);
        void add_turn(int roll);
        int  get_score()  {return m_score;}
        string get_name() {return m_name;}
    private:
        int      m_score;
        string   m_name;
};

#endif
