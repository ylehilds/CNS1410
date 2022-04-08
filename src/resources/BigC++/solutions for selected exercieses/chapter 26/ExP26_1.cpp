// it makes the code easier to read if you create a typedef for the array.

#include <iostream>

using namespace std;

typedef char tictacboard[3][3];

class BoardIterator {
public:
   BoardIterator(tictacboard& bd);
   bool is_done() const;
   void next();
   char get() const;
private:
   tictacboard& theboard;
   int i;
   int j;
};

BoardIterator::BoardIterator(tictacboard& bd) : theboard(bd), i(0), j(0) { }

bool BoardIterator::is_done() const
{
   return (i >= 3);
}

char BoardIterator::get() const
{
   return theboard[i][j];
}

void BoardIterator::next()
{
   j++;
   if (j >= 3)
   {
      i++;
      j = 0;
   }
}

int main() {
   tictacboard board;
   board[0][0] = 'x';
   board[0][1] = 'x';
   board[0][2] = '0';
   board[1][0] = ' ';
   board[1][1] = 'x';
   board[1][2] = '0';
   board[2][0] = ' ';
   board[2][1] = 'x';
   board[2][2] = '0';

   // just prints out one position
   BoardIterator iter(board);
   while (! iter.is_done())
   {
      cout << iter.get();
      iter.next();
   }
   cout << "\n";
   return 0;
}
