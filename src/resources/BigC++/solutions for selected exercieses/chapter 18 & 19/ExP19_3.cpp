// The following program throws an exception in f that is not
// caught in f, but instead caught in main.

#include <iostream>
#include <stdexcept>

using namespace std;

void f() {
   try {
      throw logic_error("a logic error");
   } catch (bad_alloc& e) {
	cout << "caught a bad alloc exception\n";
   }
   cout << "at end of f\n";
}

int main() {
   try {
      f();
   } catch (logic_error& e) {
	cout << "caught a logic error " << "\n";
   }
   return 0;
}
