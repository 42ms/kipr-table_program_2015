// copyright (c), KIPR 2015
// Table Program for Botball 2015
//     Charles Winton: 2/2/2015
// Elements have been extracted from prior table programs 
//     and from the CBC-KISS simulator

// standard libraries needed to compile for the Link simulator
#include <stdlib.h> // for rand, srand
#include <math.h>   // for abs
// needed for srandom and get_shelf_positions
#include <time.h> 
#define SWAP(x,y) \
    x = x ^ y;    \
    y = x ^ y;    \
    x = x ^ y;
// various colors used
#define RED 255,0,0
#define GREEN 0,255,0
#define BLUE 0,0,255
#define PINK 255,105,180
#define TEAL 0,200,200
#define YELLOW 255,255,0
#define ORANGE 255,153,51
#define LTORANGE 255,229,204
#define LTBLUE 204,255,255
#define WHITE 255,255,255
#define GRAY 240,240,240
#define LTGRAY 240,240,240
#define LTBROWN 255,248,220
#define BLACK 0,0,0
// segment processing for numeric_countdown
#define A(x,r,g,b) hseg(x+2,5,25,r,g,b); 
#define B(x,r,g,b) vseg(x+27,8,21,r,g,b); 
#define C(x,r,g,b) vseg(x+27,33,21,r,g,b); 
#define D(x,r,g,b) hseg(x+2,55,25,r,g,b); 
#define E(x,r,g,b) vseg(x,33,21,r,g,b);
#define F(x,r,g,b) vseg(x,8,21,r,g,b); 
#define G(x,r,g,b) hseg(x+2,30,25,r,g,b); 
#define CLEAR(x,r,g,b) graphics_rectangle_fill(x,0,x+29,61,r,g,b);
#define BCHK a_button() || b_button() || c_button()
// digital ports used for table lights
#define LIGHT_PORTS {8,9,10,11,12,13,14,15}
#define NPORTS(x)  (sizeof(x) / sizeof(x[0]))
// function prototypes
void table_lights(int lports[], int pcnt, int onoff); // table lights on/off
void setup(); // light calibration (includes time-out)
void blinking_light(); // blinking light image shown during light calibration period
// functions used to determine shelf positions
// void get_shelf_positions(); // 2014
void get_bgal_pod_positions(); // 2015
void pick2(int* x, int* y); // set pair of random values from 0-6 at least 2 apart
// functions for 7-segment display (strt time, finish time, box rgb, digit rgb, margin, displacement)
int countdown(int strt, int fin, int br, int bg, int bb, int dr, int dg, int db, int m, int w);
int blinkdown(int strt, int fin, int br, int bg, int bb, int dr, int dg, int db, int m, int w, int lports[], int pcnt);
int countdown_sd(int strt, int fin, int br, int bg, int bb, int dr, int dg, int db, int m, int w); // also pass in table light info to blink table lights
void hseg(int dy, int dx, int l, int r, int g, int b); // draw horizontal segment (col, row, length)
void vseg(int dy, int dx, int l, int r, int g, int b); // draw vertical segment
void digit(int i, int p, int r, int g, int b); // display 7 segment digit for i at position p in window
void showtriple(int i, int r, int g, int b, int m, int w) ; // show i in all 3 digit positions
// splash screen
void SplashBG(int w, int h);
void draw_bg(int x, int y, double pct);
void clear_bg(int x, int y, double pct);
#define POINT struct xy
struct xy {
	int x;
	int y;
} ;
void docircle(POINT ctr, int rad, int r, int g, int b);
void dorectangle(POINT ul, POINT lr, int r, int g, int b);
void dotriangle(POINT p1, POINT p2, POINT p3, int r, int g, int b);
void set_scale_trans(int x, int y, double pct);
