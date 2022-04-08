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
   if (phrase != "")
   {
      string c = phrase.substr(0, 1);
      string rest = phrase.substr(1, phrase.length() - 1);
      Sentence tailSentence(rest);
      phrase = tailSentence.reverse() + c;
   }
   return phrase;
}

int main()
{
   Sentence greeting("Hello!");
   cout << greeting.reverse() << "\n";
   return 0;
}
