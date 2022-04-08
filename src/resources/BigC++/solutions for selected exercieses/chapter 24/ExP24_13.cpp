// easy way to do it is to copy words into a vector.
// use unique, then copy then back
// there are lots of alternatives

#include <iostream>
#include <vector>

using namespace std;

int main() {
   string word;
   vector<string> words;
   while (cin >> word)
     words.push_back(word);
   vector<string>::iterator start = words.begin();
   vector<string>::iterator stop = unique(start, words.end());
   while (start != stop) 
   {
      cout << *start << " ";
      ++start;
   }
   return 0;
}

