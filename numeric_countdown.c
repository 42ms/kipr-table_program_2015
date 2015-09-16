// copyright (c), KIPR 2015
#include "table_program.h"

void hseg(int dy, int dx, int l, int r, int g, int b)
{
	graphics_line(dy+1, dx, dy+l-1, dx, r,g,b);  // horizontal
	graphics_line(dy, dx+1, dy+l, dx+1, r,g,b);
	graphics_line(dy+1, dx+2, dy+l-1, dx+2, r,g,b);
}
void vseg(int dy, int dx, int l, int r, int g, int b)
{
	graphics_line(dy, dx+1,dy, dx+l-1, r,g,b);  // horizontal
	graphics_line(dy+1, dx, dy+1, dx+l, r,g,b);
	graphics_line(dy+2, dx+1, dy+2, dx+l-1, r,g,b);
}
void digit(int i, int p, int r, int g, int b)
{
	switch(i) {
		case 0:
		A(p,r,g,b); B(p,r,g,b); C(p,r,g,b); D(p,r,g,b); E(p,r,g,b); F(p,r,g,b);
		break;
		case 1:
		B(p,r,g,b); C(p,r,g,b);
		break;
		case 2:
		A(p,r,g,b); B(p,r,g,b); G(p,r,g,b); E(p,r,g,b); D(p,r,g,b);
		break;
		case 3:
		A(p,r,g,b); B(p,r,g,b); G(p,r,g,b); C(p,r,g,b); D(p,r,g,b);
		break;
		case 4:
		F(p,r,g,b); B(p,r,g,b); G(p,r,g,b); C(p,r,g,b); 
		break;
		case 5:
		A(p,r,g,b); F(p,r,g,b); G(p,r,g,b); C(p,r,g,b); D(p,r,g,b);
		break;
		case 6:
		A(p,r,g,b); F(p,r,g,b); G(p,r,g,b); E(p,r,g,b); D(p,r,g,b); C(p,r,g,b);
		break;
		case 7:
		A(p,r,g,b); B(p,r,g,b); C(p,r,g,b); 
		break;
		case 8:
		A(p,r,g,b); B(p,r,g,b); C(p,r,g,b); D(p,r,g,b); E(p,r,g,b); F(p,r,g,b); G(p,r,g,b);
		break;
		case 9:
		A(p,r,g,b); B(p,r,g,b); C(p,r,g,b); F(p,r,g,b); G(p,r,g,b);
		break;
		case -1:
		CLEAR(p,r,g,b);
		default:
		G(p,r,g,b);
		break;
	}
}
// graphics_open(3*w,62);	
int countdown(int strt, int fin, int br, int bg, int bb, int dr, int dg, int db, int m, int w)
{
	int i,j,d1,d2,d3;
	while(BCHK); // debounce
	for(i=strt;i>=fin;i--) {
		graphics_fill(br,bg,bb);
		d1=i/100; d2=(i%100)/10; d3=i%10;
		if (d1>0) digit(d1,m,dr,dg,db);
		if (d1>0 || d2>0) digit(d2,m+w,dr,dg,db);
		digit(d3,m+w+w,dr,dg,db);
		graphics_update();
		for (j=0;j<4;j++) { // pause 1 second or quit
			if(BCHK) return 1;
			msleep(250);
		}
	}
	return 0;	
}
// graphics_close()

// graphics_open(3*w,62);	
int countdown_sd(int strt, int fin, int br, int bg, int bb, int dr, int dg, int db, int m, int w) // single digit version
{
	int i,j,d1,d2,d3;
	while(BCHK); // debounce
	for(i=strt;i>=fin;i--) {
		graphics_fill(br,bg,bb);
		d1=i/100; d2=(i%100)/10; d3=i%10;
		digit(d3,m+w,dr,dg,db);
		graphics_update();
		for (j=0;j<4;j++) { // pause 1 second or quit
			if(BCHK) return 1;
			msleep(250);
		}
	}
	return 0;	
}
// graphics_close()

// graphics_open(3*w,62);	
int blinkdown(int strt, int fin, int br, int bg, int bb, int dr, int dg, int db, int m, int w, int lports[], int pcnt)
{
	int i,j,d1,d2,d3,off=0,on=1;
	while(BCHK); // debounce
	for(i=strt;i>fin;i--) {
		for(j=0;j<5;j++) {
			table_lights(lports,pcnt,on); // table lights on
			graphics_fill(WHITE);
			graphics_update();
			msleep(100);
			if(BCHK) return 1;
			table_lights(lports,pcnt,off); // table lights off
			graphics_fill(br,bg,bb);
			d1=i/100; d2=(i%100)/10; d3=i%10;
			if (d1>0) digit(d1,m,dr,dg,db);
			if (d1>0 || d2>0) digit(d2,m+w,dr,dg,db);
			digit(d3,m+w+w,dr,dg,db);
			graphics_update();
			msleep(100);
			if(BCHK) return 1;
		}
	}	
	
	showtriple(0,dr,dg,db,m,w);
	return 0;
}
// graphics_close()
void showtriple(int i, int r, int g, int b, int m, int w) 
{
	digit(i,m,r,g,b); digit(i,m+w,r,g,b); digit(i,m+w+w,r,g,b);
	graphics_update();
}
