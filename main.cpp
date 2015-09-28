#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include "dice.h"
#include "player.h"
#include <cstdlib>

using namespace std;

int  get_num_players();
bool winner(vector<Player> players);     //will return true if any player has won, score > 100
int  take_turn();                        //the function that allows every player to take their turn
int  get_winner(vector<Player> players); //called after winner() returns true to find out who won, will return -1 if there was a tie

//////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
  int num_players;
  vector<Player> players;
  cout << "Welcome to Pigs Game" << endl;

  num_players = get_num_players();

  for(int i = 0; i < num_players; i++)
  {
    string name;
    cout << "Player " << i << " name: ";
    cin >> name;
    Player* new_player = new Player(name);
    players.push_back(*new_player);
  }

  while(!winner(players))
  {
    vector<Player>::iterator iter;
    for(iter = players.begin(); iter != players.end(); iter++)
    {
      
      iter->add_turn(take_turn());
      
      cout << iter->get_name() << "'s score is " << iter->get_score() << endl << endl;
    }
  }

  int winner = get_winner(players);
  if(winner > 0)
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

int take_turn()
{
  return 20;
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
