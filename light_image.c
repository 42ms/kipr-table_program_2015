// copyright (c), KIPR 2014
#include "table_program.h"

void blinking_light() {
	while(BCHK); // debounce
	graphics_close(); // close any existing window
	graphics_open(45,45);
	graphics_fill(WHITE);
	while(!(BCHK)) {
		graphics_circle_fill(24, 24, 20, GRAY);
		graphics_circle_fill(24, 24, 8, YELLOW);
		graphics_line(6, 24, 42, 24, YELLOW);  // horizontal
		graphics_line(24, 6, 24, 42, YELLOW);  // vertical
		graphics_line(12, 12, 36, 36, YELLOW); // forward slash
		graphics_line(12, 36, 36, 12, YELLOW); // back slash
		graphics_update(); 
		msleep(250);
		if(BCHK) break;
		graphics_circle_fill(24, 24, 20, GRAY);
		graphics_update();
		msleep(250);
	}
	graphics_close();
}
