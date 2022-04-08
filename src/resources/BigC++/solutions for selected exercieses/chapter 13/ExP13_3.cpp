/****************************************************************************
** FILE:    clock.cpp
**          Modified for Exercise 8.15
**          Remove the play_round() function out of the Game class and
**          make the Player class responsible for it.
****************************************************************************/

#include "ccc_win.h"
#include "ccc_time.h"

const double PI = 3.141592653589793;

void rand_seed()
{
   int seed = static_cast<int>(time(0));
   srand(seed);
}

int rand_int(int a, int b)
{
     return a + rand() % (b - a + 1);
} 

class Clock
{
public:
   Clock();
   Clock(Point c, double r);

   void set_time(Time t);

   void draw() const;
private:
   void draw_tick(double angle, double length) const;
   void draw_hand(double angle, double length) const;

   Time current_time;
   Point center;
   double radius;
};

class Player
{
public:
   Player();
   Player(string player_name, int initial_level);

   void increment_score();

   int get_level() const;
   string get_name() const;
   void play_round(); /* add from Game class */
   Time random_time(); /* add from Game class */
   Time get_guess(); /* add from Game class */
private:
   string name;
   int score;
   int level;
};

class Game
{
public:
   Game();

   void play();
   void read_player_information();
private:
   Player player;
};

Clock::Clock()
{
   radius = 0;
}

Clock::Clock(Point c, double r)
{
   center = c;
   radius = r;
}

void Clock::set_time(Time t)
{
   current_time = t;
}

void Clock::draw_tick(double angle, double length) const
{
   double alpha = PI / 2 - 6 * angle * PI / 180;
   Point from(center.get_x() + cos(alpha) * radius * (1 - length),
      center.get_y() + sin(alpha) * radius * (1 - length));
   Point to(center.get_x() + cos(alpha) * radius,
      center.get_y() + sin(alpha) * radius);
   cwin << Line(from, to);
}

void Clock::draw_hand(double angle, double length) const
{
   double alpha = PI / 2 - 6 * angle * PI / 180;
   Point from = center;
   Point to(center.get_x() + cos(alpha) * radius * length,
      center.get_y() + sin(alpha) * radius * length);
   cwin << Line(from, to);
}

void Clock::draw() const
{
   cwin << Circle(center, radius);
   int i;
   const double HOUR_TICK_LENGTH = 0.2;
   const double MINUTE_TICK_LENGTH = 0.1;
   const double HOUR_HAND_LENGTH = 0.6;
   const double MINUTE_HAND_LENGTH = 0.75;
   for (i = 0; i < 12; i++)
   {
      draw_tick(i * 5, HOUR_TICK_LENGTH);
      int j;
      for (j = 1; j <= 4; j++)
         draw_tick(i * 5 + j, MINUTE_TICK_LENGTH);
   }
   draw_hand(current_time.get_minutes(), MINUTE_HAND_LENGTH);
   draw_hand((current_time.get_hours() +
      current_time.get_minutes() / 60.0) * 5, HOUR_HAND_LENGTH);
}

Player::Player()
{
   level = 1;
   score = 0;
}

Player::Player(string player_name, int initial_level)
{
   name = player_name;
   level = initial_level;
   score = 0;
}

int Player::get_level() const
{
   return level;
}

string Player::get_name() const
{
   return name;
}

void Player::increment_score()
{
   score++;
   if (score % 5 == 0 && level < 4)
      level++;
}

Time Player::random_time()
{
   int level = get_level();
   int minutes;
   if (level == 1) minutes = 0;
   else if (level == 2) minutes = 15 * rand_int(0, 3);
   else if (level == 3) minutes = 5 * rand_int(0, 11);
   else minutes = rand_int(0, 59);
   int hours = rand_int(1, 12);
   return Time( hours, minutes, 0);
}

Time Player::get_guess()
{
   int hours;
   do
   {
      hours = cwin.get_int("Please enter hours: (1-12)");
   } while (hours < 1 || hours > 12);
   int minutes;
   do
   {
      minutes = cwin.get_int("Please enter minutes: (0-59)");
   } while (minutes < 0 || minutes > 59);

   return Time(hours, minutes, 0);
}

void Player::play_round()
{
   cwin.clear();
   Time t = random_time();
   const double CLOCK_RADIUS = 5;
   Clock clock(Point(0, 0), CLOCK_RADIUS);
   clock.set_time(t);
   clock.draw();

   Time guess = get_guess();
   if (t.seconds_from(guess) != 0)
      guess = get_guess();

   string text;
   if (t.seconds_from(guess) == 0)
   {
      text = "Congratulations, " + get_name() + "! That is correct.";
      increment_score();
      cwin << Message(Point(-CLOCK_RADIUS, CLOCK_RADIUS + 1), text);
   }
   else
   {
      text = "Sorry, " + get_name() + ". The correct answer is ";
      cwin << Message(Point(-CLOCK_RADIUS, CLOCK_RADIUS + 1), text);
      cwin << Message(Point(-CLOCK_RADIUS + 12, CLOCK_RADIUS + 1), t.get_hours());
      cwin << Message(Point(-CLOCK_RADIUS + 12.5, CLOCK_RADIUS + 1), t.get_minutes());
   }
}

Game::Game()
{
}

void Game::play()
{
   read_player_information();
   string response;
   do
   {
      player.play_round();
      response = cwin.get_string("Do you want to play again? (Y/N)");
   } while (response == "Y");
}

void Game::read_player_information()
{
   string name = cwin.get_string("What is your name?");
   int initial_level;
   do
   {
      initial_level =
         cwin.get_int("At what level do you want to start? (1-4)");
    } while (initial_level < 1 || initial_level > 4);
    player = Player(name, initial_level);
}

int ccc_win_main()
{
   Game clock_game;
   rand_seed();
   clock_game.play();

   return 0;
}
