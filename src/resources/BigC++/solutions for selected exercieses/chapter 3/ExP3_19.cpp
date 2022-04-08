#include "ccc_win.h"

int ccc_win_main()
{  
   Line leftRoof = Line(Point(-4,0), Point(0, 3));
   cwin << leftRoof;
   Line rightRoof = Line(Point(4,0), Point(0, 3));
   cwin << rightRoof;
   Line ceiling = Line(Point(-4,0), Point(4,0));
   cwin << ceiling;
   Line floor = Line(Point(-4,-5), Point(4,-5));
   cwin << floor;
   
   Line leftWall = Line(Point(-4,-5), Point(-4,0));
   cwin << leftWall;
   Line rightWall = Line(Point(4,-5), Point(4,0));
   cwin << rightWall;
   
   Line leftDoor = Line(Point(-3,-5), Point(-3,-1));
   cwin << leftDoor;
   Line rightDoor = Line(Point(-1,-5), Point(-1,-1));
   cwin << rightDoor;
   Line topDoor = Line(Point(-3,-1), Point(-1,-1));      
   cwin << topDoor;
   
   Line leftWindow = Line(Point(1,-3), Point(1,-1));
   cwin << leftWindow;
   Line rightWindow = Line(Point(3,-3), Point(3,-1));
   cwin << rightWindow;
   Line bottomWindow = Line(Point(1,-3), Point(3,-3));      
   cwin << bottomWindow;
   Line topWindow = Line(Point(1,-1), Point(3,-1));      
   cwin << topWindow;

   return 0;
}
