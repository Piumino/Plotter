#include <math.h>

#define DIM_H 700
#define DIM_W 700
#define SCALE 70
#define STEP 0.001

typedef struct Point{

	long double x;
	long double y;

}point;



long double fun(long double x){


	return pow(x, 2);
}


long double getX(point *centre, point* p){
	return centre->x + SCALE*p->x;
}

long double getY(point* centre, point* p){
	return centre->y - SCALE*fun(p->x);
}

//useless
long double getNextX(point *centre, point* p){
	return centre->x + SCALE*(p->x + 1.0);
}

//useless
long double getNextY(point* centre, point* p){
	return centre->y - SCALE*fun(p->x + 1.0);
}