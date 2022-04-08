#include "ccc_win.h" 

int ccc_win_main()
{  
   Circle face= Circle(Point(0,0), 6);
   Circle eye1= Circle(Point(2,2), 0.5);
   Circle eye2= Circle(Point(-2,2), 0.5);
   Line mouth = Line(Point(-2.5, -2), Point(2.5,-2));
          
   cwin << face;
   cwin << eye1;
   cwin << eye2;      
   cwin << mouth;
   return 0;
}
