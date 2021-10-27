#include "Point.h"


int main(int argc, char** argv) {
	
	Point p1(5,3);
    Point p2(10,7);
	Point p3 = p1-p2;
	
	p3.ShowPoint();
	
	return 0;
}
