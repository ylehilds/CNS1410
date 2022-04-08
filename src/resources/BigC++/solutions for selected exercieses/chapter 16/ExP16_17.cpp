#include <iostream>
#include <list>
#include <string>

using namespace std;

class Stack
{
public:
   void push(string s);
   string top() const;
   void pop();
   int size() const;
private:
   list<string> elements;
};

void Stack::push(string s)
{
   elements.push_front(s);
}

void Stack::pop()
{
   elements.pop_front();
}

string Stack::top() const
{
   return *elements.begin();
}

int Stack::size() const
{
   return elements.size();
}

int main()
{
   Stack s;
   s.push("Able");
   s.push("Baker");
   s.push("Charlie");

   while (s.size() > 0)
   {
      cout << s.top() << "\n";
      s.pop();
   }
   return 0;
}
