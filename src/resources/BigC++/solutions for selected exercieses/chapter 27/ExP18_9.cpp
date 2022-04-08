#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

#include <wx/wx.h>

const double PI = 3.141592653589793;

/**
   A clock that can draw its face.
*/
class Clock
{
public:
   /**
      Constructs a clock with a given center and radius.
      @param x the x-coordinate of the center
      @param y the y-coordinate of the center
      @param r the radius of the clock
   */              
   Clock(int x, int y, int r);

   /**
      Sets the current time.
      @param h the hours to set
      @param m the minutes to set
   */
   void set_time(int h, int m);

   /**
      Draws the clock face, with tick marks and hands.
      @param dc the device context to draw on
   */
   void draw(wxDC& dc) const;
private:
   /**
      Draw a tick mark (hour or minute mark).
      @param dc the device context to draw on
      @param angle the angle in minutes (0...59, 0 = top)
      @param length the length of the tick mark, as a fraction
      of the radius (between 0.0 and 1.0)
   */
   void draw_tick(wxDC& dc, double angle, double length) const;

   /**
      Draw a hand, starting from the center.
      @param dc the device context to draw on
      @param angle the angle in minutes (0...59, 0 = top)
      @param length the length of the hand, as a fraction
      of the radius (between 0.0 and 1.0)
   */
   void draw_hand(wxDC& dc, double angle, double length) const;

   int hours;
   int minutes;
   int centerx;
   int centery;
   int radius;
};

/**
   The window that shows the clock.
*/
class ClockWindow : public wxWindow
{
public:
   /**
      Constructs a clock window.
      @param parent the parent window
   */
   ClockWindow(wxWindow* parent);
   /**
      Sets the time of the clock to the current time 
      and repaints it.
   */
   void set_time();
   /**
      Paints the clock.
      @param event the event descriptor
   */      
   void OnPaint(wxPaintEvent& event);
private:
   Clock clock;
   DECLARE_EVENT_TABLE()
};

/**
   The frame that contains the clock window
*/
class ClockFrame : public wxFrame
{
public:
   /**
      Constructs the clock frame.
   */
   ClockFrame();

private:
   ClockWindow* window;
};

/**
   The clock game application.
*/
class ClockApp : public wxApp
{
public:
   /**
      Constructs the application.
   */
   ClockApp();
   virtual bool OnInit();
private:
   ClockFrame* frame;
};

DECLARE_APP(ClockApp)

IMPLEMENT_APP(ClockApp)

BEGIN_EVENT_TABLE(ClockWindow, wxWindow)
   EVT_PAINT(ClockWindow::OnPaint)
END_EVENT_TABLE()

Clock::Clock(int x, int y, int r)
{  
   centerx = x;
   centery = y;
   radius = r;
}

void Clock::set_time(int h, int m)
{  
   hours = h;
   minutes = m;
}

void Clock::draw_tick(wxDC& dc, double angle, 
   double length) const
{  
   double alpha = -PI / 2 + 6 * angle * PI / 180;
   dc.DrawLine(
      centerx + static_cast<int>(
         cos(alpha) * radius * (1 - length)),
      centery + static_cast<int>(
         sin(alpha) * radius * (1 - length)),
      centerx + static_cast<int>(cos(alpha) * radius),
      centery + static_cast<int>(sin(alpha) * radius));
}

void Clock::draw_hand(wxDC& dc, double angle, 
   double length) const
{  
   double alpha = -PI / 2 + 6 * angle * PI / 180;
   dc.DrawLine(centerx, centery,
      centerx + static_cast<int>(cos(alpha) * radius * length),
      centery + static_cast<int>(sin(alpha) * radius * length));
}

void Clock::draw(wxDC& dc) const
{  
   dc.DrawEllipse(centerx - radius, centery - radius, 
      2 * radius, 2 * radius);
   const double HOUR_TICK_LENGTH = 0.2;
   const double MINUTE_TICK_LENGTH = 0.1;
   const double HOUR_HAND_LENGTH = 0.6;
   const double MINUTE_HAND_LENGTH = 0.75;
   for (int i = 0; i < 12; i++)
   {  
      draw_tick(dc, i * 5, HOUR_TICK_LENGTH);
      int j;
      for (j = 1; j <= 4; j++)
         draw_tick(dc, i * 5 + j, MINUTE_TICK_LENGTH);
   }
   draw_hand(dc, minutes, MINUTE_HAND_LENGTH);
   draw_hand(dc, (hours + minutes / 60.0) * 5, HOUR_HAND_LENGTH);
}

ClockWindow::ClockWindow(wxWindow* parent)
   : wxWindow(parent, -1),
   clock(200, 200, 200)
{
}

void ClockWindow::OnPaint(wxPaintEvent& event)
{
   wxPaintDC dc(this);
   dc.SetBrush(*wxTRANSPARENT_BRUSH);
   clock.draw(dc);
}

void ClockWindow::set_time()
{
   time_t now = time(0);
   struct tm& t = *localtime(&now);
   int h = t.tm_hour;
   int m = t.tm_min;

   clock.set_time(h, m);
   Refresh();
}

ClockFrame::ClockFrame() 
   : wxFrame(NULL, -1, "ClockFrame")
{
   window = new ClockWindow(this);
   window->set_time();
}


ClockApp::ClockApp()
{
   frame = new ClockFrame();
}

bool ClockApp::OnInit()
{
   frame->Show(true);
   return true;
}

