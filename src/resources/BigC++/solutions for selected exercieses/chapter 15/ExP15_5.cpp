#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Entry
{  
public:
   Entry();
   Entry(string n1, string n2);
   string get_first() const;
   string get_second() const;

private:
   string first;
   string second;
};

Entry::Entry()
{
}

Entry::Entry(string n1, string n2)
{
   first = n1;
   second = n2;
}

string Entry::get_first() const
{
   return first;
}

string Entry::get_second() const
{
   return second;
}

void merge(vector<Entry>& a, int from, int mid, int to)
{
   int n = to - from + 1; /* size of the range to be merged */
   /* merge both halves into a temporary vector b */
   vector<Entry> b(n);

   int i1 = from;
      /* next element to consider in the first half */
   int i2 = mid + 1;
      /* next element to consider in the second half */
   int j = 0; /* next open position in b */

   /* as long as neither i1 nor i2 past the end, move the smaller
      element into b
   */
   while (i1 <= mid && i2 <= to)
   {
      if (a[i1].get_first() < a[i2].get_first())
      {
         b[j] = a[i1];
         i1++;
      }
      else
      {
         b[j] = a[i2];
         i2++;
      }
      j++;
   }

   /* note that only one of the two while loops below is executed
   */

   /* copy any remaining entries of the first half */
   while (i1 <= mid)
   {
      b[j] = a[i1];
      i1++;
      j++;
   }
   /* copy any remaining entries of the second half */
   while (i2 <= to)
   {
      b[j] = a[i2];
      i2++;
      j++;
   }

   /* copy back from the temporary vector */
   for (j = 0; j < n; j++)
      a[from + j] = b[j];
}

void merge_sort(vector<Entry>& a, int from, int to)
{
   if (from == to) return;
   int mid = (from + to) / 2;
   /* sort the first and the second half */
   merge_sort(a, from, mid);
   merge_sort(a, mid + 1, to);
   merge(a, from, mid, to);
}

int binary_search(vector<Entry> v, int from, int to, string n)
/* input parameter "field" indicates whether a search is being done by the
   name or by the number.
*/
{
   if (from > to)    return -1;
   int mid = (from + to) / 2;
   string t;

   if (v[mid].get_first() == n)
      return mid;
   else if (t < n)
      return binary_search(v, mid + 1, to, n);
   else
      return binary_search(v, from, mid - 1, n); 
}

/* We store files in the same format as in exercise 10.6
   name|number
*/

string lookup(string dataset, int n)
{
   int c = 1;
   int i = 0;
   while (c < n)
   {
      if (i < dataset.length())
      {
         if (dataset[i] == '|')
            c++;
         i++;
      }
      else return ""; 
   }
   /* now i points to the first character in the nth field */
   int j = i + 1;
   while (j < dataset.length() && dataset[j] != '|')
      j++;
   return dataset.substr(i, j - i);
}

void readentries(istream& fs, vector<Entry>& by_name, vector<Entry>& by_number)
{
   bool more = true;

   while (more)
   {
      string line;
      getline(fs, line);
      if (fs.fail()) more = false;
      else
      {
         string name = lookup(line, 1);
         string number = lookup(line, 2);
         by_name.push_back(Entry(name, number));
         by_number.push_back(Entry(number, name));
      }
   }

}

int main()
{
   vector<Entry> by_name;
   vector<Entry> by_number;

   cout << "Please enter the phone list data file name: ";
   string filename;
   cin >> filename;
   ifstream fs;
   fs.open(filename.c_str(), ios::in);
   readentries(fs, by_name, by_number);
   fs.close();

   merge_sort(by_name, 0, by_name.size() - 1);
   merge_sort(by_number, 0, by_number.size() - 1);

   bool more = true;

   while (more)
   {
      cout << "Enter n to search for name, # to search for number, q to quit: ";
      string input;
      cin >> input;
      if (input == "n")
      {
         cout << "Enter name to search for: ";
         string name;
         getline(cin, name);
         int i = binary_search(by_name, 0, by_name.size() - 1, name);

         if (i >= 0)
            cout << by_name[i].get_second() << "\n";
         else
            cout << "Not found.\n";
      }
      else if (input == "#")
      {
         cout << "Enter number to search for: ";
         string number;
         getline(cin, number);

         int i = binary_search(by_number, 0, by_number.size() - 1, number);

         if (i >= 0)
            cout << by_number[i].get_second() << "\n";
         else
            cout << "Not found.\n";
      }
      else if (input == "q")
         more = false;
   }

   return 0;
}
