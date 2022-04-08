#include <iostream>

using namespace std;

/**
   an ostream_iter is an adapter that takes an ostream
   and allows it to be manipulated using the iterator operations
*/
template<typename T>
class ostream_iter
{
private:
   class ostream_ref;

public:
   /**
     create an ostream iterator around the argument stream
     @param out stream to use for eventual output
   */
   ostream_iter(ostream& out);
   
   /**
     create an ostream iterator around the argument stream
     @param out stream to use for eventual output
     @param sep value to separate between each element
   */
   ostream_iter(ostream& out, string sep);

   /**
     return object referenced by current iterator
   */
   ostream_ref operator*();

   /**
     Increment current iterator
     does nothing for ostreams
   */
   ostream_iter operator++();
private:
   ostream_ref ref;
};

template<typename T>
class ostream_iter<T>::ostream_ref {
public:
   ostream_ref(ostream& o, string s);
   T operator=(const T &v);
private:
   ostream& out;
   string sep;
};

template<typename T>
ostream_iter<T>::ostream_ref::ostream_ref(ostream& o, string s) 
   : out(o), sep(s) { }

template<typename T>
T ostream_iter<T>::ostream_ref::operator=(const T& v) 
{
   out << v << sep;
   return v;
}

template<typename T>
ostream_iter<T>::ostream_ref ostream_iter<T>::operator*()
{
   return ref;
}

template<typename T>
ostream_iter<T>::ostream_iter(ostream& out) : ref(out, "") { }

template<typename T>
ostream_iter<T>::ostream_iter(ostream& out, string sep) : ref(out, sep) { }

template<typename T>
ostream_iter<T> ostream_iter<T>::operator++()
{
   return *this;
}

// this is tricky because you have to read the value in order
// to do the comparison

/**
  istream_iter create an adapter for an input stream,
  allowing it to be used with iterator operations
*/
template<typename T>
class istream_iter
{
public:
   /**
     Create a defaultistream iterator 
     used to check end of stream
   */
   istream_iter();

   /**
     Create an istream itreator around the argument stream
     @param i - stream to read values from
   */
   istream_iter(istream& i);

   /**
     Operator* - return value from current stream
   */
   T operator*();

   /**
     operator++ - increment stream to next position
     does nothing for stream iterators
   */
   istream_iter operator++ ();

   /**
     Test against another stream operator,
     in practice test for end of input
   */
   bool operator==(const istream_iter<T>& right);

private:
   istream& in;
   T nextvalue;
};

template<typename T>
bool istream_iter<T>::operator==(const istream_iter<T>& right)
{
   if (in >> nextvalue) 
      return false;
   return true;
}

template<typename T>
istream_iter<T>::istream_iter(istream& i) : in(i) { }

template<typename T>
istream_iter<T>::istream_iter() : in(cin) { }

template<typename T>
T istream_iter<T>::operator*()
{
   return nextvalue;
}

template<typename T>
istream_iter<T> istream_iter<T>::operator++()
{
   return *this;
}

int main() {
   int a[] = {2, 3, 4};
   copy(a, a+3, ostream_iter<int>(cout, "\n"));
   cout << "now read in 3 values\n";
   istream_iter<int> p(cin);
   istream_iter<int> q;
   int i = 0;
   while (!(p == q))
   {
      a[i] = *p;
      i++;
      ++p;
   }
   copy(a, a+3, ostream_iter<int>(cout, "\n"));
   return 0;
}
