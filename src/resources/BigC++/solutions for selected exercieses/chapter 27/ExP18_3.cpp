#include <wx/wx.h>

const int ID_LEFT = 1000;
const int ID_RIGHT = 1001;
const int ID_UP = 1002;
const int ID_DOWN = 1003;

const int SQUARE_WIDTH = 20;

/**
   A window onto which a square is painted.
*/
class SquareWindow : public wxWindow
{
public:
   /**
      Initializes the base class.
      @param parent the parent window
   */
   SquareWindow(wxWindow* parent);
   /**
      Moves the square.
      @param dx amount to move in x direction
      @param dy amount to move in y direction
   */
   void move_square(int dx, int dy);
   /**
      Draws a square on the window.
      @param event the event descriptor
   */
   void OnPaint(wxPaintEvent& event);
private:
   int x;
   int y;
   DECLARE_EVENT_TABLE()
};


/**
   A frame with a simple menu that moves a square.
*/
class SquareFrame : public wxFrame
{
public:
   /**
      Constructs the menu and text control.
   */
   SquareFrame();
   /**
      Moves the square to the left.
      @param event the event descriptor
   */
   void OnLeft(wxCommandEvent& event);
   /**
      Moves the square to the right.
      @param event the event descriptor
   */
   void OnRight(wxCommandEvent& event);
   /**
      Moves the square up.
      @param event the event descriptor
   */
   void OnUp(wxCommandEvent& event);
   /**
      Moves the square down.
      @param event the event descriptor
   */
   void OnDown(wxCommandEvent& event);
private:
   SquareWindow* window;
   DECLARE_EVENT_TABLE()
};

class SquareApp : public wxApp
{
public:
   /**
      Constructs the frame.
   */
   SquareApp();
   /**
      Shows the frame.
      @return true
   */
   virtual bool OnInit();
private:
   SquareFrame* frame;
};

DECLARE_APP(SquareApp)

IMPLEMENT_APP(SquareApp)

BEGIN_EVENT_TABLE(SquareFrame, wxFrame)
   EVT_MENU(ID_LEFT, SquareFrame::OnLeft)
   EVT_MENU(ID_RIGHT, SquareFrame::OnRight)
   EVT_MENU(ID_UP, SquareFrame::OnUp)
   EVT_MENU(ID_DOWN, SquareFrame::OnDown)
END_EVENT_TABLE()

SquareFrame::SquareFrame() 
   : wxFrame(NULL, -1, "SquareFrame")
{
   window = new SquareWindow(this);

   // initialize menu
   wxMenu* menu = new wxMenu();
   menu->Append(ID_LEFT, "Left");
   menu->Append(ID_RIGHT, "Right");
   menu->Append(ID_UP, "Up");
   menu->Append(ID_DOWN, "Down");

   // add menu to menu bar
   wxMenuBar* menuBar = new wxMenuBar();
   SetMenuBar(menuBar);
   menuBar->Append(menu, "Move");   
}

void SquareFrame::OnLeft(wxCommandEvent& event)
{
   window->move_square(-1, 0);
   window->Refresh();
}

void SquareFrame::OnRight(wxCommandEvent& event)
{
   window->move_square(1, 0);
   window->Refresh();
}

void SquareFrame::OnUp(wxCommandEvent& event)
{
   window->move_square(0, -1);
   window->Refresh();
}

void SquareFrame::OnDown(wxCommandEvent& event)
{
   window->move_square(0, 1);
   window->Refresh();
}


BEGIN_EVENT_TABLE(SquareWindow, wxWindow)
   EVT_PAINT(SquareWindow::OnPaint)
END_EVENT_TABLE()

SquareWindow::SquareWindow(wxWindow* parent)
   : wxWindow(parent, -1)
{
   x = SQUARE_WIDTH;
   y = SQUARE_WIDTH;
}

void SquareWindow::move_square(int dx, int dy)
{
   x = x + SQUARE_WIDTH * dx;
   y = y + SQUARE_WIDTH * dy;
}

void SquareWindow::OnPaint(wxPaintEvent& event)
{
   wxPaintDC dc(this);
   dc.SetBrush(*wxTRANSPARENT_BRUSH);
   wxSize size = GetSize();
   dc.DrawRectangle(x, y, SQUARE_WIDTH, SQUARE_WIDTH);
}

SquareApp::SquareApp()
{
   frame = new SquareFrame();
}

bool SquareApp::OnInit()
{
   frame->Show(true);
   return true;
}


