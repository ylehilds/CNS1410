#include <iostream>

using namespace std;

template<typename F, typename S=F>
class Pair
{
public:
   Pair(const F& a, const S& b);
   F get_first() const;
   S get_second() const;
private:
   F first;
   S second;
};

template<typename F, typename S>
Pair<F, S>::Pair(const F& a, const S& b)
{
   first = a;
   second = b;
}

template<typename F, typename S>
F Pair<F, S>::get_first() const
{
   return first;
}

template<typename F, typename S>
S Pair<F, S>::get_second() const
{
   return second;
}
