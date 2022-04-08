#include <wx/wx.h>

const int TILE_SIZE = 50;

class TicTacToe
{
public:
   /**
      Starts a new game.
      @param the current player ('x' or 'o')
   */
   void start_game(char player);
   /**
      Sets the next move (or rejects an illegal move).
      @int x the x-coordinate (between 0 and 2)
      @int y the y-coordinate (between 0 and 2)
      @return true if the move was legal
   */
   bool move(int x, int y);
   /**
      Gets a board entry.
      @int x the x-coordinate (between 0 and 2)
      @int y the y-coordinate (between 0 and 2)
      @return the board entry (' ', 'x', or 'o')
   */
   char get_entry(int x, int y) const;
   /**
      Gets the player who will make the next move (or
      who has lost the game)
      @return the player ('x' or 'o')
   */
private:
   char current_player;
   char board[3][3];
};

/**
   A window onto which a game board is painted.
*/
class TicTacToeWindow : public wxWindow
{
public:
   /**
      Initializes the base class.
      @param parent the parent window
   */
   TicTacToeWindow(wxWindow* parent);
   /**
      Draws the game board on the window.
      @param event the event descriptor
   */
   void OnPaint(wxPaintEvent& event);
  /**
      Makes a game move.
      @param event the event descriptor
   */
   void OnMouseEvent(wxMouseEvent& event);
private:
   TicTacToe board;
   DECLARE_EVENT_TABLE()
};

/**
   A frame with a window that shows an ellipse.
*/
class TicTacToeFrame : public wxFrame
{
public:
   /**
      Constructs the window.
   */
   TicTacToeFrame();
private:
   TicTacToeWindow* window;
};

/**
   An application to demonstrate painting.
*/
class TicTacToeApp : public wxApp
{
public:
   /**
      Constructs the frame.
   */
   TicTacToeApp();
   /**
      Shows the frame.
      @return true
   */
   virtual bool OnInit();
private:
   TicTacToeFrame* frame;
};

DECLARE_APP(TicTacToeApp)

IMPLEMENT_APP(TicTacToeApp)

BEGIN_EVENT_TABLE(TicTacToeWindow, wxWindow)
   EVT_PAINT(TicTacToeWindow::OnPaint)
   EVT_MOUSE_EVENTS(TicTacToeWindow::OnMouseEvent)
END_EVENT_TABLE()

void TicTacToe::start_game(char player)
{
   for (int y = 0; y < 3; y++)
      for (int x = 0; x < 3; x++)
         board[y][x] = ' ';
   current_player = player;
}

bool TicTacToe::move(int x, int y)
{
   if (x < 0 || y < 0 || x > 2 || y > 2) return false;
   if (board[y][x] == ' ')
   {
      board[y][x] = current_player;
      if (current_player == 'x') current_player = 'o';
      else current_player = 'x';
      return true;
   }
   else return false;
}

char TicTacToe::get_entry(int x, int y) const
{
   return board[y][x];
}

TicTacToeWindow::TicTacToeWindow(wxWindow* parent)
   : wxWindow(parent, -1)
{
   board.start_game('x');
}

void TicTacToeWindow::OnMouseEvent(wxMouseEvent& event)
{
   if (event.ButtonDown())
   {
      int x = event.GetX() / TILE_SIZE;
      int y = event.GetY() / TILE_SIZE;
      board.move(x, y);
      Refresh();
   }
}

void TicTacToeWindow::OnPaint(wxPaintEvent& event)
{
   wxPaintDC dc(this);
   dc.SetBrush(*wxTRANSPARENT_BRUSH);
   for (int i = 1; i <= 2; i++)
   {
      dc.DrawLine(0, i * TILE_SIZE, 3 * TILE_SIZE, i * TILE_SIZE);
      dc.DrawLine(i * TILE_SIZE, 0, i * TILE_SIZE, 3 * TILE_SIZE);
   }

   for (int x = 0; x <= 2; x++)
      for (int y = 0; y <= 2; y++)
      {
         char c = board.get_entry(x, y);
         if (c == 'x')
         {
            dc.DrawLine(x * TILE_SIZE, y * TILE_SIZE,
               (x + 1) * TILE_SIZE, (y + 1) * TILE_SIZE);
            dc.DrawLine(x * TILE_SIZE, (y + 1) * TILE_SIZE,
               (x + 1) * TILE_SIZE, y * TILE_SIZE);
         }
         else if (c == 'o')
         {
            dc.DrawEllipse(x * TILE_SIZE, y * TILE_SIZE,
               TILE_SIZE, TILE_SIZE);
         }
      }
}

TicTacToeFrame::TicTacToeFrame() 
   : wxFrame(NULL, -1, "TicTacToeFrame")
{
   window = new TicTacToeWindow(this);
}

TicTacToeApp::TicTacToeApp()
{
   frame = new TicTacToeFrame();
}

bool TicTacToeApp::OnInit()
{
   frame->Show(true);
   return true;
}

