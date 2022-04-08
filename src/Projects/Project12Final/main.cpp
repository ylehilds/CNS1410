// File Prologue
// Author: Lehi Alcantara
// Course: CNS 1410
// section: 002      
// Professor: Charles Allison
// Project: Project Twelve
// Date Written: December 13, 2007
// --------------------------------------    

// I declare that the following source code was written
// solely by me. I understand that copying any source
// code, in whole or in part, constitutes cheating, and
// that I will receive a zero in this assignment if I am 
// found in violation of this policy.
#include "wx/wx.h"
#include <wx/listbox.h>
#include "class.h"
#include <iomanip>
#include <cassert>
#include <vector>
#include <iostream>
#include <fstream>



class Time
{
	int _hrs;
	int _min;
	int _ispm;
public:
   	    Time(int hrs, int min) {
        _hrs = hrs;
		_min = min;

		// conditions to get the right amount of time worked, only restriction is that 
		// time worked can not go from pm to am because that is another day
		if (_ispm==0 && _hrs == 12)
		{
			(_hrs-=12);
		}
		if (_ispm == 1 && _hrs ==12) 
		{
			_hrs-=12;
		}
		if (_ispm == 1 && _hrs !=12) 
		{
			_hrs+=12;
		}
    }
	
	int gethrs() const;
	
	int getmin() const; 
	int getispm() const;
	
	//friend functions "-" as well as ">"
	friend const int operator-(const Time& test, const Time& test2) ;
	friend const int operator>(const Time& test, const Time& test2) ;
};
//getter
int Time::gethrs() const
{
	return _hrs;
}
//getter
int Time::getmin() const
{
	return _min;
}

// A minimal App class
class MyApp : public wxApp {
public:
 bool OnInit();
};
// This tells wxWidgets to generate the app's skeleton code
IMPLEMENT_APP(MyApp)
// A Frame (top-level window)
class MyFrame : public wxFrame {
	
 DECLARE_EVENT_TABLE() // To allow event processing
 vector <Employee*> E1;
 wxArrayString  E2;
 wxTextCtrl* text; 
 wxTextCtrl* text1; 
 wxTextCtrl* text2;
 wxTextCtrl* text3;
 wxTextCtrl* text4;
 wxTextCtrl* text5;
 wxTextCtrl* text6;
 wxTextCtrl* text7;
 wxListBox* employeeListBox;
 public:
 MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size, const wxString& name );
 // Sample event processing functions
 void OnQuit(wxCommandEvent& event);
 void OnAbout(wxCommandEvent& event);
 void Payroll(wxCommandEvent& event);
 void  Load(wxCommandEvent& event);
 void Selection(wxCommandEvent& event);
  void Alert ();
};
// enums for component IDSs
enum {ID_ABOUT, ID_EXIT, ID_CONV, ID_CONV1, ID_TEXT,ID_TEXT1, ID_ALERT, ID_SELECTION};
// The mapping of events to processing functions
 BEGIN_EVENT_TABLE(MyFrame, wxFrame)
 EVT_MENU(ID_ABOUT, MyFrame::OnAbout)
 EVT_MENU(ID_EXIT, MyFrame::OnQuit)
 EVT_BUTTON(ID_CONV, MyFrame::Payroll)
 EVT_BUTTON(ID_CONV1, MyFrame::Load) 
 EVT_LISTBOX(ID_SELECTION,MyFrame::Selection)
 END_EVENT_TABLE()

// Function Implementations...
bool MyApp::OnInit() {
 MyFrame* frame = new MyFrame(" Lehi Alcantara - Section 002 - Project Twelve",wxPoint (-1,-1),wxSize(450,300),"frame");
 frame->Show(true);
 return true;
}
void MyFrame::OnAbout(wxCommandEvent& event) {
 wxString msg;
 msg.Printf(" Lehi Alcantara - Section 002 - Project 12");
 wxMessageBox(msg);
 }
void MyFrame::OnQuit(wxCommandEvent& event) {
 Close();  
}

void MyFrame::Payroll(wxCommandEvent& event)
{
	int h1 = atoi (text-> GetValue().c_str());
	int h2 = atoi (text1-> GetValue().c_str());
	int m1 = atoi (text3-> GetValue().c_str());
	int m2 = atoi (text4-> GetValue().c_str());
	
	Time test(h1,m1);
	Time test2 (h2, m2);
	
	if (test > test2) 
	{
		Alert();
	}
	else 
		{
			//wxTxtcontrol to display the hours
			(*text2) << ((test2 - test)/60);
			//wxTxtcontrol to display the minutes
			(*text5) << ((test2 - test)%60);
		}
}
//operator "-" implementation
 const int operator-( const Time& test, const Time& test2) {
	
	int temp = abs(test.getmin() + (test.gethrs()*60)) - (test2.getmin() + (test2.gethrs()*60));
	return temp;
}
//operator ">" implementation
const int operator>( const Time& test, const Time& test2) {
	bool answer= (test.getmin() + (test.gethrs()*60)) > (test2.getmin() + (test2.gethrs()*60));
	return answer;
}
	
