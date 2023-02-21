#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect a, Rect b){
	double wf,hf;
	if(a.x <= b.x && a.x+a.w <= b.x+b.w)wf = (a.x+a.w) - b.x;
	if(a.x <= b.x && a.x+a.w >= b.x+b.w)wf = b.w;
	if(a.x >= b.x && a.x+a.w >= b.x+b.w)wf = (b.x+b.w)-a.x;
	if(a.x >= b.x && a.x+a.w <= b.x+b.w)wf = a.w;
	if(a.y <= b.y && a.y-a.h <= b.y-b.h)hf = a.y-(b.y-b.h);
	if(a.y <= b.y && a.y-a.h >= b.y-b.h)hf = a.h;
	if(a.y >= b.y && a.y-a.h >= b.y-b.h)hf = b.y-(a.y-a.h);
	if(a.y >= b.y && a.y-a.h <= b.y-b.h)hf = b.h;
	if(wf > 0 && hf > 0) return wf*hf;
	else return 0;
}
