#include <iostream>
#include <cassert>

using namespace std;
class String
{
public:
   String(); // Default constructor
   String(const char p[]); // Simple constructor
   String(const String& right); // Copy constructor
   String(int n, char c);
   ~String(); // Destructor
   String& operator=(const String& right); // Assignment operator
   String& operator+=(const String& right);
   int length() const;
   char& operator[](int index);
   char operator[](int index) const;
   int compare(const String& right) const;
   void resize(int n, char c);
   String operator()(int start, int length) const;
private:
   char* buffer;
   int len;
};

String::~String()
{
   delete [] buffer;
}

String::String()
{
   len = 0;
   buffer = NULL; // No need to allocate array
}

String::String(const char p[])
{
   // Determine number of characters in string
   len = 0;
   while (p[len] != '\0')
      len++;
   // Allocate buffer array, remember to make space for null character
   buffer = new char[len + 1];
   // copy new characters
   for (int i = 0; i < len; i++)
      buffer[i] = p[i];
   buffer[len] = '\0';
}

String::String(int n, char c)
{
   len = n;
   buffer = new char[len+1];
   for (int i = 0; i < len; i++)
      buffer[i] = c;
   buffer[len] = '\0';
}

String operator+(const String& left, const String& right)
{
   String result(left);
   result += right;
   return result;
}

int String::compare(const String& right) const
{
     // find smallest size
   int m = right.len;
   int n = len;
   if (m < len) n = m; 
   for (int i = 0; i < n; i++)
      if (buffer[i] < right[i])
	 return -1;
      else if (buffer[i] > right[i])
	 return 1;
   if (m < len)
      return 1;
   else if (m > len)
      return -1;
   return 0;
}

bool operator<(const String& left, const String& right)
	{   return left.compare(right) < 0; }

bool operator<=(const String& left, const String& right)
	{   return left.compare(right) <= 0; }

bool operator!=(const String& left, const String& right)
	{   return left.compare(right) != 0; }

bool operator==(const String& left, const String& right)
	{   return left.compare(right) == 0; }

bool operator>=(const String& left, const String& right)
	{   return left.compare(right) >= 0; }

bool operator>(const String& left, const String& right)
	{   return left.compare(right) > 0; }

void String::resize(int n, char c)
{
   if (n < len) {
      buffer[n] = '\0';
      len = n;
   }
   else {
      char* newbuffer = new char[n+1];
      for (int i = 0; i < n; i++)
	 if (i < len)
	    newbuffer[i] = buffer[i];
         else
	    newbuffer[i] = c;
      delete buffer;
      buffer = newbuffer;
      len = n;
   }
}

String String::operator()(int start, int length) const
{
   // a better version would do bounds checking
   String result(length, ' ');
   for (int i = 0; i < length; i++)
      result[i] = buffer[start+i];
   return result;
}

String& String::operator=(const String& right)
{
   if (this != &right)
   {
      delete [] buffer; // Get rid of old buffer
      len = right.length();
      buffer = new char[len + 1];
      for (int i = 0; i < len; i++)
	 buffer[i] = right[i];
      buffer[len] = '\0';
   }
   return *this;
}

String& String::operator+=(const String& right)
{
   int n = length();
   int m = right.length();
   len = n + m;
   char* newBuffer = new char[len + 1];
   for (int i = 0; i < n; i++)
      newBuffer[i] = buffer[i];
   for (int j = 0; j < m; j++)
      newBuffer[n+j] = right[j];
   newBuffer[len] = '\0';
   delete [] buffer;
   buffer = newBuffer;
   return *this;
}

String::String(const String& right)
{
   len = right.length();
   buffer = new char[len + 1];
   for (int i = 0; i < len; i++)
      buffer[i] = right[i];
   buffer[len] = '\0';
}

int String::length() const
{
   return len;
}

char& String::operator[](int index)
{
   assert((index >= 0) && (index < len));
   return buffer[index];
}

char String::operator[](int index) const
{
   assert((index >= 0) && (index < len));
   return buffer[index];
}

ostream& operator<<(ostream& out, const String& right)
{
   int n = right.length();
   for (int i = 0; i < n; i++)
      out << right[i];
   return out;
}

void ctest(String left, String op, String right, bool result)
{
   cout << left << op << right << " is ";
   if (result) cout << "true\n";
   else cout << "false\n";
}

int main()
{
   String a(5,'a');
   cout << "five a :" << a << "\n";
   String b("bbb");
   String c = a + b;
   cout << "catenation " << c << "\n";
   cout << "compare " << a.compare(b) << "\n";
   String x = "abc";
   String y = "xyz";
   ctest(x, "<", y, x < y);
   y = "abcd"; ctest(x, "<", y, x < y); ctest(y, "<", x, y < x);
   y = "abc"; ctest(x, "<", y, x < y); ctest(x, "==", y, x == y);
   y.resize(6, 'd');
   cout << "resize test " << y << "\n";
   y.resize(2, 'e');
   cout << "resize test " << y << "\n";
   y = "abcdefg";
   cout << "substring test " << y(2,3) << "\n";
   return 0;
}
