#include <string>
#include <iostream>
#include <set>

using namespace std;

class mpair 
{
public:
   string key;
   int value;
};

bool operator < (const mpair& left, const mpair& right)
{
   return left.key < right.key;
}

class map
{
public:
   bool contains_key(string k);
   int at(string k);
   void at_put(string k, int v);
private:
   set<mpair> values;
};

bool map::contains_key(string k)
{
   set<mpair>::iterator p = values.begin();
   set<mpair>::iterator q = values.end();
   while (p != q) 
   {
      if (p->key == k)
	 return true;
      p++;
   }
   return false;
}

int map::at(string k)
{
   set<mpair>::iterator p = values.begin();
   set<mpair>::iterator q = values.end();
   while (p != q) 
   {
      if (p->key == k)
	 return p->value;
      p++;
   }
   return 0; // must return something
}

void map::at_put(string k, int v)
{
   set<mpair>::iterator p = values.begin();
   set<mpair>::iterator q = values.end();
   while (p != q) 
   {
      if (p->key == k)
      {
	 values.erase(p);
	 break;
      }
      p++;
   }
   mpair newelement;
   newelement.key = k;
   newelement.value = v;
   values.insert(newelement);
}

int main() 
{
   map a;
   a.at_put("one", 1);
   a.at_put("two", 2);
   a.at_put("three", 3);
   cout << "two is " << a.at("two") << "\n";
   a.at_put("two", 4);
   cout << "two is " << a.at("two") << "\n";
}

