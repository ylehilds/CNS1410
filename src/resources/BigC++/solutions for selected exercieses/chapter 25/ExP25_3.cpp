#include <iostream>
#include <sstream>

using namespace std;

/**
   A row of the plane
*/

const char AVAILABLE = '.';
const char OCCUPIED  = 'o';
const char NONE      = ' ';

const int WINDOW = 0;
const int CENTER = 1;
const int AISLE = 2;

class Row
{
public:

   /** 
      Constructs a row of the plane
      @arg lw the left window character
      @arg lc the left center character
      @arg la the left aisle character
      @arg rw the right window character
      @arg rc the right center character
      @arg ra the right aisle character
   */
   Row();
   Row(char lw, char lc, char la, char rw, char rc, char ra);

   /** 
      Check to see if a request can be fulfilled, and make the assignment if 
      posible
      @arg number the number of people to assign
      @arg preference the seating preference of the group
      @return whether the request was successfully handled
   */
   bool  tryRequest(int number, int preference);

   bool trySection(char section[], int number, int preference);

   /** 
      print out row
   */
   friend ostream& operator<<(ostream& out, Row& right);


private:
   char left[3];
   char right[3];
};

Row::Row() { }

Row::Row(char lw, char lc, char la, char rw, char rc, char ra)
{
   // Always put window in 0 and reverse one side when printing
   left[0] = lw;
   left[1] = lc;
   left[2] = la;

   right[0] = rw;
   right[1] = rc;
   right[2] = ra;
}

bool  Row::tryRequest(int number, int preference)
{
   if (trySection(left, number, preference))
      return true;
   else
      return trySection(right, number, preference);
}

bool Row::trySection(char section[], int number, int preference)
{
   // Hold these temporarily so they are easier to remember and for
   // comparison at the end

   char window = section[0];
   char center = section[1];
   char aisle  = section[2];

   if (number == 1)
   {
      if      (preference == WINDOW & window == AVAILABLE)
         window = OCCUPIED;
      else if (preference == CENTER & center == AVAILABLE)
         center = OCCUPIED;
      else if (preference == AISLE  & aisle  == AVAILABLE)
         aisle = OCCUPIED;
   }
      
   // Economy
   else if (number == 2 && center == AVAILABLE)
   {
      if (preference == WINDOW & window == AVAILABLE)
      {
         window = OCCUPIED;
         center = OCCUPIED;
      }
      else if (preference == AISLE & aisle == AVAILABLE)
      {
         aisle = OCCUPIED;
         center = OCCUPIED;
      }
   }

   // First Class
   else if (number == 2 && center == NONE)
   {
      if (window == AVAILABLE & aisle == AVAILABLE)
      {
         window = OCCUPIED;
         aisle = OCCUPIED;
      }
   }

   else if (number == 3 && window == AVAILABLE && center == AVAILABLE
                        && aisle  == AVAILABLE)
   {
      window = OCCUPIED;
      center = OCCUPIED;
      aisle = OCCUPIED;
   }

   if (section[0] == window & section[1] == center & section[2] == aisle)
      return false;
   else
   {
      section[0] = window;
      section[1] = center;
      section[2] = aisle;
      return true;
   }
}

ostream& operator<<(ostream& out, Row& plane)
{
   out << plane.left[0] << plane.left[1] << plane.left[2] << " " 
      << plane.right[2] << plane.right[1] << plane.right[0];
   return out;
}

const int FIRST_CLASS = 0;
const int ECONOMY = 1;
const int FIRST_ROW_NUMBER = 1;

/**
   The plane
*/
class Plane
{
public:
   /**
      Construct a plane
      @arg firstRowCount the number of elements in first class
      @arg econRowCount the number of elements in economy class
   */
   Plane(int firstRowCount, int econRowCount);

   /**
      handle the request
      @arg theClass whether the request is for first class or economy
      @arg number the number of passengers the request is for
      @arg preference whether the seats should be aisle, center, or window
   */
   void doRequest(int theClass, int number, int preference);

