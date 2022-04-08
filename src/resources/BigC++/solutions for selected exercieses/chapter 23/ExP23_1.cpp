#include <iostream>

using namespace std;

template <typename T>
class vector
{
public:
   typedef T* iterator;
   vector();
   vector(int);
   void set_capacity(int ic);
   T& at(int index);
   void push_back(const T& element);
   int size() const;
private:
   T* buffer;
   int current_size;
   int current_capacity;
};

template<typename T>
vector<T>::vector() : current_size(0), current_capacity(5)
{
   buffer = new T[current_capacity];
}

template<typename T>
vector<T>::vector(int ic) : current_size(ic), current_capacity(ic)
{
   buffer = new T[current_capacity];
}

template<typename T>
void vector<T>::set_capacity(int ic)
{
   T* newbuffer = new T[ic];
   if (ic < current_size) 
   {
      for (int i = 0; i < ic; i++)
	 newbuffer[i] = buffer[i];
      current_size = ic;
   } 
   else 
   {
      for (int i = 0; i < current_size; i++)
	 newbuffer[i] = buffer[i];
   }
   delete buffer;
   buffer = newbuffer;
   current_capacity = ic;
}

template<typename T>
T& vector<T>::at(int index)
{
   return buffer[index];
}

template<typename T>
void vector<T>::push_back(const T& element)
{
   if (current_size >= current_capacity)
      set_capacity(current_capacity * 2);
   buffer[current_size++] = element;
}

template<typename T>
int vector<T>::size() const
{ 
   return current_size;
}

int main() {
   vector<int> a;
   a.push_back(5);
   cout << "size is " << a.size() << "\n";
   cout << "value is " << a.at(0) << "\n";
   return 0;
}
