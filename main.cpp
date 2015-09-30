#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include "dice.h"
#include "player.h"
#include <cstdlib>

using namespace std;

int  get_num_players();
int  get_dice_sides();
int  take_turn();                        //the function that allows every player to take their turn
bool winner(vector<Player> players);     //will return true if any player has won, score > 100
int  get_winner(vector<Player> players); //called after winner() returns true to find out who won, will return -1 if there was a tie
Dice* dice = new Dice();

//////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
  int num_players, sides;
  vector<Player> players;
  cout << "Welcome to Pigs Game" << endl;

  sides = get_dice_sides();
  dice->set_sides(sides);

  num_players = get_num_players();

  for(int i = 0; i < num_players; i++)
  {
    string name;
    cout << "Player " << i << " name: ";
    cin >> name;
    Player* new_player = new Player(name);
    players.push_back(*new_player);
  }

  int num_turns = 0;
  while(!winner(players))
  {
    cout << "START TURN " << num_turns << "!" << endl << endl;
    vector<Player>::iterator iter;
    for(iter = players.begin(); iter != players.end(); iter++)
    {

      cout << iter->get_name() <<"'s turn start." << endl;
      iter->add_turn(take_turn());
      cout << iter->get_name() << "'s score is " << iter->get_score() << endl << endl;
    }
  }

  int winner = get_winner(players);
  if(winner >= 0)
  {
    string winner_name = players[winner].get_name();
    cout << "Player " << winner << ", " << winner_name << ", won the game!" << endl;
  }
  else
  {
    cout << "There was a tie! NO WINNER" << endl;
  }
  return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////

//will return the number of players where 2<= num <= 10
int get_num_players()
{
  int num_players;
  do
  {
    cout << "How many players are playing? ";
    cin >> num_players;
    if(num_players < 2 || num_players > 10)
      cout << "Need between 2 and 10 players" << endl << endl;
  }while(num_players < 2 || num_players > 10);
  return num_players;
}

//will return the number of sides the dice is suppose to have. 6 <= sides <= 24
int get_dice_sides()
{
  int sides;
  do
  {
    cout << "How many sides on your dice? ";
    cin >> sides;
    if(sides < 6 || sides > 24)
      cout << "Needs to be between 6 and 24 sides" << endl << endl;
  }while(sides < 6 || sides > 24);
  return sides;
}

//allows all users ti take their turn
int take_turn()
{
  char cont;
  int score = 0;
  int cur_roll;
  do
  {
    cout << "Its your turn to roll. Rolling for you now." << endl;
    cur_roll = dice->roll();
    cout << cur_roll << endl;
    if(cur_roll == 1)
    {
      cout << "OH SHIT SUCKS TO BE YOU!!! LOL" << endl;
      return 0;
    }
    else {score += cur_roll;}
    cout << "Your score for this turn is " << score << ", Continue? (y/n) ";
    cin >> cont;
    cout << endl << endl;
  }while(cont == 'y' || cont == 'Y');
  return score;
}

//will return true if any of the players have a score >= 100
bool winner(vector<Player> players)
{
  for(vector<Player>::iterator iter = players.begin(); iter != players.end(); iter++)
  {
    if(iter->get_score() >= 100)
    {
      return true;
    }
  }
  return false;
}


int get_winner(vector<Player> players)
{
  bool tie = false;
  int winner_index;
  int max_score = 0;
  int i = 0;
  vector<Player>::iterator iter;
  for(iter = players.begin(); iter != players.end(); iter++)
  {
    if(iter->get_score() == max_score)
    {
      tie = true;
    }
    if(iter->get_score() > max_score)
    {
      max_score = iter->get_score();
      winner_index = i;
      tie = false;
    }
    i++;
  }
  if(!tie)
    return winner_index;
  else return -1;
}
