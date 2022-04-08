#include <iostream>
#include <string>

using namespace std;

class Message
{
public:
   Message();
   Message(string r, string s);
   void append(string t);
   string to_string() const;
   void print() const;

private:
   string recipient;
   string sender;
   string text;
};

Message::Message()
{
}

Message::Message(string r, string s)
{
   recipient = r;
   sender = s;
}

void Message::append(string t)
{
    text = text + t + "\n";
}

string Message::to_string() const
{
   return "From: " + sender + "\n" +
      "To: " + recipient + "\n" + text;
}

void Message::print() const
{
   cout << to_string();
}

int main()
{
   cout << "Enter the sender: ";
   string s;
   cin >> s;
   cout << "Enter the recipient: ";
   string r;
   cin >> r;
   Message m(r, s);
   bool more = true;
   string t;
   cout << "Enter message text line, enter . on new line to finish:\n";
   while (more)
   {
      getline(cin, t);
      if (t == ".")
         more = false;
      else
         m.append(t);
   } 
   cout << "The message reads:\n";
   m.print();
   return 0;
}
