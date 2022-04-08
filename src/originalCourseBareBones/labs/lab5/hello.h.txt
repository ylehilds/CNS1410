// Basic Window Program with xwWindows - Hello World
// Creates a basic window and controls
// Based on Hello World Tutorial at www.wxwindows.org
// CNS 1350
// Roger deBry
// January 2004


// First of all we need an Application class that inherits from wxApp
// It provides the main application loop
// Inherits from wxApp
class BasicApplication : public wxApp
{
	public:
	   bool OnInit( );
};

// Then we define a basic Frame class - inherits from wxFrame
// Provides all of the basic windowing functions
// Define a constructor that takes a title, position and size of the window
class BasicFrame : public wxFrame
{
	public:
	   BasicFrame( const wxChar *title, int xpos, int ypos, int width, int height);

	   // declare event handlers
	   void OnQuit (wxCommandEvent& event);
	   void OnAbout(wxCommandEvent& event);

    private:
       // this macro declares the event table
       DECLARE_EVENT_TABLE( )
};




