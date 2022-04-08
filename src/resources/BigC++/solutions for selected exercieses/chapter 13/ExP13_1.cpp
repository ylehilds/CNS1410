#include <iostream>
#include <string>
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

class Player
{
public:
   Player();
   Player(string player_name, int initial_level);
   void increment_score();
   int get_score() const;
   int get_level() const;
   string get_name() const;

private:
   string name;
   int score;
   int level;
};

Player::Player()
{
   name = "";
   score = 0;
   level = 1;
}

Player::Player(string player_name, int initial_level)
{
   name = player_name;
   score = 0;
   level = initial_level;
}

void Player::increment_score()
{
   score++;
   if (score % 5 == 0 && level < 3)
      level++;
}

int Player::get_level() const
{
   return level;
}

int Player::get_score() const
{
   return score;
}

string Player::get_name() const
{
   return name;
}


class Game
{
public:
   Game();
   void play();
   void read_player_information();
   void play_round();
   int get_guess(int v1, int v2, int answer, string operation);

private:
   Player player;
};

Game::Game()
{
    player = Player();
}

void Game::play()
{
   read_player_information();
   string response;
   do
   {
      play_round();
      cout << "Do you want to play again? (y/n) ";
      cin >> response;
   } while (response == "y");
}

void Game::read_player_information()
{
   cout << "What is your name? ";
   string name;
   cin >> name;
   int initial_level = 0;
   do
   {
      cout << "At what level do you want to start? (1-3) ";
      cin >> initial_level;
   } while (initial_level < 1 || initial_level > 3);
   player = Player(name, initial_level);
}

void Game::play_round()
{
   int i1 = 0;
   int i2 = 0;
   int answer = 0;

   if (player.get_level() == 1)
      do
      {
         i1 = rand_int(1,9);
         i2 = rand_int(1,9);
         answer = i1 + i2;
      } while (answer > 9);
   else if (player.get_level() == 2)
   {
      i1 = rand_int(1,9);
      i2 = rand_int(1,9);
      answer = i1 + i2;
   }
   else if (player.get_level() == 3)
   do
   {
      i1 = rand_int(1,9);
      i2 = rand_int(1,9);
      answer = i1 - i2;
   } while (answer < 0);

   int guess;
   if (player.get_level() < 3)
      guess = get_guess(i1, i2, answer, "sum");
   else
      guess = get_guess(i1, i2, answer, "difference");

   if (answer == guess)
   {
      player.increment_score();
      cout << "Congratulations, " << player.get_name() << "! That is correct." << "\n";
   }
   else
   {
      cout << "Sorry, " << player.get_name() << ". The correct answer is "
         << answer << ".\n";        
   }
   cout << "Your score is " << player.get_score() << "\n";
}

int Game::get_guess(int v1, int v2, int answer, string operation)
{
   int guess;
   int tries = 2;
   do
   {
      cout << "Please enter the " << operation 
         << " of " << v1 << " and " << v2 << "\n";
      cin >> guess;
      if (answer == guess)
         return guess;
      else
         cout << "Oops.  That was not right.  Try again.\n";
      tries--;
   } while (tries > 0);
      
   return guess;
}

int main()
{
   Game mathquiz;
   rand_seed();
   mathquiz.play();

   return 0;
}
