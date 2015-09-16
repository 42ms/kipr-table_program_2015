// copyright (c), KIPR 2015
#include "table_program.h"

void get_bgal_pod_positions()
{
	// screen size (scols,srows), box size (bxcols,bxcols), separator m pixels
	// random block positions p1, p2 set by function picks
	int srows=120,scols=160, bpos, ppos;
	graphics_close(); // close any existing graphics window
	display_clear();  // prep screen
	set_a_button_text("COUNTDOWN");	set_b_button_text("-"); set_c_button_text("-");
	graphics_open(scols,srows);
	graphics_fill(WHITE);
	bpos=rand()%2;
	if (bpos==0) ppos=1;
	else ppos=0;	
	// draw field
	graphics_rectangle(3,3,157,117,BLACK);        // outline
	graphics_rectangle(3,3,70,50,BLACK);          // quads
	graphics_rectangle(90,3,157,50,BLACK);
	graphics_rectangle(3,70,70,117,BLACK);
	graphics_rectangle(90,70,157,117,BLACK);
	graphics_rectangle_fill(70,3,90,50,LTBROWN);         // mesa
	graphics_rectangle(70,3,90,50,BLACK);
	graphics_rectangle_fill(70,70,90,117,LTBROWN);
	graphics_rectangle(70,70,90,117,BLACK); 
	graphics_rectangle_fill(72,50,88,70,LTGRAY);  // caldera
	graphics_rectangle(72,50,88,70,BLACK);
	graphics_rectangle_fill(20,3,25,50,TEAL);     // lines
	graphics_rectangle_fill(135,3,140,50,TEAL);
	graphics_rectangle_fill(20,70,25,117,PINK);
	graphics_rectangle_fill(135,70,140,117,PINK);	
	if (bpos==0) { 
		draw_bg(73,13,0.2);
		graphics_rectangle_fill(74,87,86,102,GREEN);
	}
	else {
		draw_bg(73,82,0.2);
		graphics_rectangle_fill(74,18,86,32,GREEN);
	}
	graphics_update();
	
	display_printf(2,0,"Set Botgal and Botpod ");
	
	while(a_button()==0);
	while(a_button()==1); // debounce
}
