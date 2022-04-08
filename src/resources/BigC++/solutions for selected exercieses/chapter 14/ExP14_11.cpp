#include <vector>
#include <string>

using namespace std; 

void swap(int& x, int& y) 
{ 
   int temp = x; 
   x = y; 
   y = temp; 
} 

void reverse(vector<int>& a, int i, int j) 
{ 
   while (i < j) 
   { 
      swap(a[i], a[j]); 
      i++; 
      j--; 
   } 
} 

bool next_permutation(vector<int>& a) 
{ 
   for (int i = a.size() - 1; i > 0; i--) 
   { 
      if (a[i - 1] < a[i]) 
      { 
         int j = a.size() - 1; 
         while (a[i - 1] > a[j]) j--; 
         swap(a[i - 1], a[j]); 
         reverse(a, i, a.size() - 1); 
         return true; 
      } 
   } 
   return false; 
} 

vector<string> generate_permutations(string w)
{
   vector<int> a;
   vector<string> r;
   for (int i = 0; i < w.length(); i++) a.push_back(i);
   r.push_back(w); 
   while (next_permutation(a)) 
   {
      string s;
      for (int i = 0; i < a.size(); i++)
         s += w[a[i]];
      r.push_back(s); 
   }
   return r;
}

void print(const vector<string>& a) 
{ 
   for (int i = 0; i < a.size(); i++) 
      cout << a[i] << "\n"; 
} 

int main() 
{ 
   print(generate_permutations("rum"));
   return 0; 
} 
