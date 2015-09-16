// copyright (c), KIPR 2014
#include "table_program.h"

void get_shelf_positions()
{
	// screen size (scols,srows), box size (bxcols,bxcols), separator m pixels
	// random block positions p1, p2 set by function picks
	int i,r,c,srows,scols,bxrows=35,bxcols=35,m=3,p1,p2;
	r=bxrows+m; c=bxcols+m;	
	srows=1+m+2*r; scols=1+m+7*c;
	graphics_close(); // close any existing graphics window
	display_clear();  // prep screen
	set_a_button_text("COUNTDOWN");	set_b_button_text("-"); set_c_button_text("-");
	graphics_open(scols,srows);
	graphics_fill(WHITE);
	pick2(&p1, &p2); // get orange (upper) positions
	display_printf(0,0,"Set ORANGE (upper shelf) positions: %d %d  ",1+p1,1+p2);
	graphics_rectangle_fill(m+p1*c,m,c+p1*c,bxrows,ORANGE);
	graphics_rectangle_fill(m+p2*c,m,c+p2*c,bxrows,ORANGE);
	
	pick2(&p1, &p2); // get yellow (lower) positions
	display_printf(0,1,"Set YELLOW (lower shelf) positions: %d %d  ",8+p1,8+p2);
	graphics_rectangle_fill(m+p1*c,m+r,c+p1*c,m+r+bxrows,YELLOW);
	graphics_rectangle_fill(m+p2*c,m+r,c+p2*c,m+r+bxrows,YELLOW);
	
	graphics_rectangle(0,0,scols-1,srows-1,BLACK);
	for(i=m; i<scols; i=i+c) {
		graphics_rectangle(i,m,i+bxcols,bxrows,BLACK); // upper
		graphics_rectangle(i,m+r,i+bxcols,m+r+bxrows,BLACK); // lower
	}	
	
	graphics_update();
	
	display_printf(0,2,"    1     2    3     4    5     6    7 ");
	display_printf(0,9,"    8     9    10   11   12    13   14 ");
	
	while(a_button()==0);
	while(a_button()==1); // debounce
}
void pick2(int* x, int* y) // select 2 of 7 positions
{
	int a=rand()%7,b=rand()%7;
	// accept/reject for the pair
	while(abs(a-b)<2) { // if reject, get new pair
		a=rand()%7;
		b=rand()%7; 
	}
	if (a>b){ // order pair low to high
		SWAP(a,b);
	}	
	*x=a; // dereference for return
	*y=b;
}
