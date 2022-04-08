#include <iostream>
#include <vector>

using namespace std;

class Set
{
public:
   Set();
   void add(int n);
   void remove(int n);
   bool contains(int n) const;
   friend Set operator|(Set a, Set b);
   friend Set operator&(Set a, Set b);
   friend Set operator~(Set a);
   friend ostream& operator<<(ostream& out, Set a);
private:
   vector<int> elements;
   bool complement;
};

Set::Set()
{
   complement = false;
}

void Set::add(int n)
{
   for (int i = 0; i < elements.size(); i++)
      if (elements[i] == n)
      {
         if (complement)
         {
            elements[i] = elements[elements.size() - 1];
            elements.pop_back();
            return;
         }
      }
   if (!complement)
      elements.push_back(n);
}

void Set::remove(int n)
{
   for (int i = 0; i < elements.size(); i++)
      if (elements[i] == n)
      {
         if (!complement)
         {
            elements[i] = elements[elements.size() - 1];
            elements.pop_back();
            return;
         }
      }
   if (complement)
      elements.push_back(n);
}

bool Set::contains(int n) const
{
   for (int i = 0; i < elements.size(); i++)
      if (elements[i] == n) return !complement;
   return complement;
}

ostream& operator<<(ostream& out, Set a)
{
   if (a.complement) out << "~";
   out << "{";
   for (int i = 0; i < a.elements.size(); i++)
   {
      if (i > 0) out << ", ";
      out << a.elements[i];
   }
   out << "}";
   return out;
}

Set operator|(Set a, Set b)
{
   if (a.complement && b.complement)
      return ~(~a & ~b);
   if (!b.complement)
   {
      Set r = a;
      for (int i = 0; i < b.elements.size(); i++)
         r.add(b.elements[i]);
      return r;
   }
   else
   {
      Set r = b;
      for (int i = 0; i < a.elements.size(); i++)
         r.add(a.elements[i]);
      return r;
   }
}

Set operator&(Set a, Set b)
{
   if (a.complement && b.complement)
      return ~(~a | ~b);
   if (!a.complement)
   {
      Set r;
      for (int i = 0; i < a.elements.size(); i++)
         if (b.contains(a.elements[i]))
            r.add(a.elements[i]);
      return r;
   }
   else
   {
      Set r;
      for (int i = 0; i < b.elements.size(); i++)
         if (a.contains(b.elements[i]))
            r.add(b.elements[i]);
      return r;
   }
}

Set operator~(Set a)
{
   Set r = a;
   r.complement = !r.complement;
   return r;
}

int main()
{
   Set a;
   a.add(2);
   a.add(3);
   a.add(5);
   a.add(7);

   Set b;
   b.add(2);
   b.add(4);
   b.add(6);

   cout << ~a << "\n";
   cout << (a | b) << "\n";
   cout << (a & b) << "\n";
   cout << (a | ~b) << "\n";
   cout << (a & ~b) << "\n";
   cout << (~a | b) << "\n";
   cout << (~a & b) << "\n";
   cout << (~a | ~b) << "\n";
   cout << (~a & ~b) << "\n";
   return 0;
}
