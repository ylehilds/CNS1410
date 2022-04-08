#include <iostream>

using namespace std;

class SharedString 
{
public:
    SharedString ( );
    SharedString (const char* right);
    SharedString (const SharedString& right);
    ~SharedString ();
    SharedString& operator = (const SharedString&);
    char& operator[](int index);
private:
    class StringReference;
    StringReference* p;
    void reassign (StringReference*);
    friend ostream& operator<<(ostream& out, SharedString sstr);
};

class SharedString::StringReference 
{
public:
    int count;
    char* buffer;
    StringReference (const char* right);
    ~StringReference ( );
};

SharedString::SharedString ( ) : p(NULL)
{
    cout << "Entering SharedString() \n";
}

SharedString::SharedString (const char* right) : p(NULL) 
{
    reassign(new StringReference(right));
}

SharedString::SharedString (const SharedString& right) : p(NULL)
{
    reassign(right.p);
}

SharedString::~SharedString ( )
{
    reassign(NULL);
}

SharedString& SharedString::operator = (const SharedString& right)
{
    reassign(right.p);
    return *this;
}

void SharedString::reassign(SharedString::StringReference* np)
{
    if (np != NULL) // increment count on the new value
        np->count += 1;
    if (p != NULL)  // decrement reference counts on old value
    {
        p->count -= 1;
        if (p->count == 0)
            delete p;
    }
    p = np;  // change binding
}

SharedString::StringReference::StringReference (const char* right)
{
    count = 0;
    int n = 0;
    while (right[n] != '\0')
       n++;
    buffer = new char[1 + n];
    for (int i = 0; i < n; i++)
       buffer[i] = right[i];
    buffer[n] = '\0';
}

SharedString::StringReference::~StringReference ( )
{
    delete [ ] buffer;
}

char& SharedString::operator[](int index)
{
   reassign(new StringReference(p->buffer));
   return p->buffer[index];
}

ostream& operator<<(ostream& out, SharedString sstr)
{
   out << sstr.p->buffer;
   return out;
}

SharedString g; // global value

int main ( )
{
   SharedString a = "Jim";
   SharedString b = a;
   b[0] = 'f';
   cout << "a is " << a << "\n";
   cout << "b is " << b << "\n";
    return 0;
}
