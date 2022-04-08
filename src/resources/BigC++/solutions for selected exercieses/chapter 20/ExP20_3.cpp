#include <iostream>
#include <vector>

using namespace std;

class Chart
{
public:
   class Iterator;
   void add(int);
   virtual void draw() const;
   Iterator begin();
   Iterator end();
protected:
   vector<int> data;
};

class Chart::Iterator 
{
public:
   Iterator(int i, Chart* ic);
   int get() const;
   void next();
   bool equals(Iterator v) const;
private:
   int index;
   Chart* c;
};

void Chart::add(int v)
{
   data.push_back(v);
}

void Chart::draw() const
{
   cout << "cannot draw simple chart";
}

Chart::Iterator::Iterator(int i, Chart* ic)
{
   index = i;
   c = ic;
}

int Chart::Iterator::get() const
{
   return c->data[index];
}

void Chart::Iterator::next()
{
   index++;
}

bool Chart::Iterator::equals(Iterator v) const
{
   return index == v.index;
}

Chart::Iterator Chart::begin()
{
   return Iterator(0, this);
}

Chart::Iterator Chart::end()
{
   return Iterator(data.size(), this);
}



class BarChart : public Chart
{
public:
   virtual void draw() const;
};

void BarChart::draw() const
{
   int n = data.size();
   for (int i = 0; i < n; i++) {
      int v = data[i];
      cout << v << " ";
      for (int j = 0; j < v; j++)
         cout << "*";
      cout << "\n";
   }
}

int main() 
{
   BarChart bc;
   bc.add(3);
   bc.add(5);
   bc.add(2);
   bc.add(7);
   bc.draw();
}
