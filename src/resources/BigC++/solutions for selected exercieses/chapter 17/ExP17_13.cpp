#include <string>
#include <iostream>
#include <vector>

using namespace std;

class mpair 
{
public:
   string key;
   double value;
};

bool operator < (const mpair& left, const mpair& right)
{
   return left.key < right.key;
}

class AssociativeArray
{
public:
   bool contains_key(string k);
   double& operator[](string k);
private:
   vector<mpair> values;
};

bool AssociativeArray::contains_key(string k)
{
   vector<mpair>::iterator p = values.begin();
   vector<mpair>::iterator q = values.end();
   while (p != q) 
   {
      if (p->key == k)
	 return true;
      p++;
   }
   return false;
}

double& AssociativeArray::operator[](string k)
{
   for (int i = 0; i < values.size(); i++) 
   {
      if (values[i].key == k)
	 return values[i].value;
   }
   mpair newelement;
   newelement.key = k;
   values.push_back(newelement);
   return values[values.size()-1].value;
}

int  main() 
{
   AssociativeArray prices;
   prices["Toaster Oven"] = 19.94;
   prices["Car Vacuum"] = 24.95;
   cout << prices["Toaster Oven"] << "\n";
}