//Load button implementation
void MyFrame::Load(wxCommandEvent& event) {
  
	
	ifstream read;
	read.open("payroll.txt");
	Employee* pointer;
	while (read)
	{
		int type;
		read >> type ;
		if (!read)// data validation, to check for any bad data
		{
			cout << "end of file reached, error";
			break;
		}
		switch (type)
		{
		case 1:
			pointer =new Salaried();
			break; 
		case 2:
			pointer = new Sales();
			break;
		case 3:
			pointer =new Hourly();
			break;
		}
		pointer->readData(read);
		E1.push_back(pointer);
	}
	
	wxString anEmployee;
    int size = E1.size( );

    for (int i = 0; i < size; i++)
    {
        anEmployee = E1[ i ]->get_name().c_str( );
        E2.Add(anEmployee);
	}
	employeeListBox->Set(E2);
	
	//doPayroll(E1); 
}

 
void MyFrame::Selection(wxCommandEvent& event)
{  


	wxString textCtrlData;
    int selectionIndex = employeeListBox->GetSelection( );
	text->Clear( ); 
    (*text) << E1[selectionIndex]->get_name().c_str( );
	text1->Clear( ); 
    (*text1) << E1[selectionIndex]->get_address().c_str( );
	text2->Clear( ); 
    (*text2) << E1[selectionIndex]->get_phoneNumber().c_str( );
	text3->Clear( ); 
    (*text3) << E1[selectionIndex]->get_socialSecurityNumber().c_str( );
	text4->Clear( ); 
    (*text4) << E1[selectionIndex]->get_empNumber();

   
} 

// alert implementation if start hour is more that end hour

void MyFrame::Alert () 
   {
      wxString t = _T("Cannot Compute WorkTime");
      t.append ( _T("\nEnd Time is before Start Time"));
      wxMessageDialog aboutDialog( this, t, "Alert", wxOK);
      aboutDialog.ShowModal();
   } 
//main frame
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size, const wxString& name )
			: wxFrame(0, wxID_ANY, title,pos,size,wxDEFAULT_FRAME_STYLE,name) // (parent,ID,title,...)
{
 // Create menu entries
 wxMenu* fileMenu = new wxMenu;
 fileMenu->Append(ID_ABOUT, "&About\tF1", "Show About Dialog");
 //wxMenu* exitMenu = new wxMenu;
 fileMenu->Append(ID_EXIT, "E&xit\tAlt-X", "Quit this program");
 // Create Menu Bar
 wxMenuBar* menuBar = new wxMenuBar;
 menuBar->Append(fileMenu, "&File");
// menuBar->Append(helpMenu, "&Help");
 SetMenuBar(menuBar);
// Create Status Bar
 CreateStatusBar(3);
 SetStatusText("");
 wxPanel* aPanel = new wxPanel(this);
// Create Buttons 
 wxButton* Payroll = new wxButton(aPanel, ID_CONV, "Payroll", wxPoint(180, 500),
		                            wxSize(85, 30));
 wxButton* Load = new wxButton(aPanel, ID_CONV1, "Load", wxPoint(440, 500),
		                            wxSize(85, 30));
// Add Text Controls
 text = new wxTextCtrl(aPanel, ID_TEXT, "", wxPoint(150,35),wxSize (140,30), 0, wxDefaultValidator, wxTextCtrlNameStr);
 text1 = new wxTextCtrl(aPanel, ID_TEXT1, "", wxPoint(150,80),wxSize (140,30), 0, wxDefaultValidator, wxTextCtrlNameStr);
 text2 = new wxTextCtrl(aPanel, ID_TEXT1, "", wxPoint(150,125),wxSize (140,30), 0, wxDefaultValidator, wxTextCtrlNameStr);
 text3 = new wxTextCtrl(aPanel, ID_TEXT1, "", wxPoint(150,175),wxSize (140,30), 0, wxDefaultValidator, wxTextCtrlNameStr);
 text4 = new wxTextCtrl(aPanel, ID_TEXT1, "", wxPoint(150,225),wxSize (140,30), 0, wxDefaultValidator, wxTextCtrlNameStr);
 text5 = new wxTextCtrl(aPanel, ID_TEXT1, "", wxPoint(150,275),wxSize (140,30), 0, wxDefaultValidator, wxTextCtrlNameStr);
 text6 = new wxTextCtrl(aPanel, ID_TEXT1, "", wxPoint(150,325),wxSize (140,30), 0, wxDefaultValidator, wxTextCtrlNameStr);
 text7 = new wxTextCtrl(aPanel, ID_TEXT1, "", wxPoint(150,375),wxSize (140,30), 0, wxDefaultValidator, wxTextCtrlNameStr);
 
 
 
 
 // Add static texts   
 wxStaticText* stext = new wxStaticText(aPanel,wxID_ANY,"Name:",
                                        wxPoint(60,40));
 wxStaticText* stext1 = new wxStaticText(aPanel,wxID_ANY,"Address:",
                                        wxPoint(60,90));
 wxStaticText* stext2 = new wxStaticText(aPanel,wxID_ANY,"Phone Number:",
                                        wxPoint(60,135));
 wxStaticText* stext3 = new wxStaticText(aPanel,wxID_ANY,"Job Title:",
                                        wxPoint(60,180));
 wxStaticText* stext4 = new wxStaticText(aPanel,wxID_ANY,"Emp No:",
                                        wxPoint(60,230));
 wxStaticText* stext5 = new wxStaticText(aPanel,wxID_ANY,"Salary:",
                                        wxPoint(60,280));
 wxStaticText* stext6 = new wxStaticText(aPanel,wxID_ANY,"Wage:",
                                        wxPoint(60,330));
 wxStaticText* stext7 = new wxStaticText(aPanel,wxID_ANY,"Comm Rate:",
                                        wxPoint(60,380)); 
employeeListBox = new wxListBox(aPanel, ID_SELECTION, wxPoint(400,30), 
        wxSize(180, 375), E2, wxLB_SINGLE | wxLB_NEEDED_SB); 

};

 
 