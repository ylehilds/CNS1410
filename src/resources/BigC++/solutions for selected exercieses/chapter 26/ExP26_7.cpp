#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

void rand_seed()
{
   int seed = static_cast<int>(time(0));
   srand(seed);
}

int rand_int(int a, int b)
{
   return a + rand() % (b - a + 1);
} 

bool is_power_of_two(int pile)
{
   int p = 1;
   while (p < pile) p = 2 * p;
   return p == pile;
}

/*
  The class Player is the embodiment of the strategy
  design pattern. Different subclasses of Player
  implement the function number_to_take in
  different ways
*/
class Player // the strategy class
{
public:
   virtual int number_to_take(int pile) = 0;
};

/*
  A SmartPlayer follows the intelligent stragey
*/
class SmartPlayer : public Player
{
public:
   virtual int number_to_take(int pile);
};

int SmartPlayer::number_to_take(int pile)
{
   return pile - (int) (pow(2, floor(log((double) pile)/log(2.0))) - 1);
}

/*
  A RandomPlayer just selects a value randomly
*/
class RandomPlayer : public Player
{
public:
   virtual int number_to_take(int pile);
};

int RandomPlayer::number_to_take(int pile)
{
   return rand_int(1, pile / 2);
}

/*
  An askPlayer will ask the user to select a value
*/
class AskPlayer : public Player
{
public:
   virtual int number_to_take(int pile);
};

int AskPlayer::number_to_take(int pile)
{
   cout << "Humm.  I don't know what to do.\n";
   cout << "There are " << pile << " marbles.  How many should I take?\n";
   int number;
   cin >> number;
   cout << "ok. I'll do that\n";
   return number;
}

int main()
{
   int pile;
   int take;
   Player* computerPlayer;

   rand_seed();

   pile = rand_int(10, 100);  /* generate size of pile of marbles */

   bool computer_turn = rand_int(0,1) == 0; /* if 0, computer goes first; else, player */

   // select what type of player to use
   bool player_type = rand_int(0,2);
   if (player_type == 0) computerPlayer = new SmartPlayer;
   else if (player_type == 1) computerPlayer = new RandomPlayer;
   else computerPlayer = new AskPlayer;

   cout << "Nim.  Players alternate taking at least one but at most half of\n" 
       << "the marbles in the pile.  The player who takes the last marble" 
       << "loses.\n";

   if (computer_turn)
      cout << "The computer will play first.\n";
   else
      cout << "You will play first.\n";

   while (pile > 1)
   {
      cout << "There are " << pile << " marbles in the pile.\n";

      if (computer_turn)
      {
         cout << "Computer plays...\n";
	 take = computerPlayer->number_to_take(pile);
         cout << "The computer takes " << take << " marbles.\n";
      }
      else
      {
         cout << "Your play .. you may take 1 to " << pile / 2 << " marbles.\n";
         cout << "You take: ";
         cin >> take;
         if (take < 1 || take > pile / 2)
         {
            cout << "Ooops...you picked too many or not enough.\n";
            take = rand_int(1, pile / 2);
            cout << "You will take " << take << " marbles.\n";
         }
      }
      pile = pile - take;
      computer_turn = !computer_turn;
   }
   
   if (computer_turn)  /* computer's turn */
       cout << "Computer must take the last marble. "
          << "You win!\n";
   else   /* player's turn */
       cout << "You must take the last marble. "
          << "You lose!\n";

   return 0;
}
