#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Person
{
public:
   /**
      Constructs a person with a given name
      @param n the name
   */
   Person(string n);
   /**
      Gets the name of this person.
      @return the name
   */
   string get_name() const;
   /**
      Sets the best friend of this person
      @param p a pointer to the best friend
   */
   void set_best_friend(Person* p);
   /**
      Gets the best friend of this person.
      @return a pointer to the best friend
   */
   Person* get_best_friend() const;
   /**
      Adjusts the popularity counter of this person.
      @param d +1 or -1
   */
   void adjust_popularity(int d);
   /**
      Gets the popularity counter of this person.
      @return the popularity counter
   */
   int get_popularity() const;
private:
   string name;
   Person* best_friend;
   int popularity;
};

Person::Person(string n)
{
   name = n;
   best_friend = NULL;
   popularity = 0;
}

void Person::set_best_friend(Person* p)
{
   if (best_friend != NULL) best_friend->adjust_popularity(-1);
   best_friend = p;
   if (best_friend != NULL) best_friend->adjust_popularity(1);
}

Person* Person::get_best_friend() const
{
   return best_friend;
}

void Person::adjust_popularity(int d)
{
   popularity = popularity + d;
}

int Person::get_popularity() const
{
   return popularity;
}

string Person::get_name() const
{
   return name;
}

int main()
{
   vector<Person*> people;
   bool more = true;
   while (more)
   {
      cout << "Enter name, q to quit: ";
      string name;
      getline(cin, name);
      if (name == "q") more = false;
      else people.push_back(new Person(name));
   }
   for (int i = 0; i < people.size(); i++)
   {
      cout << "Who is the best friend of " << people[i]->get_name() << "? ";
      string name;
      getline(cin, name);
      for (int j = 0; j < people.size(); j++)
         if (people[j]->get_name() == name)
            people[i]->set_best_friend(people[j]);
   }
   for (int i = 0; i < people.size(); i++)
   {
      cout << setw(20) << people[i]->get_name()
         << "best friend=" << setw(20) << people[i]->get_best_friend()->get_name() 
         << "popularity=" << setw(10) << people[i]->get_popularity() << "\n";
   }   
   return 0;
}
