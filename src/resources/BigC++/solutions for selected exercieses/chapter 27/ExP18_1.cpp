#include <strstream>

using namespace std;

#include <wx/wx.h>

const int ID_ADD_INTEREST = 1000;

class BankAccount
{
public:
   /**
      Constructs a bank account with a zero balance.
   */
   BankAccount();
   /**
      Deposits money into this account.
      @param amount the amount to deposit.
   */
   void deposit(double amount);
   /**
      Withdraws money from this account.
      @param amount the amount to withdraw.
   */
   void withdraw(double amount);
   /**
      Gets the balance of this account.
      @return the balance
   */
   double get_balance() const;
private:
   double balance;
};

BankAccount::BankAccount()
{
   balance = 0;
}

void BankAccount::deposit(double amount)
{
   balance = balance + amount;
}

void BankAccount::withdraw(double amount)
{
   balance = balance - amount;
}

double BankAccount::get_balance() const
{
   return balance;
}


/**
   A frame with a simple menu that adds greetings to a 
   text control.
*/
class BankAccountFrame : public wxFrame
{
public:
   /**
      Constructs the menu and text control.
   */
   BankAccountFrame();
   /**
      Adds interest to the bank account and displays the result.
      @param event the event descriptor
   */
   void OnAddInterest(wxCommandEvent& event);
private:
   wxTextCtrl* text;
   BankAccount account;
   double rate;
   DECLARE_EVENT_TABLE()
};

/**
   An application to demonstrate the handling of menu events.
*/
class BankAccountApp : public wxApp
{
public:
   /**
      Constructs the frame.
   */
   BankAccountApp();
   /**
      Shows the frame.
      @return true
   */
   virtual bool OnInit();
private:
   BankAccountFrame* frame;
};

DECLARE_APP(BankAccountApp)

IMPLEMENT_APP(BankAccountApp)

BEGIN_EVENT_TABLE(BankAccountFrame, wxFrame)
   EVT_MENU(ID_ADD_INTEREST, BankAccountFrame::OnAddInterest)
END_EVENT_TABLE()

BankAccountFrame::BankAccountFrame() 
   : wxFrame(NULL, -1, "BankAccountFrame")
{
   rate = 5;
   account.deposit(10000);

   text = new wxTextCtrl(this, -1, "",
      wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);

   // initialize menu
   wxMenu* menu = new wxMenu();
   menu->Append(ID_ADD_INTEREST, "Add Interest");

   // add menu to menu bar
   wxMenuBar* menuBar = new wxMenuBar();
   SetMenuBar(menuBar);
   menuBar->Append(menu, "Bank");   
}

void BankAccountFrame::OnAddInterest(wxCommandEvent& event)
{
   double interest = account.get_balance() * rate / 100;
   account.deposit(interest);
   ostrstream out;
   out << account.get_balance() << "\n" << ends;
   text->AppendText(out.str());
}

BankAccountApp::BankAccountApp()
{
   frame = new BankAccountFrame();
}

bool BankAccountApp::OnInit()
{
   frame->Show(true);
   return true;
}


