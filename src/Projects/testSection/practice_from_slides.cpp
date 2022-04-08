#include <iostream>
using namespace std;

int main( )
{
     int examScores[ ] = {72, 98, 56, 87, 64, 83, 77, 91, 66, 70};
     int chosen, temp;

     for ( int leftmost = 0; leftmost < 10; leftmost++ )
      {
               chosen = leftmost;
	 for ( int j = leftmost + 1; j < 10; j++ )
	      if (examScores[j] < examScores[chosen])
		chosen = j;
                temp = examScores[chosen];
	  examScores[chosen] = examScores[leftmost];
	  examScores[leftmost] = temp;
      }
	cout << "Numerical Order Algorithm!!!" <<"\n";
      // print the sorted array
      for ( int i = 0; i < 10; i++ )
	cout << examScores[i] << " " ;

	  system("PAUSE");
      //getch( );
      return 0;
}
