#include "Point.h"


int main(int argc, char** argv) {
	
	Point p1(1,3);
	
	Point p2 = -p1;
	
	p1.ShowPoint();
	p2.ShowPoint();
	
	return 0;
}
