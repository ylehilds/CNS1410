// File Prologue
// Author: Lehi Alcantara 
// Course: CNS 1410
// section: 002     
// Professor: Charles Allison
// Project: Project Seven
// Date Written: October 23th, 2007
// --------------------------------------

// I declare that the following source code was written
// solely by me. I understand that copying any source
// code, in whole or in part, constitutes cheating, and
// that I will receive a zero in this assignment if I am 
// found in violation of this policy.
#include "wx/wx.h"
class Time
{
	int _hrs;
	int _min;
	int _ispm;
public:
   	    Time(int hrs, int min, int ispm) {
        _hrs = hrs;
		_min = min;
		_ispm = ispm;
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
	wxRadioBox GetSelection( );
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
//getter
int Time::getispm() const
{
	return _ispm;
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
 wxTextCtrl* text; 
 wxTextCtrl* text1; 
 wxTextCtrl* text2;
 wxTextCtrl* text3;
 wxTextCtrl* text4;
 wxTextCtrl* text5;
 wxRadioBox* rbox;
 wxRadioBox* rbox1;
 public:
 MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size, const wxString& name );
 // Sample event processing functions
 void OnQuit(wxCommandEvent& event);
 void OnAbout(wxCommandEvent& event);
 void Compute(wxCommandEvent& event);
 void  Clear(wxCommandEvent& event);
 void Alert ();
};
// enums for component IDSs
enum {ID_ABOUT, ID_EXIT, ID_CONV, ID_CONV1, ID_TEXT,ID_TEXT1, ID_ALERT};
// The mapping of events to processing functions
 BEGIN_EVENT_TABLE(MyFrame, wxFrame)
 EVT_MENU(ID_ABOUT, MyFrame::OnAbout)
 EVT_MENU(ID_EXIT, MyFrame::OnQuit)
 EVT_BUTTON(ID_CONV, MyFrame::Compute)
 EVT_BUTTON(ID_CONV1, MyFrame::Clear) 
 END_EVENT_TABLE()
// Function Implementations...
bool MyApp::OnInit() {
 MyFrame* frame = new MyFrame(" Lehi Alcantara - Section 002 - Project Seven",wxPoint (-1,-1),wxSize(450,300),"frame");
 frame->Show(true);
 return true;
}
void MyFrame::OnAbout(wxCommandEvent& event) {
 wxString msg;
 msg.Printf(" Lehi Alcantara - Section 002 - Project Seven");
 wxMessageBox(msg);
 }
void MyFrame::OnQuit(wxCommandEvent& event) {
 Close();  
}

void MyFrame::Compute(wxCommandEvent& event)
{
	int h1 = atoi (text-> GetValue().c_str());
	int h2 = atoi (text1-> GetValue().c_str());
	int m1 = atoi (text3-> GetValue().c_str());
	int m2 = atoi (text4-> GetValue().c_str());
	
	Time test(h1,m1, rbox->GetSelection());
	Time test2 (h2, m2, rbox1->GetSelection());
	
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
//Clear button implementation
void MyFrame::Clear(wxCommandEvent& event) {
    text->SetValue("");
	text1->SetValue("" );
	text2->SetValue("" );
	text3->SetValue("" ); 
	text4->SetValue("" );
	text5->SetValue("" );
	rbox->SetSelection(0);
	rbox1->SetSelection(0);
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
 wxButton* Compute = new wxButton(aPanel, ID_CONV, "Compute", wxPoint(120, 180),
		                            wxSize(85, 30));
 wxButton* Clear = new wxButton(aPanel, ID_CONV1, "Clear", wxPoint(220, 180),
		                            wxSize(85, 30));
// Add Text Controls
 text = new wxTextCtrl(aPanel, ID_TEXT, "", wxPoint(120,35),wxSize (40,30), 0, wxDefaultValidator, wxTextCtrlNameStr);
 text1 = new wxTextCtrl(aPanel, ID_TEXT1, "", wxPoint(120,80),wxSize (40,30), 0, wxDefaultValidator, wxTextCtrlNameStr);
 text2 = new wxTextCtrl(aPanel, ID_TEXT1, "", wxPoint(120,125),wxSize (40,30), 0, wxDefaultValidator, wxTextCtrlNameStr);
 text3 = new wxTextCtrl(aPanel, ID_TEXT1, "", wxPoint(180,35),wxSize (40,30), 0, wxDefaultValidator, wxTextCtrlNameStr);
 text4 = new wxTextCtrl(aPanel, ID_TEXT1, "", wxPoint(180,80),wxSize (40,30), 0, wxDefaultValidator, wxTextCtrlNameStr);
 text5 = new wxTextCtrl(aPanel, ID_TEXT1, "", wxPoint(180,125),wxSize (40,30), 0, wxDefaultValidator, wxTextCtrlNameStr);
// Add static texts 
 wxStaticText* stext = new wxStaticText(aPanel,wxID_ANY,"Start Time",
                                        wxPoint(60,40));
 wxStaticText* stext1 = new wxStaticText(aPanel,wxID_ANY,"End Time",
                                        wxPoint(60,90));
 wxStaticText* stext2 = new wxStaticText(aPanel,wxID_ANY,"Work Time",
                                        wxPoint(60,135));
 wxStaticText* stext3 = new wxStaticText(aPanel,wxID_ANY,":",
                                        wxPoint(170,40));
 wxStaticText* stext4 = new wxStaticText(aPanel,wxID_ANY,":",
                                        wxPoint(170,90));
 wxStaticText* stext5 = new wxStaticText(aPanel,wxID_ANY,":",
                                        wxPoint(170,135));
//array to get the radiio box to am and pm
 wxArrayString strings;
 strings.Add("am");  
 strings.Add("pm");
 // radion boxes implementation
 rbox = new wxRadioBox(aPanel,wxID_ANY,"",
                                   
wxPoint( 240, 30),wxDefaultSize,strings);

 rbox1 = new wxRadioBox(aPanel,wxID_ANY,"",
                                   
wxPoint( 240, 75),wxDefaultSize,strings);
};


 