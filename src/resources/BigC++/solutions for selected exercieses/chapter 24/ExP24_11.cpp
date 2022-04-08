#include <iostream>
#include <vector>

using namespace std;

int main() {
   string word;
   vector<string> words;
   // first read in the words
   while (cin >> word)
      words.push_back(word);
   // then sort them
   sort(words.begin(), words.end());
   // then print out the permutatins
   vector<string>::iterator p = words.begin();
   vector<string>::iterator q = words.end();
   while (next_permutation(p, q)) {
      vector<string>::iterator current = p;
      while (current != q) {
	 cout << *current << " ";
	 ++current;
      }
      cout << "\n";
   }
}
