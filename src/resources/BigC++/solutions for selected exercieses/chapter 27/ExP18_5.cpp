#include <vector>

using namespace std;

#include <wx/wx.h>

/**
   A window that shows a chart.
*/
class ChartWindow : public wxWindow
{
public:
   /**
      Initializes the base class.
      @param parent the parent window
   */
   ChartWindow(wxWindow* parent);
   /**
      Draws an ellipse on the window.
      @param event the event descriptor
   */
   void OnPaint(wxPaintEvent& event);
private:
   vector<double> temperatures;
   DECLARE_EVENT_TABLE()
};

/**
   A frame with a window that shows a chart.
*/
class ChartFrame : public wxFrame
{
public:
   /**
      Constructs the window.
   */
   ChartFrame();
private:
   ChartWindow* window;
};

/**
   An application to demonstrate painting.
*/
class ChartApp : public wxApp
{
public:
   /**
      Constructs the frame.
   */
   ChartApp();
   /**
      Shows the frame.
      @return true
   */
   virtual bool OnInit();
private:
   ChartFrame* frame;
};

DECLARE_APP(ChartApp)

IMPLEMENT_APP(ChartApp)

BEGIN_EVENT_TABLE(ChartWindow, wxWindow)
   EVT_PAINT(ChartWindow::OnPaint)
END_EVENT_TABLE()

ChartWindow::ChartWindow(wxWindow* parent)
   : wxWindow(parent, -1)
{
   temperatures.push_back(11);
   temperatures.push_back(13);
   temperatures.push_back(16);
   temperatures.push_back(20);
   temperatures.push_back(25);
   temperatures.push_back(31);
   temperatures.push_back(33);
   temperatures.push_back(32);
   temperatures.push_back(29);
   temperatures.push_back(23);
   temperatures.push_back(16);
   temperatures.push_back(12);
}

void ChartWindow::OnPaint(wxPaintEvent& event)
{
   wxPaintDC dc(this);
   dc.SetBrush(*wxTRANSPARENT_BRUSH);

   wxSize size = GetSize();
   int width = size.GetWidth();
   int height = size.GetHeight();

   double tmin = temperatures[0];
   double tmax = tmin;
   for (int i = 1; i < temperatures.size(); i++)
   {
      if (tmax < temperatures[i]) tmax = temperatures[i];
      if (tmin > temperatures[i]) tmin = temperatures[i];
   }

   for (int i = 0; i < temperatures.size(); i++)
   {
      const int RADIUS = 2;

      int x = static_cast<int>(i * width / (temperatures.size() - 1));
      int y = static_cast<int>((tmax - temperatures[i]) * height / (tmax - tmin));

      dc.DrawEllipse(x - RADIUS, y - RADIUS, 
         2 * RADIUS + 1, 2 * RADIUS + 1);      
   }
}

ChartFrame::ChartFrame() 
   : wxFrame(NULL, -1, "ChartFrame")
{
   window = new ChartWindow(this);
}

ChartApp::ChartApp()
{
   frame = new ChartFrame();
}

bool ChartApp::OnInit()
{
   frame->Show(true);
   return true;
}

