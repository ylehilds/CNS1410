#include <iostream>
#include <vector>

using namespace std;

class Shape {
public:
   virtual double area() const = 0;
};

class Polygon : public Shape {
public:
   virtual double area() const = 0;
};

class Triangle : public Shape {
public:
   Triangle(int h, int b);
   virtual double area() const;
private:
   int height;
   int base;
};

Triangle::Triangle(int h, int b)
{
	height = h; base = b;
}

double Triangle::area() const
{
	return height * base / 2.0;
}

class Rectangle : public Polygon {
public:
   Rectangle (int h, int w);
   virtual double area() const;
private:
   int height;
   int width;
};

Rectangle::Rectangle(int h, int w)
{
   height = h;
   width = w;
}

double Rectangle::area() const
{
   return height * (double) width;
}

class Square : public Rectangle
{
public:
   Square(int s);
};

Square::Square(int s) : Rectangle(s, s) { }

class Oval : public Shape
{
public:
   Oval (int a, int b);
   virtual double area() const;
private:
   int horzradius, vertradius;
};

Oval::Oval(int a, int b) : horzradius(a), vertradius(b) { }

double Oval::area() const
{
	return horzradius * vertradius * 3.14159;
}

class Circle : public Oval
{
public:
   Circle (int r);
};

Circle::Circle(int r) : Oval(r, r) { }

double totalArea(const vector<Shape*>& shapes)
{
   double sum = 0.0;
   for (int i = 0; i < shapes.size(); i++)
      sum = sum + shapes[i]->area();
   return sum;
}

int main() {
   vector<Shape*> shapes;
   shapes.push_back(new Triangle(3, 4));
   shapes.push_back(new Square(2));
   shapes.push_back(new Circle(3));
   cout << "total area is " << totalArea(shapes) << "\n";
}
