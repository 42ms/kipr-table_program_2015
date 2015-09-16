// copyright (c), KIPR 2014
#include "table_program.h"

void setup() // return 0 if setup needs to run again, 1 otherwise
{
	int w=40, m=5, go=0;
	int nports[0];
	while(!go) {
		while(a_button() || b_button()); // debounce
		graphics_close(); // close any existing graphics window
		display_clear();  // prep screen
		display_printf(0,0,"************** BOTBALL 2015 **************");
		display_printf(0,1,"           INSPECTION and SETUP");
		display_printf(0,2,"******************************************");
		display_printf(0,3,"SETUP: Teams calibrate for lights ON/OFF");
		display_printf(0,8,"     Press START when teams are ready");
		set_a_button_text("START");	set_b_button_text("TIME OUT"); set_c_button_text("-");
		display_printf(0,9,"      For TIME OUT collect red card"); // B button
		graphics_open(45,45);
		graphics_fill(WHITE);
		while(!(a_button() || b_button())) {
			graphics_circle_fill(24, 24, 20, GRAY);
			graphics_circle_fill(24, 24, 8, YELLOW);
			graphics_line(6, 24, 42, 24, YELLOW);  // horizontal
			graphics_line(24, 6, 24, 42, YELLOW);  // vertical
			graphics_line(12, 12, 36, 36, YELLOW); // forward slash
			graphics_line(12, 36, 36, 12, YELLOW); // back slash
			graphics_update(); 
			msleep(250);
			if(a_button() ||  b_button()) break;
			graphics_circle_fill(24, 24, 20, GRAY);
			graphics_update();
			msleep(250);
		}
		graphics_close();	
		if(b_button()) { // time out
			display_clear();
			display_printf(0,0,"**************** TIMEOUT ****************");
			display_printf(0,2,"    Press RETURN to go back to set up");
			display_printf(0,8,"             Seconds Remaining");
			set_a_button_text("RETURN"); set_b_button_text("-"); set_c_button_text("-");
			graphics_open(3*w,62);	
			if (countdown(180,11,GREEN,BLUE,m,w)) continue;
			if (countdown(10,6,LTORANGE,BLUE,m,w)) continue;
			if (countdown(5,0,RED,YELLOW,m,w)) continue;
			showtriple(0,YELLOW,m,w);
			msleep(3000);
		}
		else { // ready to proceed
			go=1; 
		}
	}
	msleep(1000); // leave display up briefly
}



