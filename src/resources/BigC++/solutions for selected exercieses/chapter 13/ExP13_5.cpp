#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Message
{
public:
   Message();
   Message(string r, string s);
   void append(string t);
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

void Message::print() const
{  
   cout << "From: " << sender << "\n" <<
      "To: " << recipient << "\n" << text;
}

class Mailbox
{
public:
   Mailbox(string u);
   void add_message(Message m);
   Message get_message(int i) const;
   int count_messages() const;
   string get_user() const;
private:
   vector<Message> messages;
   string user;
};

Mailbox::Mailbox(string u)
{
   user = u;
}

string Mailbox::get_user() const
{
   return user;
}

void Mailbox::add_message(Message m)
{  
   messages.push_back(m);
}

Message Mailbox::get_message(int message_num) const
{ 
   return messages[message_num];
}   
 
int Mailbox::count_messages() const
{
   return messages.size();
}  

class MailSystem
{
public:
   MailSystem();
   void login(string username);
   void add_user(string username);
   void menu();
   void view();
   void send();
private:
   int current;
   vector<Mailbox> mailboxes;
};

MailSystem::MailSystem()
{
   current = -1;
}

void MailSystem::login(string username)
{
   for (int i = 0; i < mailboxes.size(); i++)
      if (mailboxes[i].get_user() == username)
      {
         current = i;
         menu();
         return;
      }
   current = -1;
}

void MailSystem::menu()
{
   while (true)
   {
      cout << "v)iew, s)end, q)uit: "; 
      string command;
      getline(cin, command);
      if (command == "v") view();
      else if (command == "s") send();
      else if (command == "q") return;
   }
}

void MailSystem::view()
{
   for (int i = 0; i < mailboxes[current].count_messages(); i++)
   {
      mailboxes[current].get_message(i).print();
   }
}

void MailSystem::add_user(string username)
{
   mailboxes.push_back(Mailbox(username));
}

void MailSystem::send()
{
   if (current == -1) return;
   cout << "Enter the recipient: ";
   string r;
   getline(cin, r);

   Message m(r, mailboxes[current].get_user());

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

   for (int i = 0; i < mailboxes.size(); i++)
      if (mailboxes[i].get_user() == r)
      {
         mailboxes[i].add_message(m);
         return;
      }
   current = -1;
   cout << "Recipient has no mailbox.\n";
}

int main()
{  
   MailSystem system;

   bool more = true;
   while (more)
   {
      cout << "Name of user to add, q to quit: ";
      string name;
      getline(cin, name);
      if (name == "q") more = false;
      else system.add_user(name);
   }

   more = true;
   while (more)
   {
      cout << "Name of user to log in, q to quit: ";
      string name;
      getline(cin, name);
      if (name == "q") more = false;
      else system.login(name);
   }

   return 0;
}
