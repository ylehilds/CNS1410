// File Prologue
// Author: Lehi Alcantara
// Course: CNS 1410
// section: 002   
// Professor: Charles Allison
// Project: Project Six
// Date Written: October 13th, 2007
// --------------------------------------

// I declare that the following source code was written
// solely by me. I understand that copying any source
// code, in whole or in part, constitutes cheating, and
// that I will receive a zero in this assignment if I am 
// found in violation of this policy.
#include "wx/wx.h"
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
 public:
 MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size, const wxString& name );
 // Sample event processing functions
 void OnQuit(wxCommandEvent& event);
 void OnAbout(wxCommandEvent& event);
 void ToCentigrade(wxCommandEvent& event);
  void  ToFahrenheit(wxCommandEvent& event);
};
// enums for component IDSs
enum {ID_ABOUT, ID_EXIT, ID_CONV, ID_CONV1, ID_TEXT,ID_TEXT1};
// The mapping of events to processing functions
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
 EVT_MENU(ID_ABOUT, MyFrame::OnAbout)
 EVT_MENU(ID_EXIT, MyFrame::OnQuit)
 EVT_BUTTON(ID_CONV, MyFrame::ToCentigrade)
 EVT_BUTTON(ID_CONV1, MyFrame::ToFahrenheit) 
END_EVENT_TABLE()
// Function Implementations...
bool MyApp::OnInit() {
 MyFrame* frame = new MyFrame("Lehi Alcantara - Project #6",wxPoint (-1,-1),wxSize(450,300),"frame");
 frame->Show(true);
 return true;
}
void MyFrame::OnAbout(wxCommandEvent& event) {
 wxString msg;
 msg.Printf(" Lehi Alcantara - Section 002 - Project Six");
 wxMessageBox(msg);
 }
void MyFrame::OnQuit(wxCommandEvent& event) {
 Close();
}
void MyFrame::ToCentigrade(wxCommandEvent& event) {
	text1->Clear( );
	wxTextCtrl *theCText = text;
	double tempC;
	theCText->GetValue( ).ToDouble(&tempC); 
	tempC=(tempC-32)*5/9;
    (*text1) << tempC;
}
void MyFrame::ToFahrenheit(wxCommandEvent& event) {
	text->Clear( );
	wxTextCtrl *theCText = text1;
	double tempF;
	theCText->GetValue( ).ToDouble(&tempF); 
	tempF=(tempF * 9/5)+32;
    (*text) << tempF;
}
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
 wxButton* toCentigrade = new wxButton(aPanel, ID_CONV, "to Centigrade", wxPoint(120, 30),
		                            wxSize(85, 30));
 wxButton* toFahrenheit = new wxButton(aPanel, ID_CONV1, "to Fahrenheit", wxPoint(120, 90),
		                            wxSize(85, 30));
// Add Text Controls
 text = new wxTextCtrl(aPanel, ID_TEXT, "", wxPoint(60,30),wxSize (40,30), 0, wxDefaultValidator, wxTextCtrlNameStr);
 text1 = new wxTextCtrl(aPanel, ID_TEXT1, "", wxPoint(60,90),wxSize (40,30), 0, wxDefaultValidator, wxTextCtrlNameStr);
// Add static texts
 wxStaticText* stext = new wxStaticText(aPanel,wxID_ANY,"Temp F",
                                        wxPoint(60,14));
 wxStaticText* stext1 = new wxStaticText(aPanel,wxID_ANY,"Temp C",
                                        wxPoint(60,74));
};
 