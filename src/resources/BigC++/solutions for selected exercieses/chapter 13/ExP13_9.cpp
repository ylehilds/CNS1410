#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

const int WINDOW = 0;
const int CENTER = 1;
const int AISLE = 2;

const int FIRST = 0;
const int ECONOMY = 1;

const int FIRST_CLASS_ROWS = 5;
const int ECONOMY_CLASS_ROWS = 30;

class SeatRow
{
public:
   SeatRow();
   SeatRow(int passengers);
   bool add_passengers(int npassenger, int where);
   bool add(int from, int to);
   void print() const;
private:
   vector<bool> occupied;
};

SeatRow::SeatRow()
{
}

SeatRow::SeatRow(int passengers)
{
   int i;
   for (i = 0; i < passengers; i++)
      occupied.push_back(false);
}

bool SeatRow::add(int from, int to)
{
   int i;
   for (i = from; i <= to; i++)
      if (occupied[i]) return false;
   for (i = from; i <= to; i++)
      occupied[i] = true;
   return true;
}

bool SeatRow::add_passengers(int npassenger, int where)
{
   if (occupied.size() < 6 && (where == CENTER || npassenger > 2))
      return false;
   if (npassenger > 3) return false;
   if (npassenger == 3 && where == CENTER)
      where = WINDOW;
      
   if (where == WINDOW)
      return add(0, npassenger - 1) || add(occupied.size() - npassenger, occupied.size());
   else if (where == AISLE)
      return add(occupied.size() / 2 - npassenger, occupied.size() / 2 - 1)
         || add(occupied.size() / 2, occupied.size() / 2 + npassenger - 1);
   else if (where == CENTER)
      return add(1 - npassenger + 1, 1) || add(1, 1 + npassenger - 1)
      || add(4, 4 + npassenger - 1) || add(4 - npassenger + 1, 4);
   else return false;      
}

void SeatRow::print() const
{
   for (int i = 0; i < occupied.size(); i++)
   {
      if (occupied[i])
         cout << "*";
      else
         cout << ".";
      if (occupied.size() == 4 || occupied.size() == 6 && i == 2)
         cout << " ";
   }
   cout << "\n";
}

class Airplane
{
public:
   Airplane();
   void add_passengers(int tclass, int npassenger, int where);
   void print() const;
private:
   vector<SeatRow> first_class;
   vector<SeatRow> economy_class;
};

Airplane::Airplane()
{
   int i;
   for (i = 0; i < FIRST_CLASS_ROWS; i++)
      first_class.push_back(SeatRow(4));
   for (i = 0; i < ECONOMY_CLASS_ROWS; i++)
      economy_class.push_back(SeatRow(6));
}

void Airplane::add_passengers(int tclass, int npassenger, int where)
{
   int i;
   if (tclass == FIRST)
   {
      for (i = 0; i < first_class.size(); i++)
         if (first_class[i].add_passengers(npassenger, where)) return;
   }
   else
   {
      for (i = 0; i < economy_class.size(); i++)
         if (economy_class[i].add_passengers(npassenger, where)) return;
   }
   cout << "Assignment did not succeed.\n";
}

void Airplane::print() const
{
   int i;
   for (i = 0; i < first_class.size(); i++)
   {
      cout << setw(3) << i + 1 << ": ";
      first_class[i].print();
   }
   for (i = 0; i < economy_class.size(); i++)
   {
      cout << setw(3) << i + 1 + FIRST_CLASS_ROWS << ": ";
      economy_class[i].print();
   }
}

int main()
{
   Airplane plane;

   bool more = true;
 
   while (more)
   {
      cout << "Add, Show, or Quit? (a/s/q) ";
      string input;
      cin >> input;
      if (input == "a")
      {
         string tclass;
         cout << "First Economy? (f/e) ";
         cin >> tclass;
         if (tclass == "f")
         {
            int num;
            cout << "Passengers? (1/2) ";
            cin >> num;
            if (1 <= num && num <= 2)
            {
               string seat_pref;
               cout << "Aisle or Window? (a/w) ";
               cin >> seat_pref;
               if (seat_pref == "a")
                  plane.add_passengers(FIRST, num, AISLE);
               else if (seat_pref == "w")
                  plane.add_passengers(FIRST, num, WINDOW);
            }
         }
         else if (tclass == "e")
         {
            int num;
            cout << "Passengers? (1/2/3) ";
            cin >> num;
            if (1 <= num && num <= 3)
            {
               string seat_pref;
               cout << "Aisle, Center or Window? (a/c/w) ";
               cin >> seat_pref;
               if (seat_pref == "a")
                  plane.add_passengers(ECONOMY, num, AISLE);
               if (seat_pref == "c")
                  plane.add_passengers(ECONOMY, num, CENTER);
               else if (seat_pref == "w")
                  plane.add_passengers(ECONOMY, num, WINDOW);
            }
         }
      }
      else if (input == "s")
         plane.print();
      else if (input == "q")
         more = false;
   }
   return 0;
}  
