// copyright (c), KIPR 2014
#include "table_program.h"

void SplashBG(int w, int h)
{
	int i,offX,offY;
	for (i=0;i<h;i=i+(h/50)+1) {
		offX=38*(((float)i)/(float)(h/8));
		offY=(-i/1.2)+50*(((float)i)/(float)(h/8));
		draw_bg(w/2-offX,h/2-offY,((float)i)/(float)(h/8));
		msleep(20);
		clear_bg(w/2-offX,h/2-offY,((float)i)/(float)(h/8));
	}
}
