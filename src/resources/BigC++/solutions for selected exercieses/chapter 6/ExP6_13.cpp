#include <iostream>
#include <string>

using namespace std;

/**
   A student who gets scores in a course.
*/
class Student
{
public:
   /**
      Constructs a student with no scores.
      @param n the student name
   */
   Student(string n);
   /**
      Adds a score.
      @param score the score to add
   */
   void add_quiz(double score);
   /**
      Gets the student name.
      @return the name
   */
   string get_name() const;
   /**
      Gets the total score.
      @return the sum of all scores
   */
   double get_total_score() const;
   /**
      Gets the average score.
      @return the average of all scores
   */
   double get_average_score() const;
private:
   string name;
   double total;
   double count;
};

Student::Student(string n)
{
   name = n;
}

string Student::get_name() const
{
   return name;
}

double Student::get_total_score() const
{
   return total;
}

double Student::get_average_score() const
{
   if (count == 0) return 0;
   return total / count;
}

void Student::add_quiz(double score)
{
   total = total + score;
   count++;
}

int main()
{
   Student joe("Joe Smith");
   joe.add_quiz(10);
   joe.add_quiz(8);
   joe.add_quiz(8);
   cout << joe.get_total_score() << "\n";
   cout << joe.get_average_score() << "\n";
   return 0;
}
