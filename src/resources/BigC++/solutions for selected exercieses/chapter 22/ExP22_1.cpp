#include <vector>

using namespace std;

/** 
   Sorts a vector using the selection sort algorithm
   @param a the vector to sort
*/
template<typename T>
void selection_sort(vector<T>& a)
{  
   int next; /* the next position to be set to the minimum */

   for (next = 0; next < a.size() - 1; next++)
   {  
      /* find the position of the minimum */
      int min_pos = min_position(a, next, a.size() - 1);
      if (min_pos != next)
         swap(a[min_pos], a[next]);
   }
}