   /**
      print the seats
   */
   void printSeating();

private:
   Row* firstClass;
   Row* economy;

   int firstClassRowCount;
   int economyRowCount;
};

Plane::Plane(int firstRowCount, int econRowCount)
{
   firstClassRowCount = firstRowCount;
   economyRowCount = econRowCount;

   firstClass = new Row[firstRowCount];
   for (int i = 0; i < firstRowCount; i++)
      firstClass[i] = Row(AVAILABLE, NONE, AVAILABLE,
                              AVAILABLE, NONE, AVAILABLE);

   economy= new Row[economyRowCount];
   for (int i = 0; i < economyRowCount; i++)
      economy[i] = Row(AVAILABLE, AVAILABLE, AVAILABLE,
                           AVAILABLE, AVAILABLE, AVAILABLE);

}

void Plane::doRequest(int theClass, int number, int preference)
{
   bool satisfiedRequest = false;

   if (theClass == FIRST_CLASS)
      for (int i = 0; i < firstClassRowCount; i++)
      {
         if (firstClass[i].tryRequest(number, preference))
         {
            satisfiedRequest = true;
            break;
         }
      }
   else
      for (int i = 0; i < economyRowCount; i++)
      {
         if (economy[i].tryRequest(number, preference))
         {
            satisfiedRequest = true;
            break;
         }
      }
   if (!satisfiedRequest)
      cout << "Request not satisfied!\n";
}

void Plane::printSeating()
{
   for (int row = FIRST_ROW_NUMBER; row <= firstClassRowCount; row++)
   {
      if (row < 10) cout << " ";
      cout << row << ":" << firstClass[row-FIRST_ROW_NUMBER] << "\n";
   }

   int firstEconomyRowNumber = FIRST_ROW_NUMBER + firstClassRowCount;
   int lastEconomyRowNumber = firstEconomyRowNumber + economyRowCount - 1;

   for (int row = firstEconomyRowNumber; row <= lastEconomyRowNumber; row++)
   {
      if (row < 10) cout << " ";
      cout << row << ":" << economy[row-firstEconomyRowNumber] << "\n";
   }
}

void doMenu()
{
   Plane plane(5, 30);

   cout << "Welcome to the airline reservation program!";
   cout << "Please enter your command.\n";
   while (true)
   {
      cout << 
         "Enter A)dd passengers, S)how Seating, or Q)uit: ";
      char response;
      int number;
      cin >> response;

      if (response == 'A') 
      {
	 cout << "F)irst class or E)conomy: ";
	 cin >> response;

         if (response == 'F')
         {
            int classType = FIRST_CLASS;
	    cout << "Number in party (1 or 2): ";
	    cin >> number;

	    cout << "Seat preference (W)indow or A)isle): ";
	    cin >> response;

            if (response == 'W')
               plane.doRequest(FIRST_CLASS, number, WINDOW);
            else if (response == 'A')
               plane.doRequest(FIRST_CLASS, number, AISLE);
            else 
	       cout << "Invalid entry.  Try again.";
         }
         else if (response == 'E')
         {
	    cout << "Number in party (1, 2, 3): ";
	    cin >> number;

	    cout << "Seat preference (W)indow, C)enter, or A)isle): ";
	    cin >> response;

            if (response == 'W')
               plane.doRequest(ECONOMY, number, WINDOW);
            else if (response == 'C')
               plane.doRequest(ECONOMY, number, CENTER);
            else if (response == 'A')
               plane.doRequest(ECONOMY, number, AISLE);
            else 
	       cout << "Invalid entry.  Try again.";
         }
         else 
	    cout << "Invalid entry.  Try again.";
      }

      else if (response == 'S') 
         plane.printSeating();

      else if (response == 'Q') 
      {
	 cout << "Goodbye";
         exit(0);
      }

      else
	 cout << "Invalid command";
   }
}

int main() 
{
   doMenu();
   return 0;
}
