#include <iostream>

using namespace std;

template <typename T>
class deque
{
public:
   typedef T* iterator;
   deque();
   T& at(int index);
   void push_front(const T& value);
   void push_back(const T& value);
   void pop_front();
   void pop_back();
   int size() const;
private:
   T* buffer;
   int current_start;
   int current_size;
   int current_capacity;
   void increase_capacity();
};

template<typename T>
deque<T>::deque() : current_size(0), current_start(0), current_capacity(5)
{
   buffer = new T[current_capacity];
}

template<typename T>
void deque<T>::increase_capacity()
{
   T* newbuffer = new T[current_capacity * 2];
   for (int j = 0; j < current_size; j++)
   {
      newbuffer[j] = buffer[current_start];
      current_start++;
      if (current_start >= current_capacity)
	 current_start = 0;
   }
   delete buffer;
   buffer = newbuffer;
   current_start = 0;
   current_capacity = current_capacity * 2;
}

template<typename T>
T& deque<T>::at(int index)
{
   return buffer[(current_start + index) % current_capacity];
}

template<typename T>
void deque<T>::pop_front()
{
   current_start++;
   if (current_start > current_capacity)
      current_start = 0;
   current_size--;
}

template<typename T>
void deque<T>::pop_back()
{
   current_size--;
}

template<typename T>
void deque<T>::push_front(const T& value)
{
   if (current_size >= current_capacity)
      increase_capacity();
   current_start--;
   if (current_start < 0)
      current_start = current_capacity-1;
   buffer[current_start] = value;
   current_size++;
}

template<typename T>
void deque<T>::push_back(const T& value)
{
   if (current_size >= current_capacity)
      increase_capacity();
   int index = (current_start + current_size) % current_capacity;
   buffer[index] = value;
   current_size++;
}

template<typename T>
int deque<T>::size() const
{
   return current_size;
}

int main() {
   deque<int> a;
   a.push_front(2);
   a.push_front(1);
   a.push_back(3);
   a.push_back(4);
   for (int i = 0; i < a.size(); i++)
      cout << "element " << a.at(i) << "\n";
   cout << "now test for buffer increase\n";
   a.push_back(5);
   a.push_back(6);
   a.push_back(7);
   a.push_back(8);
   for (int i = 0; i < a.size(); i++)
      cout << "element " << a.at(i) << "\n";
   return 0;
}
