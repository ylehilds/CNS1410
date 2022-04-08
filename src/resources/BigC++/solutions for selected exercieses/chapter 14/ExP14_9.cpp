#include <vector>
#include <string>

using namespace std;

vector<string> generate_substrings(string s)
{
   if (s.length() == 0)
   {
      vector<string> r;
      r.push_back("");
      return r;
   }
   vector<string> r = generate_substrings(s.substr(1, s.length() - 1));
   for (int i = 1; i <= s.length(); i++)
      r.push_back(s.substr(0, i));
   return r;
}

int main()
{
   vector<string> v = generate_substrings("rum");
   for (int i = 0; i < v.size(); i++)
      cout << v[i] << "\n";
   return 0;
}
