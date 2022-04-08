#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

class StackError : public runtime_error 
{
public:
   StackError(const string& why) : runtime_error(why) { }
};

class SafeStack 
{
public:
   SafeStack();
   bool empty() const;
   string top() const;
   void pop();
   void push(const string&);
private:
   stack<string> data;
};

SafeStack::SafeStack() : data() { }

void SafeStack::pop() 
{
   if (empty()) 
       throw StackError("stack underflow");
   data.pop();
}

string SafeStack::top() const
{
   if (empty()) 
       throw StackError("stack undeflow");
   return data.top();
}

bool SafeStack::empty() const { return data.empty(); }

void SafeStack::push(const string& v) { data.push(v); }

int main()
{
   SafeStack stk;
   try 
   {
      stk.pop(); // pop an empty stack
   } 
   catch (StackError & e)
   {
      cout << "caught stack error " << e.what() << "\n";
   }
   return 0;
}

