#include <iostream>
#include <cassert>

using namespace std;

template<typename T, int L, int H>
class LBArray
{
public:
   T& operator[](int index);
private:
   T data[H-L+1];
};

template<typename T, int L, int H>
T& LBArray<T, L, H>::operator[](int index)
{
   assert((index >= L) && (index <= H));
   return data[index-L];
}

int main() {
   LBArray<int, 1955, 1975> x;
   x[1956] = 8;
   cout << "value is " << x[1956] << "\n";
}

