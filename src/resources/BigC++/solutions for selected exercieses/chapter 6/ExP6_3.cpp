#include <iostream>
#include <string>

using namespace std;

class Address
{
public:
   Address(int h, string st, int appt, string c, string s, string pc);
   Address(int h, string st, string c, string s, string pc);
   void print() const;
   bool comes_before(Address a) const;
private:
   int house_number;
   string street;
   int apartment_number;
   string city;
   string state;
   string postal_code;
};

Address::Address(int h, string st, int appt, string c, string s, string pc)
{
   house_number = h;
   street = st;
   apartment_number = appt;
   city = c;
   state = s;
   postal_code = pc;
}

Address::Address(int h, string st, string c, string s, string pc)
{
   house_number = h;
   street = st;
   apartment_number = 0;
   city = c;
   state = s;
   postal_code = pc;
}

void Address::print() const
{
   cout << house_number << " " << street;
   if (apartment_number > 0)
      cout << ", #" << apartment_number;
   cout << "\n";
   cout << city << ", " << state << ", " << postal_code;
   cout << "\n";
}


bool Address::comes_before(Address other) const
{
   return postal_code < other.postal_code;
}

int main()
{
   Address my_place(148, "First Ave", "San Diego", "CA", "10392");
   Address your_place(553, "Second St", 44, "San Diego", "CA", "10394");

   cout << "Comparing address\n";
   my_place.print();
   cout << "with address\n";
   your_place.print();

   if (my_place.comes_before(your_place))
      cout << "The first address comes before the second\n";
   else
      cout << "The first address comes after the second\n";
   return 0;
}
