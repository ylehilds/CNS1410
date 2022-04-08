// Basic Window Program with wxWindows
// Class Implementations
// CNS 1350
// Roger deBry
// January 2004

#include <wx/wx.h>


#include "hello.h"

// Menu commands require a unique identifier. This
// is most easily done with an enumeration
enum
{
	ID_Quit = 1,
	ID_About
};


// Now implement the event table
// Each entry in the table contains an event ID and the name
// of the callback function (the event handler)
BEGIN_EVENT_TABLE(BasicFrame, wxFrame)
   EVT_MENU(ID_Quit, BasicFrame::OnQuit)
   EVT_MENU(ID_About, BasicFrame::OnAbout)
END_EVENT_TABLE( )


// This macro creates the application object and sets the main entry point
IMPLEMENT_APP(BasicApplication)

// OnInit function
// Creates the frame object (the main window) and initializes it
bool BasicApplication::OnInit( )
{
	BasicFrame *frame = new BasicFrame("Hello World", 50, 50, 450, 340);
	frame->Show(true);
	SetTopWindow(frame);
	return TRUE;
}

// The fram constructor -- any GUI objects in the frame are created here
BasicFrame::BasicFrame(const wxChar *title, int xpos, int ypos, int width, int height)
   : wxFrame( ( wxFrame *) NULL, -1, title, wxPoint(xpos, ypos), wxSize(width, height))
{
   wxMenu* menuFile = new wxMenu;

   menuFile->Append( ID_About, "&About..." );
   menuFile->AppendSeparator( );
   menuFile->Append( ID_Quit, "E&xit" );

   wxMenuBar *menuBar = new wxMenuBar;
   menuBar->Append( menuFile, "&File" );

   SetMenuBar( menuBar );

   CreateStatusBar( );
   SetStatusText( "Welcome to wxWidgets" );
}

// Event Handler for quit
void BasicFrame::OnQuit( wxCommandEvent& event )
{
	Close( TRUE );
}

// Event Handler for about
void BasicFrame::OnAbout( wxCommandEvent& event )
{
	wxMessageBox("The Hello World Sample",
	             "About Hello World", wxOK | wxICON_INFORMATION );
}



