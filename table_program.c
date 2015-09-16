// copyright (c), KIPR 2015
// Table Program for Botball 2015
//     Charles Winton: 2/2/2015
// Elements have been extracted from prior table programs 
//     and from the CBC-KISS simulator
#include "table_program.h"

int main()
{
	int i, off=0, on=1, lports[]=LIGHT_PORTS, pcnt, w=40, m=5;
	float s;
	graphics_open(320,240);
	for(i=0;i<256;i+=5) {
		graphics_fill(i,i,i);
		graphics_update();
	}
	SplashBG(320, 240);
	msleep(1000);
	graphics_close();
	pcnt=NPORTS(lports);
	for(i=8;i<16;i++) { // change the digital ports to output
		set_digital_output(i,1);
	}
	srand(time(NULL)); // prime random number generation
	while(1) { 
		table_lights(lports,pcnt,off); // shut off table lights
		setup(); // team setup (light calibration w/time out option)
		// setup done, including any time outs so proceed with judge's setup
		//get_shelf_positions(); // display orange/yellow block set up for judges - 2014
		get_bgal_pod_positions(); // display left-right positions for Botgal & pod - 2015
		set_a_button_text("QUIT");	set_b_button_text("-"); set_c_button_text("-");
		graphics_close();  // close any open graphics
		graphics_open(3*w,62);	
		display_clear();
		display_printf(0,0,"************** BOTBALL 2015 **************");
		display_printf(0,1,"               LIGHTS ON IN");
		display_printf(0,2,"******************************************");
		display_printf(0,9,"      Press QUIT to stop count down");
		if (countdown_sd(5,1,BLUE,YELLOW,m,w)) continue;
		s=seconds();
		// 2015
		table_lights(lports,pcnt,on); // on for 115 seconds	
		display_printf(0,1,"     GAME CLOCK - LIGHTS ON TILL 5");
		if (countdown(120,11,GREEN,BLUE,m,w)) continue;
		// end 2015
		/*
		// 2014	
		table_lights(lports,pcnt,on); // on for 15 seconds	
		display_printf(0,1,"     GAME CLOCK - LIGHTS ON TILL 105");
		if (countdown(120,106,GREEN,BLUE,m,w)) continue;
		table_lights(lports,pcnt,off); // of for 100 seconds	
		display_printf(0,1,"      GAME CLOCK - LIGHTS OFF TILL 5");
		if (countdown(105,11,LTBLUE,RED,m,w)) continue;
		// end 2014
		*/
		if (countdown(10,6,LTORANGE,BLUE,m,w)) continue;
		display_printf(0,1,"     GAME CLOCK - LIGHTS BLINK TILL 0");
		i=5+(seconds()-s);
		if (blinkdown(5,0,RED,YELLOW,m,w,lports,pcnt)) continue;
		display_printf(0,1,"            GAME CLOCK - %d          ",i);
		display_printf(0,9,"          ***** GAME OVER! *****     ");
		table_lights(lports,pcnt,off); // shut off table lights
		msleep(5000); // pause display
	}
	return 0;
}
