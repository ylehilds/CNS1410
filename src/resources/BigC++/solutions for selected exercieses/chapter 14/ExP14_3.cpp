#include <string>

using namespace std;

/**
   Reverse a sentence.
*/
class Sentence
{
public:
   /**
      Creates a Sentence object.
      @param aPhrase a sentence to reverse.
   */
   Sentence(string aPhrase);
   
   /**
      Reverses this sentence.
      @return the reversed sentence
   */
   string reverse();
     
private:
   string phrase;
};

Sentence::Sentence(string aPhrase)   
{
   phrase = aPhrase;
}

  
string Sentence::reverse()
{
   string r;
   for (int i = 0; i < phrase.length(); i++)
      r = phrase.substr(i, 1) + r;
   phrase = r;
   return phrase;
}

int main()
{
   Sentence greeting("Hello!");
   cout << greeting.reverse() << "\n";
   return 0;
}
